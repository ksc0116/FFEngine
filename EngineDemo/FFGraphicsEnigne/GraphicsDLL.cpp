#include "GraphicsDLL.h"

#include "FFGraphicsEngine.h"

namespace FFGraphics
{
	GRAPHICSDLL_MAIN IGraphics* GetFFGraphics()
	{
		return FFGraphics::CreateFFGraphics();
	}

	FFGraphicsEngine* CreateFFGraphics()
	{
		return new FFGraphicsEngine();
	}
}

