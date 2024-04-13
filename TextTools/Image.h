#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "EasyBMP.h"
#include "Coordinates.h"
using namespace std;

class Image : public Coordinates
{
public:
    HWND console;
    HDC dc;
    Image();
    void DrwImage(string imagePath);
};
