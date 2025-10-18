//---------------------------------------------------------------------------//
// Background Object
// C++ Header - Background.h
// Date : 2003.11.09
//---------------------------------------------------------------------------//
#ifndef StarryBackgroundH
#define StarryBackgrountH





//---------------------------------------------------------------------------//
// Include Files
//---------------------------------------------------------------------------//
#include "Background.h"





//---------------------------------------------------------------------------//
// Starry Background Class
//---------------------------------------------------------------------------//
class StarryBackground : Background
{
protected:
  // Member Variables
  int       m_iNumStars;
  int       m_iTwinkleDelay;
  POINT     m_ptStars[100];
  COLORREF  m_crStarColors[100];

public:
  // Constructor(s)/Destructor
          StarryBackground(int iWidth, int iHeight, int iNumStars = 100,
            int iTwinkleDelay = 50);
  virtual ~StarryBackground();

  // General Methods
  virtual void  Update();
  virtual void  Draw(HDC hDC);
};
//---------------------------------------------------------------------------//
#endif
