#pragma once
#include "ChiliException.h"
#include <wrl.h> // ComPtr
#include "DxgiInfoManager.h"

// D3D 11의 초기화 및 핵심 인터페이스 관리

class ZGraphics
{
	friend class ZGraphicsResource;

private:
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;			// D3D11 장치, 리소스 생성 및 관리
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;			// 스왑 체인, 후면 버퍼와 화면 출력을 교체
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;	// D3D11 장치 컨텍스트, 렌더링 명령을 GPU에 전달
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pTarget;	// 렌더 타겟 뷰, 렌더링 결과가 저장되는 곳
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> pDSV;

#ifndef NDEBUG
	DxgiInfoManager infoManager;
#endif

    float winRatio;
    DWORD m_ClientWidth;
    DWORD m_ClientHeight;

public:
	class Exception : public ChiliException
	{
		using ChiliException::ChiliException;
	};
	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs = {}) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;
		std::string GetErrorDescription() const noexcept;
		std::string GetErrorInfo() const noexcept;
	private:
		HRESULT hr;
		std::string info;
	};
	class InfoException : public Exception
	{
	public:
		InfoException(int line, const char* file, std::vector<std::string> infoMsgs) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		std::string GetErrorInfo() const noexcept;
	private:
		std::string info;
	};
	class DeviceRemovedException : public HrException
	{
		using HrException::HrException;
	public:
		const char* GetType() const noexcept override;
	private:
		std::string reason;
	};

public:
	ZGraphics(HWND hWnd, float winRatio, DWORD width, DWORD height);

	// 복사 생성자와 대입 연산자를 사용하지 않는다. (객체 복사 방지)
	// -- D3D 리소스 고유하게 유지
	ZGraphics(const ZGraphics&) = delete;
	ZGraphics& operator=(const ZGraphics&) = delete;

	~ZGraphics() = default;

	// 현재 프레임의 렌더링을 끝내고 후면 버퍼를 화면에 표시한다.
	void EndFrame();
	// 후면 버퍼를 지정된 색상으로 초기화
	// red (0.0f ~ 1.0f)
	// green (0.0f ~ 1.0f)
	// blue (0.0f ~ 1.0f)
	void ClearBuffer(float red, float green, float blue) noexcept;

	// Basic
	void DrawTriangle();
    void DrawIndexedTriangle();
    void DrawConstTriangle(float angle);
    void DrawDepthCube(float angle, float x, float y); // using face color
};
