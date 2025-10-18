//---------------------------------------------------------------------------//
// StarryBackground Object
// C++ Source - StarryBackground.cpp
// Date : 2003.11.09
//---------------------------------------------------------------------------//





//---------------------------------------------------------------------------//
// Include Files
//---------------------------------------------------------------------------//
#include "StarryBackground.h"





//---------------------------------------------------------------------------//
// StarryBackground Constructor
//---------------------------------------------------------------------------//
StarryBackground::StarryBackground(int iWidth, int iHeight, int iNumStars,
  int iTwinkleDelay) : Background(iWidth, iHeight, 0)
{
  // Initialize the member variables
  m_iNumStars = min(iNumStars, 100);
  m_iTwinkleDelay = iTwinkleDelay;

  // Create the stars
  for (int i = 0; i < iNumStars; i++)
  {
    m_ptStars[i].x = rand() % iWidth;
    m_ptStars[i].y = rand() % iHeight;
    m_crStarColors[i] = RGB(128, 128, 128);
  }
}
//---------------------------------------------------------------------------
StarryBackground::~StarryBackground()
{
}
//---------------------------------------------------------------------------//





//---------------------------------------------------------------------------//
// StarryBackground General Methods
//---------------------------------------------------------------------------//
void StarryBackground::Update()
{
  // Randomly change the shade of the stars so that they twinkle
  int iRGB;
  for (int i = 0; i < m_iNumStars; i++)
    if ((rand() % m_iTwinkleDelay) == 0)
    {
      iRGB = rand() % 256;
      m_crStarColors[i] = RGB(iRGB, iRGB, iRGB);
    }
}
//---------------------------------------------------------------------------
void StarryBackground::Draw(HDC hDC)
{
  // Draw the solid black background
  RECT    rect = { 0, 0, m_iWidth, m_iHeight };
  HBRUSH  hBrush = CreateSolidBrush(RGB(0, 0, 0));
  FillRect(hDC, &rect, hBrush);
  DeleteObject(hBrush);

  // Draw the stars
  for (int i = 0; i < m_iNumStars; i++)
    SetPixel(hDC, m_ptStars[i].x, m_ptStars[i].y, m_crStarColors[i]);
}
//---------------------------------------------------------------------------//
