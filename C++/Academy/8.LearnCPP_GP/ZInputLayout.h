#pragma once
#include "ZBindable.h"

namespace Bind
{
    class ZInputLayout : public ZBindable
    {
    protected:
        Microsoft::WRL::ComPtr<ID3D11InputLayout> pInputLayout;

    public:
        ZInputLayout(ZGraphics& gfx,
            const std::vector<D3D11_INPUT_ELEMENT_DESC>& layout,
            ID3DBlob* pVertexShaderBytecode);
        void Bind(ZGraphics& gfx) noexcept override;
    };
}