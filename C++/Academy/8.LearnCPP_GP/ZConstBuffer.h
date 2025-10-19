#pragma once

#include "ZBindable.h"
#include "GraphicsThrowMacros.h"

namespace Bind
{
    template<typename C>
    class ZConstBuffer : public ZBindable
    {
        protected :
            Microsoft::WRL::ComPtr<ID3D11Buffer> pConstBuffer;
            UINT slot;

        public :
            void Update( ZGraphics& gfx, const C& consts )
            {
                INFOMAN( gfx );
                D3D11_MAPPED_SUBRESOURCE msr;
                GFX_THROW_INFO( GetContext( gfx ) -> Map(
                                pConstantBuffer.Get(), 0u,
                                D3D11_MAP_WRITE_DISCARD, 0u, 
                                &msr ) );
                memcpy( msr.pData, &consts, sizeof( C ) );
                GetContext( gfx ) -> Unmap( pConstantBuffer.Get(), 0u );
            }

            ZConstBuffer( ZGraphics& gfx, const C& consts, UINT slot = 0u ) : slot( slot )
            {
                INFOMAN( gfx );

                D3D11_BUFFER_DESC cbd = {};
                cbd.BindFlags = D3D11_BIND_CONST_BUFFER;
                cbd.Usage = D3D11_USAGE_DYNAMIC;
                cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
                cbd.MiscFlags = 0u;
                cbd.ByteWidth = sizeof( consts );
                cbd.StructureByteStride = 0u;

                D3D11_SUBRESOURCE_DATA csd = {};
                csd.pSysMem = &consts;

                GFX_THROW_INFO( GetDevice( gfx ) -> CreateBuffer( &cbd, &csd, &pConstBuffer ) );
            }
    };

    template<typename C>
    class VSCpmstBuffer : public ZConstBuffer<C>
    {
        // template inheritance
        using ZConstBuffer<C>::ZConstBuffer;
        using ZConstBuffer<C>::slot;
        using ZBindable::GetContext;

        public :
            using ZConstBuffer<C>::ZConstBuffer;
            void Bind( ZGraphics& gfx ) noexcept override
            {
                GetContext( gfx ) -> VSSetConstantBuffers( slot, 1u, pConstantBuffer.GetAddressOf() );
            }
    };

    template<typename C>
    class PSCpmstBuffer : public ZConstBuffer<C>
    {
        // template inheritance
        using ZConstBuffer<C>::ZConstBuffer;
        using ZConstBuffer<C>::slot;
        using ZBindable::GetContext;

        public :
            using ZConstBuffer<C>::ZConstBuffer;
            void Bind( ZGraphics& gfx ) noexcept override
            {
                GetContext( gfx ) -> PSSetConstantBuffers( slot, 1u, pConstantBuffer.GetAddressOf() );
            }
    };


} // namespace Bind
