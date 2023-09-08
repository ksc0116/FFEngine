#include "Core.h"

namespace FFEngine
{
	void Core::Run()
	{
		MSG msg;

		// �⺻ �޽��� �����Դϴ�:
		while (true)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					break;
				}

				if (!TranslateAccelerator(msg.hwnd, m_windowSystem->GetHACCEL(), &msg))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		}
	}
}

