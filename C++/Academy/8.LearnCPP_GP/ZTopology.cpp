#include "ZD3D11.h"
#include "ZTopology.h"

namespace Bind
{
    ZTopology::ZTopology(ZGraphics& gfx, D3D11_PRIMITIVE_TOPOLOGY type)
        :
        type(type)
    {
    }

    void ZTopology::Bind(ZGraphics& gfx) noexcept
    {
        GetContext(gfx)->IASetPrimitiveTopology(type);
    }
}