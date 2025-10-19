#pragma once

#include "ZConstBuffer.h"
#include "ZRenderable.h"
#include <DirectXMath.h>

namespace Bind
{
    class ZTransformVSConstBuffer : public ZBindable
    {
        private :
            // VSConstBuffer는 매프래임마다 다시 계산하기 때문에 재활용한다.
            static std::unique_ptr<Bind::VSCpmstBuffer<DirectX::XMMATRIX>> pVcbuf;
            const ZRenderable& parent;

        public :
            ZTransformVSConstBuffer( ZGraphics& gfx, const ZRenderable& parent );
            void Bind( ZGraphics& gfx ) noexcept override;
    };
}