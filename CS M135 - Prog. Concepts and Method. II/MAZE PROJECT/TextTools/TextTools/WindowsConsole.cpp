#include "WindowsConsole.h"
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <strsafe.h>
#include <tuple>
#include <iostream>
#include <string>
#include "DebugHelper.h"

using namespace DebugHelper;
using namespace std;

//--------------------------------------------------------------------------------------------

std::tuple<short, short> WindowsConsole::GetMaxWindowSize()
{
    auto windowSize = GetLargestConsoleWindowSize(GetConsoleHandle());

    return make_tuple<short, short>((SHORT)windowSize.X, (SHORT)windowSize.Y);
}

//--------------------------------------------------------------------------------------------

std::tuple<short, short> WindowsConsole::GetActiveScreenBufferSize()
{
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    if (!GetConsoleScreenBufferInfo(GetConsoleHandle(), &consoleScreenBufferInfo))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set window size with error ", GetLastError()));
        return std::tuple<short, short>(-1, -1);
    }
}

//--------------------------------------------------------------------------------------------

bool WindowsConsole::SetWindowSize(short columns, short rows)
{
    if (columns <= 0 || rows <= 0)
    {
        LogToOutputWindow("Failed to set window size. Columns or rows cannot be less than or equal to zero");
        return false;
    }

    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    if (!GetConsoleScreenBufferInfo(GetConsoleHandle(), &consoleScreenBufferInfo))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set window size with error ", GetLastError()));
        return false;
    }

    SMALL_RECT newRect;
    newRect.Top = consoleScreenBufferInfo.srWindow.Top;
    newRect.Left = consoleScreenBufferInfo.srWindow.Left;
    newRect.Bottom = rows;
    newRect.Right = columns;
    if (!SetConsoleWindowInfo(GetConsoleHandle(), true, &newRect))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set window size with error ", GetLastError()));
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------------------------

bool WindowsConsole::SetScreenBufferSize(short columns, short rows)
{
    if (columns <= 0 || rows <= 0)
    {
        LogToOutputWindow("Failed to set screen buffer size. Columns or rows cannot be less than or equal to zero");
        return false;
    }

    if (!SetConsoleScreenBufferSize(GetConsoleHandle(), { columns, rows }))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set console screen buffer size with error ", GetLastError()));
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------------------------

bool WindowsConsole::SetTitle(const string& title)
{
    if (title.size() > MAX_PATH)
    {
        LogToOutputWindow("Failed to set title. Title exceeds max path length of " + MAX_PATH);
        return false;
    }

    char szNewTitle[MAX_PATH];
    StringCchPrintfA(szNewTitle, MAX_PATH, title.c_str(), szNewTitle);

    if (!SetConsoleTitleA(szNewTitle))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set title with error ", GetLastError()));
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------------------------

bool WindowsConsole::SetFontSize(short size)
{
    if (size <= 0)
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set font size. size cannot be less than or equal to zero ", GetLastError()));
        return false;
    }

    CONSOLE_FONT_INFOEX fontInfo;

    // Note: cbSize has to be set before GetCurrentConsoleFontEx can be called otherwise it fails 
    // see https://docs.microsoft.com/en-us/windows/console/console-font-infoex
    fontInfo.cbSize = sizeof(fontInfo);

    if (!GetCurrentConsoleFontEx(GetConsoleHandle(), true, &fontInfo))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set font size with error ", GetLastError()));
        return false;
    }

    // Note: If you go to console properties -> Font you will see that the height of the pixels corresponds
    // to the font size. I just tried setting the height and ignoring width and this seems to change the font
    // without needing the width.
    fontInfo.dwFontSize = { 0, size };

    if (!SetCurrentConsoleFontEx(GetConsoleHandle(), true, &fontInfo))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to set font size with error ", GetLastError()));
        return false;
    }

    return true;
}

//--------------------------------------------------------------------------------------------

void WindowsConsole::Write(const CHAR_INFO characterBuffer[], const short columns, const short rows, const short size, std::tuple<int, int> coordinates)
{
    SMALL_RECT srctReadRect;
    SMALL_RECT srctWriteRect;
    COORD coordBufSize;
    COORD coordBufCoord;

    coordBufSize.Y = rows;
    coordBufSize.X = columns;

    coordBufCoord.X = 0;
    coordBufCoord.Y = 0;

    srctWriteRect.Top = 0;
    srctWriteRect.Left = 0;
    srctWriteRect.Bottom = rows - 1;
    srctWriteRect.Right = columns - 1;

    bool fSuccess = WriteConsoleOutput(
        GetConsoleHandle(),   // screen buffer to write to
        characterBuffer,        // buffer to copy from
        coordBufSize,           // col-row size of chiBuffer
        coordBufCoord,          // top left src cell in chiBuffer
        &srctWriteRect);        // dest. screen buffer rectangle

    if (!fSuccess)
    {
        LogToOutputWindow(CreateHresultMessage("Failed to write to console with error ", GetLastError()));
    }
}

//--------------------------------------------------------------------------------------------

void WindowsConsole::Clear()
{
    COORD cursorPosition = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    DWORD screenBufferSize;

    if (!GetConsoleScreenBufferInfo(GetConsoleHandle(), &consoleScreenBufferInfo))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to clear screen with error ", GetLastError()));
        return;
    }

    screenBufferSize = consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y;

    // Clear screen by filling it with blanks
    if (!FillConsoleOutputCharacter(GetConsoleHandle(),
        (CHAR)' ',            // Character to write to the buffer
        screenBufferSize,      // Number of cells to write
        cursorPosition,       //  Coordinates of first cell
        &cCharsWritten))      //  Receive number of characters written
    {
        return;
    }

    if (!SetConsoleCursorPosition(GetConsoleHandle(), cursorPosition))
    {
        LogToOutputWindow(CreateHresultMessage("Failed to reset console cursor position whilst clearing the screen with error ", GetLastError()));
    }
}

//--------------------------------------------------------------------------------------------

HANDLE WindowsConsole::GetConsoleHandle()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (consoleHandle == INVALID_HANDLE_VALUE)
    {
        throw InvalidHandleException();
    }
    return consoleHandle;
}