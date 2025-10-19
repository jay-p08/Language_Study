#include "ZD3D11.h"
#include "ZTransformVSConstBuffer.h"

namespace Bind
{
    ZTransformVSConstBuffer::ZTransformVSConstBuffer( ZGraphics& gfx, const ZRenderable& parent )
    : parent( parent )
    {
        if( !pVcbuf ) // 한번만 생성한다
        {
            pVcbuf = std::make_unique<Bind::VSCpmstBuffer<DirectX::XMMATRIX>>( gfx );
        }
        
    }

    void ZTransformVSConstBuffer::Bind( ZGraphics& gfx ) noexcept
    {
        pVcbuf -> Update( gfx,
            // 전치행렬 사용 이유 : D3D( 행벡터 * 행렬 ) --> Shader( 행렬 * 열벡터 ) 전치행렬 관계
            DirectX::XMMatrixTranspose( 
                parent.GetTransfromXM() * gfx.GetProjection()
            )
        );
        pVcbuf -> Bind( gfx );
    }

    std::unique_ptr<Bind::VSCpmstBuffer<DirectX::XMMATRIX>> ZTransformVSConstBuffer::pVcbuf;
}