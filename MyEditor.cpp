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
	//ToolBar.OnPress(hWnd, ID_TOOL_POINT);
};

//void MyEditor::StartPointEditor(HWND hWnd) {
//	pse = new PointEditor(hWnd);
//	ToolBar.OnPress(hWnd, ID_TOOL_POINT);
//};
//void MyEditor::StartLineEditor(HWND hWnd) {
//	pse = new LineEditor(hWnd);
//	ToolBar.OnPress(hWnd, ID_TOOL_LINE);
//};
//void MyEditor::StartRectEditor(HWND hWnd) {
//	pse = new RectEditor(hWnd);
//	ToolBar.OnPress(hWnd, ID_TOOL_RECT);
//};
//void MyEditor::StartEllipseEditor(HWND hWnd) {
//	pse = new EllipseEditor(hWnd);
//	ToolBar.OnPress(hWnd, ID_TOOL_ELLIPSE);
//};
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
	}
};
void MyEditor::OnMouseMove(HWND hWnd) {
	if (pse && press)
		pse->UpdateEnd(hWnd);
		//pse->OnMouseMove(hWnd);
};
void MyEditor::OnPaint(HWND hWnd) {
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