#pragma once

// 윈도우 / D3D 헤더 선언

// Windows includes
#include <windows.h>
#include <tchar.h>

// Standard ANSI-C includes
#include <time.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

// DirectX includes
#include <d3d11.h>
#include "dxerr.h"
#include "ChiliException.h"

//------------------------------------------------------------------------------

#define randomize() srand((unsigned)time(nullptr))
#define SAFE_DELETE(p)			{ if(p) { delete (p);		(p)=nullptr; }}
#define SAFE_DELETE_ARRAY(p)	{ if(p) { delete[] (p);		(p)=nullptr; }}
#define SAFE_RELEASE(p)			{ if(p) { (p)->Release();	(p)=nullptr; }}

inline int RectWidth(RECT& rc) { return ((rc).right - (rc).left); }
inline int RectHeight(RECT& rc) { return ((rc).bottom - (rc).top); }

//------------------------------------------------------------------------------
// Graphics
// D3D 활용 기본 그래픽 클래스들
#include "ZGraphics.h"
#include "ZGraphicsResource.h"

//------------------------------------------------------------------------------
// Framework
// 게임 윈도우(ZApplication) 생성 및 게임 프레임 교체 지원
#include "ZApplication.h"
