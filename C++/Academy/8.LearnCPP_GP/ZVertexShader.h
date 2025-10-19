#pragma once

#include "ZBindable.h"

namespace Bind
{
    class ZVertexShader : public ZBindable
    {
        protected :
            Microsoft::WRL::ComPtr<ID3DBlob> pBytecodeBlob;
            Microsoft::WRL::ComPtr<ID3D11VertexShader> pVertexShader;

        public :
            ZVertexShader( ZGraphics& gfx, const std::wstring& path ); 
            void Bind( ZGraphics& gfx ) noexcept override;
            ID3DBlob* GetBytecode() const noexcept;

    };
}