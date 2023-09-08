#include "Engine.h"

namespace FFEngine
{
	void Engine::Init()
	{
		core = std::make_unique<Core>();
		core->Init();
	}

	void Engine::Run()
	{
		core->Run();
	}
}
