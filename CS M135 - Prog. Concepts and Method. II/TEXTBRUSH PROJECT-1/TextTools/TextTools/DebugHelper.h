#pragma once
#pragma once

#include <string>
#include <assert.h>
#include <Windows.h>
#include <winerror.h>
#include <strsafe.h>

using namespace std;

namespace DebugHelper
{
    std::string inline CreateHresultMessage(const string& message, DWORD errorCode)
    {
        return message + std::to_string(HRESULT_CODE(errorCode)) + "\n";
    }

    void inline LogToOutputWindow(const string& message)
    {
        string result = message + "\n";
        OutputDebugStringA(result.c_str());
    }

    void inline Check(bool expression, const string& message)
    {
#ifdef _DEBUG 

        if (!expression)
        {
            string outputString = message + "\n";
            OutputDebugStringA(outputString.c_str());
            assert(expression);
        }
#endif
    }
}