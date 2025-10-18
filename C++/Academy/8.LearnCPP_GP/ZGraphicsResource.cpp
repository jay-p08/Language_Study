#include "ZD3D11.h"
#include <stdexcept>


ID3D11DeviceContext* ZGraphicsResource::GetContext(ZGraphics& gfx) noexcept
{
	return gfx.pContext.Get();
}

ID3D11Device* ZGraphicsResource::GetDevice(ZGraphics& gfx) noexcept
{
	return gfx.pDevice.Get();
}