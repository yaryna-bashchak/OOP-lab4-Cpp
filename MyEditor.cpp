#include "framework.h"
#include "MyEditor.h"
#include "Editor.h"
#include "Shape.h"
#include "editors.h"

Shape* pse = NULL;
BOOL press = FALSE;
BOOL* ppress = &press;
LPARAM LastButtonId = 0;
LPARAM* pLastButtonId = &LastButtonId;

Toolbar ToolBar(ppress, pLastButtonId);

void MyEditor::Start(HWND hWnd, Shape * object) {
	pse = object;
	ToolBar.OnPress(hWnd, object);
};

void MyEditor::OnLBdown(HWND hWnd) {
	if (pse && press)
	{
		pse->Set(0, 0, 0, 0);
		pse->UpdateEnd(hWnd);
	}
		//pse->OnLBdown(hWnd);
};
void MyEditor::OnLBup(HWND hWnd) {
	if (press && pse->isStarted())
	{
		pse->UpdateEnd(hWnd);
		pcshape[COUNT_OF_OBJECTS] = pse->copy();
		InvalidateRect(hWnd, NULL, TRUE);
		//pse->OnLBup(hWnd, pcshape, COUNT_OF_OBJECTS);
		COUNT_OF_OBJECTS++;
		pse->Set(0, 0, 0, 0);
	}
};
void MyEditor::OnMouseMove(HWND hWnd) {
	if (press && pse->isStarted())
	{
		HDC hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOTXORPEN);
		SelectObject(hdc, pse->GetShadowPen());
		pse->Show(hdc);
		pse->UpdateEnd(hWnd);
		pse->Show(hdc);
		//pse->OnMouseMove(hWnd);
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
	//pse->OnPaint(hWnd, pcshape, COUNT_OF_OBJECTS);
};

void MyEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	//if (pse) 
		//pse->OnInitMenuPopup(hWnd, wParam, LastButtonId, press);
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