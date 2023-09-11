#include <Windows.h>
#include "dllMain.h"

#define DLL_ENGINE_PATH "..//Output//Lib//Engine//FFEngine.dll"
using DLL_RUN = void (*)();
using DLL_INIT = void (*)();

int main()
{
	HMODULE hDll = ::LoadLibraryA(DLL_ENGINE_PATH);
	DLL_RUN pRun = nullptr;
	DLL_INIT pInit = nullptr;

	if (hDll)
	{
		pInit = (DLL_INIT)::GetProcAddress(hDll, "EngineInit");
		pInit();

		// TODO







		pRun = (DLL_RUN)::GetProcAddress(hDll, "Run");
		pRun();
	}

	return 0;
}