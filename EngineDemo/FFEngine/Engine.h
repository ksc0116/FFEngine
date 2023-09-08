#pragma once
#include "Utils.h"
#include "Core.h"
#include "WindowSystem.h"
#include <memory>

namespace FFEngine
{
	class Engine : public FFEngine::Singleton<Engine>
	{
	public:
		void Init();
		void Run();

	private:
		std::unique_ptr<Core> core;
		std::unique_ptr<WindowSystem> windowSystem;
	};
}


