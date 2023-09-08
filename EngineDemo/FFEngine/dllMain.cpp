#include "dllMain.h"
#include <iostream>

#include "Engine.h"

namespace FFEngine
{
	DLL_MAIN void Run()
	{
		
	}

	DLL_MAIN void EngineInit()
	{
		FFEngine::Engine::GetInstance().Init();
	}
}

