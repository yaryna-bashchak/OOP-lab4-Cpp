#pragma once
#include "Shape.h"
#include <cmath>

class Point : virtual public Shape
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

	virtual Shape* copy() const
	{
		Point* NewCopy = new Point(*this);
		return NewCopy;
	}

	virtual void Show(HDC hdc)
	{
		DrawLine(hdc, xs2, ys2, xs2, ys2);
	}

	void SelectPen(HDC hdc) { SelectObject(hdc, hPen); }
};

////////////////////////////////////////////////

class Line : virtual public Shape
{
public:
	Line(void)
		:Shape()
	{}

	Line(const Shape& other)
		:Shape(other)
	{}

	virtual Shape* copy() const
	{ 
		Line* NewCopy = new Line(*this);
		return NewCopy;
	}

	virtual void Show(HDC hdc) {
		DrawLine(hdc, xs1, ys1, xs2, ys2);
	}
};

////////////////////////////////////////////////

class Rect : virtual public Shape
{
public:
	Rect(void)
		:Shape()
	{}

	Rect(const Shape& other)
		:Shape(other)
	{}

	virtual Shape* copy() const 
	{
		Rect* NewCopy = new Rect(*this);
		return NewCopy;
	}

	virtual void Show(HDC hdc) {
		DrawRect(hdc, xs1, ys1, xs2, ys2);
	}
};

/////////////////////////////////////////////////////

class Elipse : virtual public Shape
{
public:
	Elipse(void)
		:Shape()
	{}

	Elipse(const Shape& other)
		:Shape(other)
	{}

	virtual Shape* copy() const 
	{ 
		Elipse* NewCopy = new Elipse(*this); 
		return NewCopy; 
	}

	virtual void Show(HDC hdc)
	{
		DrawEllipse(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, xs2, ys2);
	}
};

/////////////////////////////////////////////////////

class OLineO : virtual public Line, virtual public Elipse
{
public:
	OLineO(void)
		:Shape()
	{}

	OLineO(const Shape& other)
		:Shape(other)
	{}

	virtual Shape* copy() const 
	{ 
		OLineO* NewCopy = new OLineO(*this);
		return NewCopy;
	}

	virtual void Show(HDC hdc)
	{
		long x1 = xs1, y1 = ys1, x2 = xs2, y2 = ys2;
		long r = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) / 10;

		Line::Show(hdc);
		Set(x1, y1, x1 + r, y1 + r);
		Elipse::Show(hdc);
		Set(x2, y2, x2 + r, y2 + r);
		Elipse::Show(hdc);

		Set(x1, y1, x2, y2);
	}
};

class Cube : virtual public Rect, virtual public Line
{
public:
	Cube(void)
		:Shape()
	{}

	Cube(const Cube& other)
		:Shape(other)
	{}

	virtual Shape* copy() const 
	{ 
		Cube* NewCopy = new Cube(*this);
		return NewCopy;
	}

	virtual void Show(HDC hdc)
	{
		long x1 = xs1, y1 = ys1, x2 = xs2, y2 = ys2;
		long a = min(abs(x2 - x1), abs(y2 - y1));
		long ax = (((x2 - x1) > 0) ? 1 : -1) * a;
		long ay = (((y2 - y1) > 0) ? 1 : -1) * a;

		Set(x1, y1, x1 + 3 * ax / 4, y1 + 3 * ay / 4);
		Rect::Show(hdc);
		Set(x1 + ax / 4, y1 + ay / 4, x1 + ax, y1 + ay);
		Rect::Show(hdc);

		Set(x1, y1, x1 + ax / 4, y1 + ay / 4);
		Line::Show(hdc);
		Set(x1 + 3 * ax / 4, y1 + 3 * ay / 4, x1 + ax, y1 + ay);
		Line::Show(hdc);
		Set(x1, y1 + 3 * ay / 4, x1 + ax / 4, y1 + ay);
		Line::Show(hdc);
		Set(x1 + 3 * ax / 4, y1, x1 + ax, y1 + ay / 4);
		Line::Show(hdc);

		Set(x1, y1, x2, y2);
	}
};