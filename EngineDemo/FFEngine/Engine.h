#pragma once
#include "Utils.h"
#include "Core.h"
#include <memory>

class IGraphics;

namespace FFEngine
{
	class Engine : public FFEngine::Singleton<Engine>
	{
	public:
		void Init();
		void Run();

	private:
		std::unique_ptr<Core> core;
		IGraphics* graphics;
	};
}


