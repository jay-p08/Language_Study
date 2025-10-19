#include "ZD3D11.h"
#include "SampleBox.h"
#include "ZBindableBase.h"
#include "GraphicsThrowMacros.h"


SampleBox::SampleBox(ZGraphics& gfx, 
    std::mt19937& rng, 
    std::uniform_real_distribution<float>& adist, 
    std::uniform_real_distribution<float>& ddist,   // delta
    std::uniform_real_distribution<float>& odist,   // 
    std::uniform_real_distribution<float>& rdist)   // radius
    :
    r(rdist(rng)),
    droll(ddist(rng)),
    dpitch(ddist(rng)),
    dyaw(ddist(rng)),
    dphi(odist(rng)),
    dtheta(odist(rng)),
    dchi(odist(rng)),
    chi(adist(rng)),
    theta(adist(rng)),
    phi(adist(rng))
{
    if (!IsStaticInitialized())
    {
        struct Vertex
        {
            struct
            {
                float x;
                float y;
                float z;
            } pos;
        };
        const std::vector<Vertex> vertices =
        {
            { -1.0f,-1.0f,-1.0f },
            { 1.0f,-1.0f,-1.0f },
            { -1.0f,1.0f,-1.0f },
            { 1.0f,1.0f,-1.0f },
            { -1.0f,-1.0f,1.0f },
            { 1.0f,-1.0f,1.0f },
            { -1.0f,1.0f,1.0f },
            { 1.0f,1.0f,1.0f },
        };
        AddStaticBind(std::make_unique<Bind::ZVertexBuffer>(gfx, vertices));

        auto pvs = std::make_unique<Bind::ZVertexShader>(gfx, L"./x64/Debug/VertexShaderCubeDepth.cso");
        auto pvsbc = pvs->GetBytecode();
        AddStaticBind(std::move(pvs));

        AddStaticBind(std::make_unique<Bind::ZPixelShader>(gfx, L"./x64/Debug/PixelShaderCubeDepth.cso"));

        const std::vector<unsigned short> indices =
        {
            0,2,1, 2,3,1,
            1,3,5, 3,7,5,
            2,6,3, 3,6,7,
            4,5,7, 4,7,6,
            0,4,2, 2,4,6,
            0,1,4, 1,5,4
        };
        AddStaticIndexBuffer(std::make_unique<Bind::ZIndexBuffer>(gfx, indices));

        struct ConstantBuffer2
        {
            struct
            {
                float r;
                float g;
                float b;
                float a;
            } face_colors[6];
        };
        const ConstantBuffer2 cb2 =
        {
            {
                { 1.0f,0.0f,1.0f },
                { 1.0f,0.0f,0.0f },
                { 0.0f,1.0f,0.0f },
                { 0.0f,0.0f,1.0f },
                { 1.0f,1.0f,0.0f },
                { 0.0f,1.0f,1.0f },
            }
        };
        AddStaticBind(std::make_unique<Bind::PSConstBuffer<ConstantBuffer2>>(gfx, cb2));

        const std::vector<D3D11_INPUT_ELEMENT_DESC> ied =
        {
            { "Position",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
        };
        AddStaticBind(std::make_unique<Bind::ZInputLayout>(gfx, ied, pvsbc));

        AddStaticBind(std::make_unique<Bind::ZTopology>(gfx, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST));
    }
    else
    {
        SetIndexFromStatic();
    }

    AddBind(std::make_unique<Bind::ZTransformVSConstBuffer>(gfx, this));
}

void SampleBox::Update(float dt) noexcept
{
    roll += droll dt;
    pitch += dpitch * dt;
    yaw += dyaw * dt;
    theta += dtheta * dt;
    phi += dphi * dt;
    chi += dchi * dt;
}

DirectX::XMMATRIX SampleBox::GetTransformXM() const noexcept
{
    return DirectX::XMMatrixRotationRollPitchYaw(pitch, yaw, roll) *
        DirectX::XMMatrixTranslation(r, 0.0f, 0.0f) *
        DirectX::XMMatrixRotationRollPitchYaw(theta, phi, chi) *
        DirectX::XMMatrixTranslation(0.0f, 0.0f, 20.0f);
}