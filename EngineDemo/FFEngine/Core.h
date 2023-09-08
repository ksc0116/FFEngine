#pragma once
#include <Windows.h>

namespace FFEngine
{
	class Core
	{
	public:
		Core();
		~Core();
		void Init();
		void Run();
		void Progress();


	private:
		// 윈도우 관련 변수들
		HWND m_hWnd;
		float m_width;
		float m_height;
		bool m_isWindowed;
		HINSTANCE m_hInstance;
		HACCEL m_hAccelTable;

	};

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
}


