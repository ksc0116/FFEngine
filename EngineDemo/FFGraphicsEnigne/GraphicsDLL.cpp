#include "GraphicsDLL.h"

#include "FFGraphicsEngine.h"

namespace FFGraphics
{

	GRAPHICSDLL_MAIN FFGraphicsEngine* GetFFGraphics()
	{
		return FFGraphics::CreateFFGraphics();
	}

	FFGraphicsEngine* CreateFFGraphics()
	{
		return new FFGraphicsEngine();
	}
}

