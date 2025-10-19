#pragma once

#include "ZBindable.h"

namespace Bind
{
    class ZIndexBuffer : public ZBindable
    {
        protected :
            UINT count;
            Microsoft::WRL::ComPtr<ID3D11Buffer> pIndexBuffer;

        public :
            template<typename I>
            ZIndexBuffer( ZGraphics& gfx, const std::vector<unsigned short>& indices )
            : count( ( UINT )indices.size() );
            void Bind( ZGraphics& gfx ) noexcept;
            UINT GetCount() const noexcept;
    };
}