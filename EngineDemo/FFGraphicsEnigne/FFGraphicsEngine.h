#pragma once

#include "IGraphics.h"

class FFGraphicsEngine : public IGraphics
{
public:
	virtual void Init(long long hWnd, float width, float height, bool isWindowed) override;
	virtual void RenderBegin() override;

};


