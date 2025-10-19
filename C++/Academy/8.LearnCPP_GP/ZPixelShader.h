#pragma once

#include "ZBindable.h"

namespace Bind
{
    class ZPixelShader : public ZBindable
    {
        protected :
            Microsoft::WRL::ComPtr<ID3D11PixelShader> pPixelShader;

        public :
            ZPixelShader( ZGraphics& gfx, const std::wstring& path );
            void Bind( ZGraphics& gfx ) noexcept override;
    };
}