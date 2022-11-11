#pragma once
#include "Shape.h"

class Point : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 7, 0);
public:
	Point(void)
		:Shape()
	{}

	Point(const Shape& other)
		:Shape(other)
	{}

	Point* copy() const { Point* ret = new Point(*this); return ret; }

	void Show(HDC hdc) {
		SelectObject(hdc, hPen);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hPen); }
};

////////////////////////////////////////////////

class Line : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 3, 0);
public:
	Line(void)
		:Shape()
	{}

	Line(const Shape& other)
		:Shape(other)
	{}

	Line* copy() const { Line* ret = new Line(*this); return ret; }

	void Show(HDC hdc) {
		//SelectObject(hdc, hPen);
		MoveToEx(hdc, xs1, ys1, NULL);
		LineTo(hdc, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hPen); }
};

////////////////////////////////////////////////

class Rect : public Shape
{
private:
	HPEN hPen = CreatePen(PS_SOLID, 3, 0);
public:
	Rect(void)
		:Shape()
	{}

	Rect(const Shape& other)
		:Shape(other)
	{}

	Rect* copy() const { Rect* ret = new Rect(*this); return ret; }

	void Show(HDC hdc) {
		//SelectObject(hdc, hPen);
		MoveToEx(hdc, xs2, ys2, NULL);
		LineTo(hdc, xs2, ys1);
		LineTo(hdc, xs1 , ys1);
		LineTo(hdc, xs1, ys2);
		LineTo(hdc, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hPen); }
};

/////////////////////////////////////////////////////

class Elipse : public Shape
{
private:
	hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 255));
public:
	Elipse(void)
		:Shape()
	{}

	Elipse(const Shape& other)
		:Shape(other)
	{}

	Elipse* copy() const { Elipse* ret = new Elipse(*this); return ret; }

	void Show(HDC hdc)
	{
		//SelectObject(hdc, hBrush);
		Ellipse(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hBrush); }
};