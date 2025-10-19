#pragma once
#include "ZGraphicsResource.h"

class ZGraphics;

namespace Bind
{
    class ZBindable : public ZGraphicsResource
    {
    public:
        virtual void Bind(ZGraphics& gfx) noexcept = 0;
        virtual ~ZBindable() = default;
    };
}