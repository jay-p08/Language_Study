#include "ZD3D11.h"
#include <sstream>
#include "GraphicsThrowMacros.h"
#include <d3dcompiler.h>
#include <DirectXMath.h> // dx math

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib") // Shader Compiler

namespace wrl = Microsoft::WRL;
namespace dx = DirectX;

ZGraphics::ZGraphics(HWND hWnd, float winRatio, DWORD width, DWORD height)
{
    this->winRatio = winRatio;
    this->m_ClientWidth = width;
    this->m_ClientHeight = height;

	// 스왑 체인을 설정하기 위한 구조체입니다.
	DXGI_SWAP_CHAIN_DESC sd = {};
	// 후면 버퍼의 너비와 높이를 설정합니다. 0으로 설정하면 윈도우 크기에 맞춰 자동으로 조절됩니다.
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	// 후면 버퍼의 픽셀 포맷을 설정합니다. (B8G8R8A8_UNORM: 32비트, 채널당 8비트, BGRA 순서)
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	// 화면 주사율(Refresh Rate)을 설정합니다. 0으로 설정하면 시스템 기본값을 사용합니다.
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	// 디스플레이 스케일링 모드를 설정합니다.
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	// 스캔 라인 렌더링 순서를 설정합니다.
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	// 멀티샘플링(MSAA) 설정을 합니다. Count=1, Quality=0은 멀티샘플링을 사용하지 않음을 의미합니다.
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	// 후면 버퍼의 사용 용도를 설정합니다. 렌더 타겟으로 사용됩니다.
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	// 후면 버퍼의 개수를 설정합니다. 일반적으로 1개(더블 버퍼링) 또는 2개(트리플 버퍼링)를 사용합니다.
	sd.BufferCount = 1;
	// 렌더링 결과를 출력할 윈도우의 핸들입니다.
	sd.OutputWindow = hWnd;
	// 창 모드(TRUE) 또는 전체 화면 모드(FALSE)를 설정합니다.
	sd.Windowed = TRUE;
	// 후면 버퍼를 화면에 표시한 후의 처리 방식을 설정합니다. (DISCARD: 내용을 버림)
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	// 추가적인 플래그를 설정합니다.
	sd.Flags = 0;

	D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	D3D_FEATURE_LEVEL featureLevel;

	UINT creationFlags = 0;
#if defined(_DEBUG)
	// 디버그 빌드에서는 D3D11 디버그 레이어를 활성화합니다.
	// 이를 통해 API 사용 오류, 메모리 누수 등 다양한 디버깅 정보를 얻을 수 있습니다.
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// D3D11 장치(Device), 장치 컨텍스트(Context), 스왑 체인(Swap Chain)을 생성합니다.
	HRESULT hr;

	GFX_THROW_INFO( D3D11CreateDeviceAndSwapChain(
		nullptr,						// pAdapter: 기본 어댑터(그래픽 카드)를 사용합니다.
		D3D_DRIVER_TYPE_HARDWARE,		// DriverType: 하드웨어 가속을 사용합니다.
		nullptr,						// Software: 하드웨어 드라이버를 사용하므로 NULL입니다.
		creationFlags,					// Flags: 추가적인 생성 플래그 (예: 디버그 모드)
		featureLevels,				// pFeatureLevels: 지원할 기능 수준 배열입니다.
		numFeatureLevels,				// FeatureLevels: 기능 수준 배열의 크기입니다.
		D3D11_SDK_VERSION,			// SDKVersion: 항상 D3D11_SDK_VERSION으로 설정합니다.
		&sd,						// pSwapChainDesc: 위에서 설정한 스왑 체인 설정 구조체입니다.
		&pSwap,						// ppSwapChain: 생성된 스왑 체인 인터페이스를 받을 포인터입니다.
		&pDevice,					// ppDevice: 생성된 장치 인터페이스를 받을 포인터입니다.
		&featureLevel,				// pFeatureLevel: 실제로 선택된 기능 수준을 받을 포인터입니다.
		&pContext					// ppImmediateContext: 생성된 장치 컨텍스트를 받을 포인터입니다.
	) );

	if (SUCCEEDED(hr))
	{
		switch (featureLevel)
		{
			case D3D_FEATURE_LEVEL_11_1:
				std::cout << "D3D Feature Level: 11.1" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_11_0:
				std::cout << "D3D Feature Level: 11.0" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_10_1:
				std::cout << "D3D Feature Level: 10.1" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_10_0:
				std::cout << "D3D Feature Level: 10.0" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_9_3:
				std::cout << "D3D Feature Level: 9.3" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_9_2:
				std::cout << "D3D Feature Level: 9.2" << std::endl;
				break;
			case D3D_FEATURE_LEVEL_9_1:
				std::cout << "D3D Feature Level: 9.1" << std::endl;
				break;
			default:
				std::cout << "D3D Feature Level: Unknown or lower than 9.1" << std::endl;
				break;
		}
	}

	// [주요 개념: GetBuffer와 스왑 체인]
	// 스왑 체인으로부터 후면 버퍼(Back Buffer)에 접근하기 위한 리소스를 가져옵니다.
	// - 첫 번째 인자 '0': 스왑 체인의 첫 번째 버퍼, 즉 '후면 버퍼'를 의미합니다. 모든 렌더링은 이 버퍼에 이루어집니다.
	// - 전면 버퍼(Front Buffer): 현재 화면에 표시되는 버퍼로, GetBuffer()를 통해 직접 접근할 수 없습니다.
	// - Present() 호출: 후면 버퍼의 내용을 전면 버퍼로 보내 화면에 표시하는 역할을 합니다. (실제로는 포인터 교체(Flip) 방식이 주로 사용됨)
	// - 트리플 버퍼링: BufferCount를 2 이상으로 설정하면, 인덱스 1은 '두 번째 후면 버퍼'를 의미합니다. 이는 V-Sync 시 GPU의 대기 시간을 줄여 성능 저하를 완화하는 데 사용됩니다.
	wrl::ComPtr<ID3D11Resource> pBackBuffer;
	GFX_THROW_INFO(pSwap->GetBuffer(0, __uuidof(ID3D11Resource), &pBackBuffer));

	// 후면 버퍼에 대한 RTV(Render Target View)를 생성합니다.
	// 렌더링 파이프라인의 최종 출력은 이 렌더 타겟 뷰에 쓰여집니다.
	GFX_THROW_INFO(pDevice->CreateRenderTargetView(
		pBackBuffer.Get(),		// pResource: 렌더 타겟으로 사용할 리소스 (후면 버퍼)
		nullptr,			// pDesc: 렌더 타겟 뷰 설정, NULL이면 리소스의 기본 설정을 따릅니다.
		&pTarget			// ppRTView: 생성된 렌더 타겟 뷰를 받을 포인터입니다.
	));


    // depth 버퍼 초기화 할 때 사용한다.
    // create depth stensil state
    D3D11_DEPTH_STENCIL_DESC dsDesc = {};
    dsDesc.DepthEnable = TRUE;
    dsDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    dsDesc.DepthFunc = D3D11_COMPARISON_LESS; // z축으로 가까운 것이 다른 것을 오버라이드한다.
    wrl::ComPtr<ID3D11DepthStencilState> pDSState;
    GFX_THROW_INFO(pDevice->CreateDepthStencilState(&dsDesc, &pDSState));

    // bind depth state
    pContext->OMSetDepthStencilState(pDSState.Get(), 1u);

    // create depth stensil texture
    wrl::ComPtr<ID3D11Texture2D> pDepthStencil;
    D3D11_TEXTURE2D_DESC descDepth = {};
    descDepth.Width = (UINT)m_ClientWidth;
    descDepth.Height = (UINT)m_ClientHeight;
    descDepth.MipLevels = 1u;
    descDepth.ArraySize = 1u;
    descDepth.Format = DXGI_FORMAT_D32_FLOAT;
    descDepth.SampleDesc.Count = 1u;
    descDepth.SampleDesc.Quality = 0u;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    GFX_THROW_INFO(pDevice->CreateTexture2D(&descDepth, nullptr, &pDepthStencil));

    // create view of depth stensil texture
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV = {};
    descDSV.Format = DXGI_FORMAT_D32_FLOAT;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0u;
    GFX_THROW_INFO(pDevice->CreateDepthStencilView(pDepthStencil.Get(), &descDSV, &pDSV));

    // bind depth stensil view to OM
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), pDSV.Get());
}

void ZGraphics::EndFrame()
{
	HRESULT hr;

#ifndef NDEBUG
	infoManager.Set();
#endif

	// 후면 버퍼의 내용을 화면에 표시(Present)합니다.
	// 첫 번째 인자(SyncInterval): 수직 동기화 옵션. 1은 수직 동기화를 켭니다.
	// 두 번째 인자(Flags): 추가적인 프레젠테이션 옵션.
	if (FAILED(hr = pSwap->Present(1u, 0u)))
	{
		if (hr == DXGI_ERROR_DEVICE_REMOVED)
		{
			throw GFX_DEVICE_REMOVED_EXCEPT(pDevice->GetDeviceRemovedReason());
		}
		else
		{
			throw GFX_EXCEPT(hr);
		}
	}
}

void ZGraphics::ClearBuffer(float red, float green, float blue) noexcept
{
	// 렌더 타겟 뷰를 지정된 색상으로 초기화합니다.
	const float color[] = { red, green, blue, 1.0f }; // RGBA 순서
	pContext->ClearRenderTargetView(pTarget.Get(), color);
    pContext->ClearDepthStencilView(pDSV.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0u);
}

void ZGraphics::DrawTestTriangle()
{
	HRESULT hr;

	struct Vertex
	{
        struct
        {
		    float x;
		    float y;
        } pos;
        //struct
        //{
        //    //float r;
        //    //float g;
        //    //float b;
        //    uint8_t r;
        //    uint8_t g;
        //    uint8_t b;
        //    uint8_t a;
        //} color;
	};

    // NDC
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1)
	// create vertex buffer (1 2d triangle at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
	Vertex vertices[] =
	{
		//{ 0.0f, 0.5f, 255, 0, 0, 0 },
		//{ 0.5f, -0.5f, 0, 255, 0, 0 },
		//{ -0.5f, -0.5f, 0, 0, 255, 0 },

        // 2d float3
        //{ 0.0f, 0.5f, 1.0f, 0.0f, 0.0f },
        //{ 0.5f, -0.5f, 0.0f, 1.0f, 0.0f },
        //{ -0.5f, -0.5f, 0.0f, 0.0f, 1.0f },

        // 2d
        { 0.0f, 0.5f },
        { 0.5f, -0.5f },
        { -0.5f, -0.5f },
	};

    //Vertex vertices[] =
    //{
    //    { 0.0f, 0.5f, 255, 0, 0, 0 },
    //    { 0.5f, -0.5f, 0, 255, 0, 0 },
    //    { -0.5f, -0.5f, 0, 0, 255, 0 },

    //    { 0.0f, 0.5f, 255, 0, 0, 0 },
    //    { -0.5f, -0.5f, 0, 0, 255, 0 },
    //    { -0.3f, 0.3f, 0, 255, 0, 0 },

    //    { 0.0f, 0.5f, 255, 0, 0, 0 },
    //    { 0.3f, 0.3f, 0, 0, 255, 0 },
    //    { 0.5f, -0.5f, 0, 255, 0, 0 },

    //    { 0.0f, -0.8f, 255, 0, 0, 0 },
    //    { -0.5f, -0.5f, 0, 0, 255, 0 },
    //    { 0.5f, -0.5f, 0, 255, 0, 0 },
    //};

    //vertices[0].color.g = 255;

	wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
	D3D11_BUFFER_DESC bd = {};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(vertices);
	bd.StructureByteStride = sizeof(Vertex);

	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = vertices;
	GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

	// Bind vertex buffer to pipeline
	const UINT stride = sizeof(Vertex);
	const UINT offset = 0u;
	pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);

    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)m_ClientWidth;
    vp.Height = (float)m_ClientHeight;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    pContext->RSSetViewports(1u, &vp);

	GFX_THROW_INFO_ONLY(pContext->Draw((UINT)std::size(vertices), 0u));
}

void ZGraphics::DrawIndexedTriangle()
{
    HRESULT hr;

    struct Vertex
    {
        struct
        {
            float x;
            float y;
        } pos;
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        } color;
    };

    // NDC
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1)
    // create vertex buffer (1 2d triangle at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
    Vertex vertices[] =
    {
        { 0.0f, 0.5f, 255, 0, 0, 0 },
        { 0.5f, -0.5f, 0, 255, 0, 0 },
        { -0.5f, -0.5f, 0, 0, 255, 0 },
        { -0.3f, 0.3f, 0, 255, 0, 0 },
        { 0.3f, 0.3f, 0, 0, 255, 0 },
        { 0.0f, -0.8f, 255, 0, 0, 0 },
    };

    wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeof(vertices);
    bd.StructureByteStride = sizeof(Vertex);

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = vertices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

    // Bind vertex buffer to pipeline
    const UINT stride = sizeof(Vertex);
    const UINT offset = 0u;
    pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);


    // create index buffer
    const uint16_t indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 4, 1,
        2, 1, 5,
    };

    wrl::ComPtr<ID3D11Buffer> pIndexBuffer;
    D3D11_BUFFER_DESC ibd = {};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags = 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = sizeof(indices);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd = {};
    isd.pSysMem = indices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&ibd, &isd, &pIndexBuffer));

    // bind index buffer
    pContext->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);


    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "Color", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    //vp.Width = 800 / 2;
    //vp.Height = 600 / 2;
    vp.Width = (float)m_ClientWidth / 2.0f;
    vp.Height = (float)m_ClientHeight / 2.0f;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 400;
    vp.TopLeftY = 300;
    pContext->RSSetViewports(1u, &vp);

    GFX_THROW_INFO_ONLY(pContext->DrawIndexed((UINT)std::size(indices), 0u, 0u));
}

void ZGraphics::DrawConstantBuffer(float angle)
{
    HRESULT hr;

    struct Vertex
    {
        struct
        {
            float x;
            float y;
        } pos;
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        } color;
    };

    // NDC
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1)
    // create vertex buffer (1 2d triangle at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
    Vertex vertices[] =
    {
        { 0.0f, 0.5f, 255, 0, 0, 0 },
        { 0.5f, -0.5f, 0, 255, 0, 0 },
        { -0.5f, -0.5f, 0, 0, 255, 0 },
        { -0.3f, 0.3f, 0, 255, 0, 0 },
        { 0.3f, 0.3f, 0, 0, 255, 0 },
        { 0.0f, -0.8f, 255, 0, 0, 0 },
    };

    wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeof(vertices);
    bd.StructureByteStride = sizeof(Vertex);

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = vertices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

    // Bind vertex buffer to pipeline
    const UINT stride = sizeof(Vertex);
    const UINT offset = 0u;
    pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);


    // create index buffer
    const uint16_t indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 4, 1,
        2, 1, 5,
    };

    wrl::ComPtr<ID3D11Buffer> pIndexBuffer;
    D3D11_BUFFER_DESC ibd = {};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags = 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = sizeof(indices);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd = {};
    isd.pSysMem = indices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&ibd, &isd, &pIndexBuffer));

    // bind index buffer
    pContext->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);


    // create constant buffer for transformation matrix
    struct ConstantBuffer
    {
        struct
        {
            float element[4][4];
        } transformation;
    };
    const ConstantBuffer cb =
    {
        {
            winRatio * std::cos(angle), std::sin(angle), 0.0f, 0.0f,
            winRatio * -std::sin(angle), std::cos(angle), 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f,
        }
    };
    wrl::ComPtr<ID3D11Buffer> pConstantBuffer;
    D3D11_BUFFER_DESC cbd;
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd.Usage = D3D11_USAGE_DYNAMIC;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    cbd.MiscFlags = 0u;
    cbd.ByteWidth = sizeof(cb);
    cbd.StructureByteStride = 0u;

    // GPU에 상수 버퍼를 전달하기 전에 Transpose 해야한다. (CPU : 벡터*매트릭스, GPU : 매트릭스*벡터)
    // 여기서는 D3D 상태를 그대로 두고 VertexShader에서 row_major 키워드 사용한다.
    D3D11_SUBRESOURCE_DATA csd = {};
    csd.pSysMem = &cb;
    GFX_THROW_INFO(pDevice->CreateBuffer(&cbd, &csd, &pConstantBuffer));

    // bind constant buffer to vertex shader
    pContext->VSSetConstantBuffers(0u, 1u, pConstantBuffer.GetAddressOf());


    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShaderConst.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "Color", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)m_ClientWidth;
    vp.Height = (float)m_ClientHeight;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    pContext->RSSetViewports(1u, &vp);

    GFX_THROW_INFO_ONLY(pContext->DrawIndexed((UINT)std::size(indices), 0u, 0u));
}

void ZGraphics::DrawConstantBufferWithDXMath(float angle, float x, float y)
{
    // XMVECTOR 테스트
    dx::XMVECTOR v = dx::XMVectorSet(3.0f, 3.0f, 0.0f, 0.0f);
    auto result = dx::XMVector3Transform(v, dx::XMMatrixScaling(1.5f, 1.0f, 1.0f));
    auto xx = dx::XMVectorGetX(result);
    auto yy = dx::XMVectorGetY(result);
    auto zz = dx::XMVectorGetZ(result);
    //std::cout << xx << " " << yy << " " << zz << std::endl;

    HRESULT hr;

    struct Vertex
    {
        struct
        {
            float x;
            float y;
        } pos;
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        } color;
    };

    // NDC
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1)
    // create vertex buffer (1 2d triangle at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
    Vertex vertices[] =
    {
        { 0.0f, 0.5f, 255, 0, 0, 0 },
        { 0.5f, -0.5f, 0, 255, 0, 0 },
        { -0.5f, -0.5f, 0, 0, 255, 0 },
        //{ -0.3f, 0.3f, 0, 255, 0, 0 },
        //{ 0.3f, 0.3f, 0, 0, 255, 0 },
        //{ 0.0f, -0.8f, 255, 0, 0, 0 },
    };

    wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeof(vertices);
    bd.StructureByteStride = sizeof(Vertex);

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = vertices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

    // Bind vertex buffer to pipeline
    const UINT stride = sizeof(Vertex);
    const UINT offset = 0u;
    pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);


    // create index buffer
    const uint16_t indices[] =
    {
        0, 1, 2,
        //0, 2, 3,
        //0, 4, 1,
        //2, 1, 5,
    };

    wrl::ComPtr<ID3D11Buffer> pIndexBuffer;
    D3D11_BUFFER_DESC ibd = {};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags = 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = sizeof(indices);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd = {};
    isd.pSysMem = indices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&ibd, &isd, &pIndexBuffer));

    // bind index buffer
    pContext->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);


    // create constant buffer for transformation matrix
    struct ConstantBuffer
    {
        dx::XMMATRIX transform; // apply simd
    };
    const ConstantBuffer cb =
    {
        {
            // NDC(-1 ~ 1) : RST 변환
            dx::XMMatrixTranspose(
                dx::XMMatrixRotationZ(angle) * 
                dx::XMMatrixScaling(winRatio, 1.0f, 1.0f) * 
                dx::XMMatrixTranslation(x, y, 0)
            )
        }
    };
    wrl::ComPtr<ID3D11Buffer> pConstantBuffer;
    D3D11_BUFFER_DESC cbd;
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd.Usage = D3D11_USAGE_DYNAMIC;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    cbd.MiscFlags = 0u;
    cbd.ByteWidth = sizeof(cb);
    cbd.StructureByteStride = 0u;

    // GPU에 상수 버퍼를 전달하기 전에 Transpose 해야한다. (CPU : 벡터*매트릭스, GPU : 매트릭스*벡터)
    // 여기서는 D3D 상태를 그대로 두고 VertexShader에서 row_major 키워드 사용한다.
    D3D11_SUBRESOURCE_DATA csd = {};
    csd.pSysMem = &cb;
    GFX_THROW_INFO(pDevice->CreateBuffer(&cbd, &csd, &pConstantBuffer));

    // bind constant buffer to vertex shader
    pContext->VSSetConstantBuffers(0u, 1u, pConstantBuffer.GetAddressOf());


    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShaderColMajor.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "Color", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)m_ClientWidth;
    vp.Height = (float)m_ClientHeight;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    pContext->RSSetViewports(1u, &vp);

    GFX_THROW_INFO_ONLY(pContext->DrawIndexed((UINT)std::size(indices), 0u, 0u));
}

void ZGraphics::DrawCube(float angle, float x, float y)
{
    HRESULT hr;

    struct Vertex
    {
        struct
        {
            float x;
            float y;
            float z;
        } pos;
        struct
        {
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
        } color;
    };

    // NDC (Normalize Device Coordinate)
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1) Z(-1 ~ 1)
    // create vertex buffer (1 3d cube at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
    Vertex vertices[] =
    {
        { -1.0f, -1.0f, -1.0f   , 255, 0, 0 },
        { 1.0f, -1.0f, -1.0f    , 0, 255, 0 },
        { -1.0f, 1.0f, -1.0f    , 0, 0, 255 },
        { 1.0f, 1.0f, -1.0f     , 255, 255, 0 },
        { -1.0f, -1.0f, 1.0f    , 255, 0, 255 },
        { 1.0f, -1.0f, 1.0f     , 0, 255, 255 },
        { -1.0f, 1.0f, 1.0f     , 0, 0, 0 },
        { 1.0f, 1.0f, 1.0f      , 255, 255, 255 },
    };

    wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeof(vertices);
    bd.StructureByteStride = sizeof(Vertex);

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = vertices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

    // Bind vertex buffer to pipeline
    const UINT stride = sizeof(Vertex);
    const UINT offset = 0u;
    pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);


    // create index buffer
    const uint16_t indices[] =
    {
        0, 2, 1,  2, 3, 1,
        1, 3, 5,  3, 7, 5,
        2, 6, 3,  3, 6, 7,
        4, 5, 7,  4, 7, 6,
        0, 4, 2,  2, 4, 6,
        0, 1, 4,  1, 5, 4,
    };

    wrl::ComPtr<ID3D11Buffer> pIndexBuffer;
    D3D11_BUFFER_DESC ibd = {};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags = 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = sizeof(indices);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd = {};
    isd.pSysMem = indices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&ibd, &isd, &pIndexBuffer));

    // bind index buffer
    pContext->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);


    // create constant buffer for transformation matrix
    struct ConstantBuffer
    {
        dx::XMMATRIX transform; // apply simd
    };
    const ConstantBuffer cb =
    {
        {
            // NDC(-1 ~ 1) : RST 변환
            dx::XMMatrixTranspose(
                dx::XMMatrixRotationZ(angle) *
                dx::XMMatrixRotationY(angle) *
                // dx::XMMatrixScaling(winRatio, 1.0f, 1.0f) * // no need ratio adjustment
                dx::XMMatrixTranslation(x, y, 4) *
                dx::XMMatrixPerspectiveLH(1.0f, winRatio, 0.5f, 10.0f)
            )
        }
    };
    wrl::ComPtr<ID3D11Buffer> pConstantBuffer;
    D3D11_BUFFER_DESC cbd;
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd.Usage = D3D11_USAGE_DYNAMIC;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    cbd.MiscFlags = 0u;
    cbd.ByteWidth = sizeof(cb);
    cbd.StructureByteStride = 0u;

    // GPU에 상수 버퍼를 전달하기 전에 Transpose 해야한다. (CPU : 벡터*매트릭스, GPU : 매트릭스*벡터)
    // 여기서는 D3D 상태를 그대로 두고 VertexShader에서 row_major 키워드 사용한다.
    D3D11_SUBRESOURCE_DATA csd = {};
    csd.pSysMem = &cb;
    GFX_THROW_INFO(pDevice->CreateBuffer(&cbd, &csd, &pConstantBuffer));

    // bind constant buffer to vertex shader
    pContext->VSSetConstantBuffers(0u, 1u, pConstantBuffer.GetAddressOf());


    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShader.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShaderCube.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        //{ "Color", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 8u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "Color", 0, DXGI_FORMAT_R8G8B8A8_UNORM, 0, 12u, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr);

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)m_ClientWidth;
    vp.Height = (float)m_ClientHeight;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    pContext->RSSetViewports(1u, &vp);

    GFX_THROW_INFO_ONLY(pContext->DrawIndexed((UINT)std::size(indices), 0u, 0u));
}

void ZGraphics::DrawCubeDepth(float angle, float x, float z)
{
    HRESULT hr;

    struct Vertex
    {
        struct
        {
            float x;
            float y;
            float z;
        } pos;
    };

    // NDC (Normalize Device Coordinate)
    // 화면 가운데가 (0,0), X(-1 ~ 1), Y(-1 ~ 1) Z(-1 ~ 1)
    // create vertex buffer (1 3d cube at center of screen)
    // 왼손좌표계 앞면 : CW (Clock Wise)
    Vertex vertices[] =
    {
        { -1.0f, -1.0f, -1.0f},
        { 1.0f, -1.0f, -1.0f },
        { -1.0f, 1.0f, -1.0f },
        { 1.0f, 1.0f, -1.0f  },
        { -1.0f, -1.0f, 1.0f },
        { 1.0f, -1.0f, 1.0f },
        { -1.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 1.0f },
    };

    wrl::ComPtr<ID3D11Buffer> pVertexBuffer;
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeof(vertices);
    bd.StructureByteStride = sizeof(Vertex);

    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = vertices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer));

    // Bind vertex buffer to pipeline
    const UINT stride = sizeof(Vertex);
    const UINT offset = 0u;
    pContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);


    // create index buffer
    const uint16_t indices[] =
    {
        0, 2, 1,  2, 3, 1,
        1, 3, 5,  3, 7, 5,
        2, 6, 3,  3, 6, 7,
        4, 5, 7,  4, 7, 6,
        0, 4, 2,  2, 4, 6,
        0, 1, 4,  1, 5, 4,
    };

    wrl::ComPtr<ID3D11Buffer> pIndexBuffer;
    D3D11_BUFFER_DESC ibd = {};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags = 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = sizeof(indices);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd = {};
    isd.pSysMem = indices;
    GFX_THROW_INFO(pDevice->CreateBuffer(&ibd, &isd, &pIndexBuffer));

    // bind index buffer
    pContext->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);


    // create constant buffer for transformation matrix
    struct ConstantBuffer
    {
        dx::XMMATRIX transform; // apply simd
    };
    const ConstantBuffer cb =
    {
        {
            // NDC(-1 ~ 1) : RST 변환
            dx::XMMatrixTranspose(
                dx::XMMatrixRotationZ(angle) *
                dx::XMMatrixRotationY(angle) *
                // dx::XMMatrixScaling(winRatio, 1.0f, 1.0f) * // no need ratio adjustment
                dx::XMMatrixTranslation(x, 0.0f, z + 4.0f) *
                dx::XMMatrixPerspectiveLH(1.0f, winRatio, 0.5f, 10.0f)
            )
        }
    };
    wrl::ComPtr<ID3D11Buffer> pConstantBuffer;
    D3D11_BUFFER_DESC cbd;
    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd.Usage = D3D11_USAGE_DYNAMIC;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    cbd.MiscFlags = 0u;
    cbd.ByteWidth = sizeof(cb);
    cbd.StructureByteStride = 0u;

    // GPU에 상수 버퍼를 전달하기 전에 Transpose 해야한다. (CPU : 벡터*매트릭스, GPU : 매트릭스*벡터)
    // 여기서는 D3D 상태를 그대로 두고 VertexShader에서 row_major 키워드 사용한다.
    D3D11_SUBRESOURCE_DATA csd = {};
    csd.pSysMem = &cb;
    GFX_THROW_INFO(pDevice->CreateBuffer(&cbd, &csd, &pConstantBuffer));

    // bind constant buffer to vertex shader
    pContext->VSSetConstantBuffers(0u, 1u, pConstantBuffer.GetAddressOf());


    // 각 삼각형의 꼭지점 컬러는 다르다. 개별 값을 가져오기 위해 constant buffer 추가
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
            {1.0f, 0.0f, 1.0f},
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
            {1.0f, 1.0f, 0.0f},
            {0.0f, 1.0f, 1.0f},
        }
    };
    wrl::ComPtr<ID3D11Buffer> pConstantBuffer2;
    D3D11_BUFFER_DESC cbd2;
    cbd2.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cbd2.Usage = D3D11_USAGE_DEFAULT;
    cbd2.CPUAccessFlags = 0u;
    cbd2.MiscFlags = 0u;
    cbd2.ByteWidth = sizeof(cb2);
    cbd2.StructureByteStride = 0u;
    D3D11_SUBRESOURCE_DATA csd2 = {};
    csd2.pSysMem = &cb2;
    GFX_THROW_INFO(pDevice->CreateBuffer(&cbd2, &csd2, &pConstantBuffer2));

    // bind constant buffer to pixel shader
    pContext->PSSetConstantBuffers(0u, 1u, pConstantBuffer2.GetAddressOf());


    // create pixel shader
    wrl::ComPtr<ID3D11PixelShader> pPixelShader;
    wrl::ComPtr<ID3DBlob> pBlob;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/PixelShaderCubeDepth.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pPixelShader));

    // bind pixel shader
    pContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);


    // create vertex shader
    wrl::ComPtr<ID3D11VertexShader> pVertexShader;
    GFX_THROW_INFO(D3DReadFileToBlob(L"./x64/Debug/VertexShaderCubeDepth.cso", &pBlob));
    GFX_THROW_INFO(pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), nullptr, &pVertexShader));

    // bind vertex shader
    pContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);


    // VertexShader의 바이트코드(pBlob)가 필요하기 때문에 PixelShader를 먼저 생성한다.
    // input (vertex) layout (2d position only)
    wrl::ComPtr<ID3D11InputLayout> pInputLayout;
    const D3D11_INPUT_ELEMENT_DESC ied[] =
    {
        { "Position", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    GFX_THROW_INFO(pDevice->CreateInputLayout(
        ied, (UINT)std::size(ied),
        pBlob->GetBufferPointer(),
        pBlob->GetBufferSize(),
        &pInputLayout
    ));

    // bind vertex layout
    pContext->IASetInputLayout(pInputLayout.Get());


    // bind render target
    //pContext->OMSetRenderTargets(1u, pTarget.GetAddressOf(), nullptr); // ZGraphics 생성자에서 DepthStensil 초기화 했다. 여기서 주석

    // Set primitive topology to triangle list (groups of 3 vertices)
    pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINELIST); // CW 영향 없음
    //pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP); // CW 영향 없음

    // configure viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)m_ClientWidth;
    vp.Height = (float)m_ClientHeight;
    vp.MinDepth = 0;
    vp.MaxDepth = 1;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    pContext->RSSetViewports(1u, &vp);

    GFX_THROW_INFO_ONLY(pContext->DrawIndexed((UINT)std::size(indices), 0u, 0u));
}



// Graphics exception stuff
ZGraphics::HrException::HrException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs) noexcept
	:
	Exception(line, file),
	hr(hr)
{
	// join all info messages with newlines into single string
	for (const auto& m : infoMsgs)
	{
		info += m;
		info.push_back('\n');
	}
	// remove final newline if exists
	if (!info.empty())
	{
		info.pop_back();
	}
}

const char* ZGraphics::HrException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< "[Error Code] 0x" << std::hex << std::uppercase << GetErrorCode()
		<< std::dec << " (" << (unsigned long)GetErrorCode() << ")" << std::endl
		<< "[Error String] " << GetErrorString() << std::endl
		<< "[Description] " << GetErrorDescription() << std::endl;
	if (!info.empty())
	{
		oss << "\n[Error Info]\n" << GetErrorInfo() << std::endl << std::endl;
	}
	oss << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ZGraphics::HrException::GetType() const noexcept
{
	return "Chili Graphics Exception";
}

HRESULT ZGraphics::HrException::GetErrorCode() const noexcept
{
	return hr;
}

std::string ZGraphics::HrException::GetErrorString() const noexcept
{
	// DXGetErrorString은 TCHAR*를 반환하므로, std::string으로 변환해야 합니다.
	const TCHAR* errorString = DXGetErrorString(hr);
#ifdef _UNICODE
	// 유니코드 환경에서는 wchar_t*를 char*로 변환합니다.
	std::wstring w_str(errorString);
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &w_str[0], (int)w_str.size(), NULL, 0, NULL, NULL);
	std::string str_to(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &w_str[0], (int)w_str.size(), &str_to[0], size_needed, NULL, NULL);
	return str_to;
#else
	// 멀티바이트 환경에서는 바로 변환 가능합니다.
	return std::string(errorString);
#endif
}

std::string ZGraphics::HrException::GetErrorDescription() const noexcept
{
	TCHAR buf[512];
	DXGetErrorDescription(hr, buf, sizeof(buf) / sizeof(TCHAR));
#ifdef _UNICODE
	// 유니코드 환경에서는 wchar_t*를 char*로 변환합니다.
	std::wstring w_str(buf);
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &w_str[0], (int)w_str.size(), NULL, 0, NULL, NULL);
	std::string str_to(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &w_str[0], (int)w_str.size(), &str_to[0], size_needed, NULL, NULL);
	return str_to;
#else
	// 멀티바이트 환경에서는 바로 변환 가능합니다.
	return std::string(buf);
#endif
}

std::string ZGraphics::HrException::GetErrorInfo() const noexcept
{
	return info;
}


const char* ZGraphics::DeviceRemovedException::GetType() const noexcept
{
	return "Chili Graphics Exception [Device Removed] (DXGI_ERROR_DEVICE_REMOVED)";
}
ZGraphics::InfoException::InfoException(int line, const char* file, std::vector<std::string> infoMsgs) noexcept
	:
	Exception(line, file)
{
	// join all info messages with newlines into single string
	for (const auto& m : infoMsgs)
	{
		info += m;
		info.push_back('\n');
	}
	// remove final newline if exists
	if (!info.empty())
	{
		info.pop_back();
	}
}


const char* ZGraphics::InfoException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< "\n[Error Info]\n" << GetErrorInfo() << std::endl << std::endl;
	oss << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* ZGraphics::InfoException::GetType() const noexcept
{
	return "Chili Graphics Info Exception";
}

std::string ZGraphics::InfoException::GetErrorInfo() const noexcept
{
	return info;
}
