#pragma once

#ifdef CREATEDLL_EXPORTS
#define DLL_MAIN extern "C" __declspec(dllexport)
#else
#define DLL_MAIN __declspec(dllimport)
#endif

namespace FFEngine
{
	DLL_MAIN void Run();
	DLL_MAIN void EngineInit();
}

