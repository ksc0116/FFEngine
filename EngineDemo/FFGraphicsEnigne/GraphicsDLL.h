#pragma once

#ifdef CREATEDLL_EXPORTS
#define GRAPHICSDLL_MAIN extern "C" __declspec(dllexport)
#else
#define GRAPHICSDLL_MAIN __declspec(dllimport)
#endif

#include "IGraphics.h"

class FFGraphicsEngine;

namespace FFGraphics
{
	GRAPHICSDLL_MAIN IGraphics* GetFFGraphics();
	FFGraphicsEngine* CreateFFGraphics();
}

