#pragma once
#include <Windows.h>

class IGraphics;


namespace FFEngine
{
	class Core
	{
	public:
		Core();
		~Core();

	public:
		HWND GetHWND();
		float GetWidth();
		float GetHeight();
		bool GetWindowed();

	public:
		void Init(IGraphics* graphics);
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

	private:
		// 참조 관련 변수
		IGraphics* graphics;

	};

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
}


