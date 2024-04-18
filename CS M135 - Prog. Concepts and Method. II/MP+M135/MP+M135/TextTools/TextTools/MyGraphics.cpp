#include "MyGraphics.h"

MyGraphics::MyGraphics()
{
    //Get a console handle
    myconsole = GetConsoleWindow();
    //Get a handle to device context
    mydc = GetDC(myconsole);
    COLOR = RGB(255, 255, 255);
}

MyGraphics::~MyGraphics()
{
    ReleaseDC(myconsole, mydc);
}

void MyGraphics::SetColor(int R, int G, int B)
{
    COLOR = RGB(R, G, B);
}

void MyGraphics::DrawPixel(int x, int y)
{
    SetPixel(mydc, x, y, COLOR);
}

void MyGraphics::DrawCircle(int x, int y, int radius)
{
    const double PI = 3.14159;
    for (double angle = 0; angle <= 2 * PI; angle += 0.001)//You are using radians so you will have to increase by a very small amount
     //This will have the coordinates  you want to draw a point at
        DrawPixel(x + radius * cos(angle), y + radius * sin(angle));
}
