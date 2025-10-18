//---------------------------------------------------------------------------//
// Background Object
// C++ Header - Background.h
// Date : 2003.11.09
//---------------------------------------------------------------------------//
#ifndef BackgroundH
#define BackgrountH





//---------------------------------------------------------------------------//
// Include Files
//---------------------------------------------------------------------------//
#include <windows.h>
#include "Bitmap.h"
#include <algorithm>





//---------------------------------------------------------------------------//
// Background Class
//---------------------------------------------------------------------------//
class Background
{
protected:
  // Member Variables
  int       m_iWidth, m_iHeight;
  COLORREF  m_crColor;
  Bitmap*   m_pBitmap;

public:
  // Constructor(s)/Destructor
  Background(int iWidth, int iHeight, COLORREF crColor);
  Background(Bitmap* pBitmap);
  virtual ~Background();

  // General Methods
  virtual void  Update();
  virtual void  Draw(HDC hDC);

  // Accessor Methods
  int GetWidth()  { return m_iWidth; };
  int GetHeight() { return m_iHeight; };
};
//---------------------------------------------------------------------------//
#endif
