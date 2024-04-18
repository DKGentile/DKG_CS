#pragma once
#include <windows.h> 
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

class MyMouse2
{
private:
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];

	VOID ErrorExit(LPCSTR);
	VOID KeyEventProc(KEY_EVENT_RECORD);
	VOID MouseEventProc(MOUSE_EVENT_RECORD);
	VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
public:
	bool lButton, rButton;
	int x, y;

	MyMouse2();
	~MyMouse2();
	void ClearButtonClicks();
	void ReadMouseEvent();
};