#include "Core.h"
#include "Resource.h"
#include "IGraphics.h"

namespace FFEngine
{

	Core::Core()
		: m_hWnd{0},
		m_width{0.f},
		m_height{0.f},
		m_isWindowed{true},
		m_hInstance{},
		m_hAccelTable{},
		graphics{nullptr}
	{

	}

	Core::~Core()
	{

	}

	HWND Core::GetHWND()
	{
		return m_hWnd;
	}

	float Core::GetWidth()
	{
		return m_width;
	}

	float Core::GetHeight()
	{
		return m_height;
	}

	bool Core::GetWindowed()
	{
		return m_isWindowed;
	}

	void Core::Init(IGraphics* graphics)
	{
		this->graphics = graphics;

		m_width = 1920;
		m_height = 1080;

		m_hInstance = GetModuleHandle(NULL);

		WNDCLASSEXW wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_FFENGINE));
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_FFENGINE);
		wcex.lpszClassName = L"EngineTest";
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

		RegisterClassExW(&wcex);

		m_hWnd = CreateWindowW(L"EngineTest", L"EngineTest", WS_OVERLAPPEDWINDOW,
			100, 100, m_width, m_height, nullptr, nullptr, m_hInstance, nullptr);

		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);

		m_hAccelTable = LoadAccelerators(m_hInstance, MAKEINTRESOURCE(IDC_FFENGINE));
	}

	void Core::Run()
	{
		MSG msg;

		// 기본 메시지 루프입니다:
		while (true)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					break;
				}

				if (!TranslateAccelerator(msg.hwnd, m_hAccelTable, &msg))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}

			Progress();
		}
	}

	void Core::Progress()
	{
		// Update

		// Render
		graphics->RenderBegin();

	}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_COMMAND:
			{
				int wmId = LOWORD(wParam);
				// 메뉴 선택을 구문 분석합니다:
				switch (wmId)
				{
					case IDM_ABOUT:
						//DialogBox(m_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
						break;
					case IDM_EXIT:
						DestroyWindow(hWnd);
						break;
					default:
						return DefWindowProc(hWnd, message, wParam, lParam);
				}
			}
			break;
			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
				EndPaint(hWnd, &ps);
			}
			break;
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			case WM_SIZE:
			{
				//Core::GetInstance().GetGameEngine()->OnResize();
			}
			break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}
}

