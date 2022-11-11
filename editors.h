#pragma once
/*
#include "shapes.h"
#include "ShapeEditor.h"
#include "resource.h"

/////////////////////////////////////////////////////

class PointEditor : public ShapeEditor
{
public:
	PointEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	void OnLBdown(HWND hWnd) {}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateEnd();
		p[COUNT_OF_OBJECTS] = new Point;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd) {};
};

/////////////////////////////////////////////////////

class LineEditor : public ShapeEditor
{
private:
	void DrawLine()
	{
		MoveToEx(hdc, xstart, ystart, NULL);
		LineTo(hdc, xend, yend);
	}
public:
	LineEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateEnd();
		p[COUNT_OF_OBJECTS] = new Line;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (Check()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawLine();
			UpdateEnd();
			DrawLine();
		}
		
	}
};

//////////////////////////////////////////////////////

class RectEditor : public ShapeEditor
{
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, ystart);
		LineTo(hdc, xstart, ystart);
		LineTo(hdc, xstart, yend);
		LineTo(hdc, xend, yend);
	}
public:
	RectEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}

	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateEnd();
		p[COUNT_OF_OBJECTS] = new Rect;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (isStarted()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawRect();
			UpdateEnd();
			DrawRect();
		}	
	}
};

///////////////////////////////////////////////////////

class EllipseEditor : public ShapeEditor
{
private:
	void DrawRect()
	{
		MoveToEx(hdc, xend, yend, NULL);
		LineTo(hdc, xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, 2 * ystart - yend);
		LineTo(hdc, 2 * xstart - xend, yend);
		LineTo(hdc, xend, yend);
	}
	void DrawEllipse()
	{
		Arc(hdc, 2 * xstart - xend, 2 * ystart - yend, xend, yend, 0, 0, 0, 0);
	}
public:
	EllipseEditor(HWND hwnd)
		:ShapeEditor(hwnd)
	{}
	
	void OnLBup(HWND hWnd, Shape* p[], int COUNT_OF_OBJECTS)
	{
		UpdateEnd();
		p[COUNT_OF_OBJECTS] = new Ellipse;
		p[COUNT_OF_OBJECTS]->Set(xstart, ystart, xend, yend);
		xstart = ystart = xend = yend = 0;
		InvalidateRect(hWnd, NULL, TRUE);
	}

	void OnMouseMove(HWND hWnd)
	{
		if (isStarted()) {
			SetROP2(hdc, R2_NOTXORPEN);

			DrawEllipse();
			DrawRect();
			UpdateEnd();
			DrawEllipse();
			DrawRect();
		}
	}
};

*/