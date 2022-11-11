#pragma once
#include "framework.h"

class Shape
{
protected:
	long xs1 = 0, ys1 = 0, xs2 = 0, ys2 = 0;
	HPEN hPen;
	HBRUSH hBrush;
	HPEN hPenShadow = CreatePen(PS_DASH, 1, 0);
	void DrawLine(HDC hdc, long x1, long y1, long x2, long y2);
	void DrawRect(HDC hdc, long x1, long y1, long x2, long y2);
	void DrawEllipse(HDC hdc, long x1, long y1, long x2, long y2);
public:
	Shape();
	Shape(const Shape&);
	~Shape();
	int isStarted();
	virtual void SelectPen(HDC) = 0;
	HPEN GetShadowPen() { return hPenShadow; };
	void UpdateEnd(HWND hWnd);
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
	virtual Shape* copy() const = 0;
};