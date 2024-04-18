#pragma once

#include <string>
#include <Windows.h>
#include <exception>

class InvalidHandleException : std::exception
{
    const char* what() const noexcept { return "Failed to perform operation on console. Console handle is invalid"; }
};

class WindowsConsole
{
public:
    WindowsConsole() = delete;

    static std::tuple<short, short> GetMaxWindowSize();

    static std::tuple<short, short> GetActiveScreenBufferSize();

    static bool SetWindowSize(short columns, short rows);

    static bool SetScreenBufferSize(short columns, short rows);

    static bool SetTitle(const std::string& title);

    static bool SetFontSize(short size);

    static void Write(const CHAR_INFO characterBuffer[], const short columns, const short rows, const short size, std::tuple<int, int> coordinates);

    static void Clear();

private:
    static HANDLE GetConsoleHandle();
};