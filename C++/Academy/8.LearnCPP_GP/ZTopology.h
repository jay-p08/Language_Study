#pragma once

#include "ZBindable.h"

namespace Bind
{
    class ZTopology : public ZBindable
    {
    protected:
        D3D11_PRIMITIVE_TOPOLOGY type;

    public:
        ZTopology( ZGraphics& gfx, D3D11_PRIMITIVE_TOPOLOGY type );
        void Bind( ZGraphics& gfx ) noexcept override;
    };
}