#include <iostream>

#include <SFML/Graphics.hpp>
#include <cassert>

#include "angelscript/angelscript.h"
#include "angelscript/scriptbuilder/scriptbuilder.h"
#include "angelscript/scriptstdstring/scriptstdstring.h"

#include "World.hxx"
#include "WorldRenderer.hxx"

void asMsgCallback(const asSMessageInfo *msg, void *param)
{
	const char *type = "[ERR] ";
	if(msg->type == asMSGTYPE_WARNING)
		type = "[WARN] ";
	else if(msg->type == asMSGTYPE_INFORMATION)
		type = "[INFO] ";

	std::cerr << type << msg->section << msg->row << msg->col << msg->message << std::endl;
}

void asPrint(std::string &str)
{
	std::cout << str;
}

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
	World world(8, 6, 0);
	WorldRenderer w_renderer(&world, &window);

	// Test a world.
	world.set_cell_state_at(0, 0, 1);
	world.set_cell_state_at(7, 5, 1);
	world.set_cell_state_at(4, 3, 1);
	world.set_cell_state_at(7, 0, 1);

	// Test AngelScript
	asIScriptEngine *engine = asCreateScriptEngine();
	int r = engine->SetMessageCallback(asFUNCTION(asMsgCallback), 0, asCALL_CDECL);
	assert(r >= 0);
	RegisterStdString(engine);
	r = engine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(asPrint), asCALL_CDECL);
	assert(r >= 0);

	CScriptBuilder builder;
	r = builder.StartNewModule(engine, "module1");
	if(r < 0)
	{
		std::cerr << "[ERR] Unrecoverable error while starting a new module." << std::endl;
		return -1;
	}
	r = builder.AddSectionFromFile("data/scripts/hello.as");
	if(r < 0)
	{
		std::cerr << "[ERR] There are error in hello.as" << std::endl;
		return -1;
	}
	r = builder.BuildModule();
	if(r < 0)
	{
		std::cerr << "[ERR] There are error in hello.as" << std::endl;
		return -1;
	}

	asIScriptModule *mod = engine->GetModule("module1");
	asIScriptFunction *fun = mod->GetFunctionByDecl("void main()");
	if(fun == 0)
	{
		std::cerr << "[ERR] no void main() in hello.as" << std::endl;
		return -1;
	}

	asIScriptContext *ctx = engine->CreateContext();
	ctx->Prepare(fun);
	r = ctx->Execute();
	if(r != asEXECUTION_FINISHED)
		if(r == asEXECUTION_EXCEPTION)
			std::cerr << "[ERR] An exception has occured while running hello.as" << std::endl;

	ctx->Release();
	engine->ShutDownAndRelease();

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color(255, 255, 255));

		w_renderer.render_world();

		window.display();
	}

	return 0;
}

