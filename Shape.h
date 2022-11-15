#pragma once
#include "framework.h"

class Shape
{
protected:
	long xs1, ys1, xs2, ys2;
	HPEN hPen = CreatePen(PS_SOLID, 2, 0);
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
	HPEN hShadowPen = CreatePen(PS_DOT, 1, 0);
	void DrawLine(HDC hdc, long x1, long y1, long x2, long y2);
	void DrawRect(HDC hdc, long x1, long y1, long x2, long y2);
	void DrawEllipse(HDC hdc, long x1, long y1, long x2, long y2);
    Shape(const Shape&);
public:
	Shape();	
	~Shape();
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
	virtual Shape* copy() const = 0;
	BOOL isStarted();
	virtual void SelectPen(HDC);
	HPEN GetShadowPen() { return hShadowPen; };
	void UpdateEnd(HWND hWnd);
};