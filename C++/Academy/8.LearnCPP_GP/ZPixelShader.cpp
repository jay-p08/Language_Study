#include "ZD3D11.h"
#include "ZPixelShader.h"
#include "GraphicsThrowMacros.h"
#include <d3dcompiler.h>

namespace Bind
{
    ZPixelShader::ZPixelShader( ZGraphics& gfx, const std::wstring& path )
    {
        INFOMAN( gfx );

        Microsoft::WRL::ComPtr<ID3DBlob> pBlob;
        GFX_THROW_INFO( D3DReadFileToBlob( path.c_str(), &pBlob ) );
        GFX_THROW_INFO( GetDevice( gfx ) -> CreatePixelShader( 
            pBlob -> GetBufferPointer(), 
            pBlob -> GetBufferSize(), 
            nullptr, &pPixelShader ) );
    }

    void ZPixelShader::Bind( ZGraphics& gfx ) noexcept
    {
        GetContext( gfx ) -> PSSetShader( pPixelShader.Get(), nullptr, 0u );
    }
}