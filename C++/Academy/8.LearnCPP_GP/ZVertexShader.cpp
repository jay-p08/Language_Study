#include "ZD3D11.h"
#include "ZVertexShader.h"
#include "GraphicsThrowMacros.h"
#include <d3dcompiler.h>

namespace Bind
{
    ZVertexShader::ZVertexShader( ZGraphics& gfx, const std::wstring& path )
    {
        INFOMAN( gfx );

        GFX_THROW_INFO( D3DReadFileToBlob( path.c_str(), &pBytecodeBlob ) );
        GFX_THROW_INFO( GetDevice( gfx ) -> CreateVertexShader( 
            pBytecodeBlob -> GetBufferPointer(),
            pBytecodeBlob -> GetBufferSize(),
            nullptr, &pVertexShader ) );
        
        
    }

    void ZVertexShader::Bind( ZGraphics& gfx ) noexcept
    {
        GetContext( gfx ) -> VSSetShader( pVertexShader.Get(), nullptr, 0u );
    }

    ID3DBlob* ZVertexShader::GetBytecode() const noexcept
    {
        return pBytecodeBlob.Get();
    }
}