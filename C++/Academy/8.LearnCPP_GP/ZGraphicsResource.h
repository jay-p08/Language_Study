#pragma once
//#include "ZGraphics.h"

class ZGraphics;
class DxgiInfoManager;

class ZGraphicsResource
{
protected:
	static ID3D11DeviceContext* GetContext(ZGraphics& gfx) noexcept;
	static ID3D11Device* GetDevice(ZGraphics& gfx) noexcept;
	static DxgiInfoManager& GetInfoManager(ZGraphics& gfx);
};