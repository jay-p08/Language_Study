//-----------------------------------------------------------------
// Space Out 4 Application
// C++ Header - SpaceOut.h
// Date : 2003.11.12
//-----------------------------------------------------------------

#ifndef SpaceOutH
#define SpaceOutH

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include <math.h>
#include "Resource.h"
//#include "Bitmap.h"
//#include "Sprite.h"
#include "AlienSprite.h"
#include "StarryBackground.h"
#include "GameEngine.h"





//-----------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------
HINSTANCE         _hInstance2;
GameEngine*       _pGame;
HDC               _hOffscreenDC;
HBITMAP           _hOffscreenBitmap;
Bitmap*           _pSplashBitmap;
Bitmap*           _pDesertBitmap;
Bitmap*           _pCarBitmap;
Bitmap*           _pSmCarBitmap;
Bitmap*           _pMissileBitmap;
Bitmap*           _pBlobboBitmap;
Bitmap*           _pBMissileBitmap;
Bitmap*           _pJellyBitmap;
Bitmap*           _pJMissileBitmap;
Bitmap*           _pTimmyBitmap;
Bitmap*           _pTMissileBitmap;
Bitmap*           _pSmExplosionBitmap;
Bitmap*           _pLgExplosionBitmap;
Bitmap*           _pGameOverBitmap;
StarryBackground* _pBackground;
Sprite*           _pCarSprite;
int               _iFireInputDelay;
int               _iNumLives, _iScore, _iDifficulty;
BOOL              _bGameOver;
int               _iGameOverDelay;
BOOL              _bDemo;
int               _iHiScores[5];

//-----------------------------------------------------------------
// Function Declarations
//-----------------------------------------------------------------
void NewGame();
void AddAlien();
void UpdateHiScores();
BOOL ReadHiScores();
BOOL WriteHiScores();
#endif
