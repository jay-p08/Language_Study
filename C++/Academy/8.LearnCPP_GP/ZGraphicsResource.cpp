#include "ZD3D11.h"
#include "ZGraphicsResource.h"
#include <stdexcept>


ID3D11DeviceContext* ZGraphicsResource::GetContext(ZGraphics& gfx) noexcept
{
	return gfx.pContext.Get();
}

ID3D11Device* ZGraphicsResource::GetDevice(ZGraphics& gfx) noexcept
{
	return gfx.pDevice.Get();
}

DxgiInfoManager& ZGraphicsResource::GetInfoManager( ZGraphics& gfx )
{
	#ifndef NDEBUG
		return gfx.infoManager;
	#else
		throw std::logic_error( "Error! ( tried to access gfx.infoManager in Release config )" );
	#endif
}