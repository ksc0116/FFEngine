#include "dllMain.h"
#include <iostream>

#include "Engine.h"

namespace FFEngine
{
	DLL_MAIN void Run()
	{
		FFEngine::Engine::GetInstance().Run();
	}

	DLL_MAIN void EngineInit()
	{
		FFEngine::Engine::GetInstance().Init();
	}
}

