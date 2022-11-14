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

	virtual void Show(HDC hdc) {
		DrawLine(hdc, xs2, ys2, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hPen); }
};

////////////////////////////////////////////////

class Line : public Shape
{
public:
	Line(void)
		:Shape()
	{}

	Line(const Shape& other)
		:Shape(other)
	{}

	Line* copy() const { Line* ret = new Line(*this); return ret; }

	virtual void Show(HDC hdc) {
		DrawLine(hdc, xs1, ys1, xs2, ys2);
	}
};

////////////////////////////////////////////////

class Rect : public Shape
{
public:
	Rect(void)
		:Shape()
	{}

	Rect(const Shape& other)
		:Shape(other)
	{}

	Rect* copy() const { Rect* ret = new Rect(*this); return ret; }

	virtual void Show(HDC hdc) {
		DrawRect(hdc, xs1, ys1, xs2, ys2);
	}
};

/////////////////////////////////////////////////////

class Elipse : public Shape
{
public:
	Elipse(void)
		:Shape()
	{}

	Elipse(const Shape& other)
		:Shape(other)
	{}

	Elipse* copy() const { Elipse* ret = new Elipse(*this); return ret; }

	virtual void Show(HDC hdc)
	{
		DrawEllipse(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, xs2, ys2);
	}
};

/////////////////////////////////////////////////////

class OLineO : public Line, public Elipse
{
public:
	virtual void Show(HDC hdc)
	{
		long x1, y1, x2, y2;
		x1 = Line::xs1; y1 = Line::ys1;
		x2 = Line::xs2; y2 = Line::ys2;

		Line::Show(hdc);
		Elipse::Set(x1, y1, x1 + 10, y1 + 10);
		Elipse::Show(hdc);
		Elipse::Set(x2, y2, x2 + 10, y2 + 10);
		Elipse::Show(hdc);
	}
};

class Cube : public Line, public Elipse
{
public:
	virtual void Show(HDC hdc)
	{
		long x1, y1, x2, y2;
		x1 = Line::xs1; y1 = Line::ys1;
		x2 = Line::xs2; y2 = Line::ys2;

		/*Line::Show(hdc);
		Elipse::Set(x1, y1, x1 + 10, y1 + 10);
		Elipse::Show(hdc);
		Elipse::Set(x2, y2, x2 + 10, y2 + 10);
		Elipse::Show(hdc);*/
	}
};