#pragma once
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")
#include "resource.h"
#include "Shape.h"

class Toolbar
{
private:
    HWND hwndToolBar = NULL;
    BOOL* ppress;
    LPARAM* pLastId;
public:
    Toolbar(BOOL*, LPARAM*);
	void OnCreate(HWND, HINSTANCE);
    void OnSize(HWND hWnd);
    void OnPress(HWND hWnd, Shape*);
    void OnNotify(HWND, WPARAM, LPARAM);
};