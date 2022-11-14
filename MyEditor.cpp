#include "framework.h"
#include "MyEditor.h"
#include "Shape.h"
#include <typeinfo>

Shape* pse = NULL;
BOOL press = FALSE;
BOOL* ppress = &press;
LPARAM LastButtonId = 0;
LPARAM* pLastButtonId = &LastButtonId;

UINT IDS[] = { IDM_POINT, IDM_LINE, IDM_RECT, IDM_ELLIPSE, IDM_OLINEO, IDM_CUBE };

Toolbar ToolBar(ppress, pLastButtonId);

void MyEditor::Start(HWND hWnd, Shape * object) {
	pse = object;
	pse->Set(0, 0, 0, 0);
	ToolBar.OnPress(hWnd, object);
};

void MyEditor::OnLBdown(HWND hWnd) {
	if (pse && press)
	{
		pse->Set(0, 0, 0, 0);
		pse->UpdateEnd(hWnd);
	}
};
void MyEditor::OnLBup(HWND hWnd) {
	if (press && pse->isStarted())
	{
		pse->UpdateEnd(hWnd);
		pcshape[COUNT_OF_OBJECTS] = pse->copy();
		InvalidateRect(hWnd, NULL, TRUE);
		COUNT_OF_OBJECTS++;
		pse->Set(0, 0, 0, 0);
	}
};
void MyEditor::OnMouseMove(HWND hWnd) {
	if (press && pse->isStarted() && (typeid(*pse) != typeid(Point)))
	{
		HDC hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		SelectObject(hdc, pse->GetShadowPen());
		pse->Show(hdc);
		pse->UpdateEnd(hWnd);
		pse->Show(hdc);
	}
		
};
void MyEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < COUNT_OF_OBJECTS; i++)
	{
		pcshape[i]->SelectPen(hdc);
		pcshape[i]->Show(hdc);
	}	
	EndPaint(hWnd, &ps);
};

void MyEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (pse)
	{
		HMENU hMenu, hSubMenu;
		hMenu = GetMenu(hWnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		if ((HMENU)wParam == hSubMenu)
		{
			for (LPARAM ID : IDS)
				CheckMenuItem(hSubMenu, ID, MF_UNCHECKED);
		}
		if (press)
			CheckMenuItem(hSubMenu, IDS[LastButtonId - 1], MF_CHECKED);
	}
}

void MyEditor::OnCreate(HWND hWnd, HINSTANCE hInst) {
	ToolBar.OnCreate(hWnd, hInst);
};

void MyEditor::OnSize(HWND hWnd) {
	ToolBar.OnSize(hWnd);
};

void MyEditor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	ToolBar.OnNotify(hWnd, wParam, lParam);
};