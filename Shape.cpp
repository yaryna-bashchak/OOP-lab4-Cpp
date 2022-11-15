#include "Shape.h"

Shape::Shape() {}

Shape::Shape(const Shape &other)
{
	xs1 = other.xs1;
	ys1 = other.ys1;
	xs2 = other.xs2;
	ys2 = other.ys2;
}

Shape::~Shape()
{
	DeleteObject(hPen);
	DeleteObject(hShadowPen);
	DeleteObject(hBrush);
}

void Shape::Set(long x1 = 0, long y1 = 0, long x2 = 0, long y2 = 0)
{
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}

void Shape::UpdateEnd(HWND hWnd)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	if (!isStarted())
	{
		xs1 = pt.x;
		ys1 = pt.y;
	}
	xs2 = pt.x;
	ys2 = pt.y;
}

void Shape::DrawLine(HDC hdc, long x1, long y1, long x2, long y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

void Shape::DrawRect(HDC hdc, long x1, long y1, long x2, long y2)
{
	MoveToEx(hdc, x2, y2, NULL);
	LineTo(hdc, x2, y1);
	LineTo(hdc, x1, y1);
	LineTo(hdc, x1, y2);
	LineTo(hdc, x2, y2);
}

void Shape::DrawEllipse(HDC hdc, long x1, long y1, long x2, long y2)
{
	Ellipse(hdc, x1, y1, x2, y2);
}

BOOL Shape::isStarted() {
	if (xs1 == 0 && ys1 == 0 && xs2 == 0 && ys2 == 0) return 0;
	else return 1;
}

void Shape::SelectPen(HDC hdc)
{ 
	SelectObject(hdc, hPen);
	if (hBrush)
		SelectObject(hdc, hBrush);
}
