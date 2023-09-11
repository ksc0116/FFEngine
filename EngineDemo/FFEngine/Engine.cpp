#include "Engine.h"

#include "GraphicsDLLDefine.h"

namespace FFEngine
{
	void Engine::Init()
	{
		CreateGraphicsFunc();

		graphics = GetGraphics();

		core = std::make_unique<Core>();
		core->Init(graphics);
		
		graphics->Init(
			reinterpret_cast<long long>(core->GetHWND()),
			core->GetWidth(),
			core->GetHeight(),
			core->GetWindowed()
		);
	}

	void Engine::Run()
	{
		core->Run();
	}
}
