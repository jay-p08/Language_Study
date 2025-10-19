#include "ZD3D11.h"
#include "ZInputLayout.h"
#include "GraphicsThrowMacros.h"

namespace Bind
{
    ZInputLayout::ZInputLayout(ZGraphics& gfx,
        const std::vector<D3D11_INPUT_ELEMENT_DESC>& layout,
        ID3DBlob* pVertexShaderBytecode)
    {
        INFOMAN(gfx);

        GFX_THROW_INFO(GetDevice(gfx)->CreateInputLayout(
            layout.data(), (UINT)layout.size(),
            pVertexShaderBytecode->GetBufferPointer(),
            pVertexShaderBytecode->GetBufferSize(),
            &pInputLayout
        ));
    }

    void ZInputLayout::Bind(ZGraphics& gfx) noexcept
    {
        GetContext(gfx)->IASetInputLayout(pInputLayout.Get());
    }
}