// GDIMonster.h: interface for the CGDIMonster class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIMONSTER_H__43127661_406E_41B5_87BB_1B42647334F1__INCLUDED_)
#define AFX_GDIMONSTER_H__43127661_406E_41B5_87BB_1B42647334F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
    
static bool TransparentBltU(
     HDC dcDest,         // handle to Dest DC
     int nXOriginDest,   // x-coord of destination upper-left corner
     int nYOriginDest,   // y-coord of destination upper-left corner
     int nWidthDest,     // width of destination rectangle
     int nHeightDest,    // height of destination rectangle
     HDC dcSrc,          // handle to source DC
     int nXOriginSrc,    // x-coord of source upper-left corner
     int nYOriginSrc,    // y-coord of source upper-left corner
     int nWidthSrc,      // width of source rectangle
     int nHeightSrc,     // height of source rectangle
     UINT crTransparent  // color to make transparent
  );

static bool AlphaBlendU(HDC dcDest, int x, int y, int cx, int cy,
                 HDC dcSrc, int sx, int sy, int scx, int scy,
                 int alpha);

static bool AlphaBlendCK(HDC dcDest, int x, int y, int cx, int cy,
                      HDC dcSrc, int sx, int sy, int scx, int scy,
                      int alpha, COLORREF rgbMask);

void PixelsToColor(HDC hdcTarget, int nWidth, int nHeight, COLORREF crColorToReplace, COLORREF crReplacementColor);
#endif // !defined(AFX_GDIMONSTER_H__43127661_406E_41B5_87BB_1B42647334F1__INCLUDED_)
