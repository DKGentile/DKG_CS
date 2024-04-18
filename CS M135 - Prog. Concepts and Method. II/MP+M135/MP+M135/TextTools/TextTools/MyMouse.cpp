#include "MyMouse.h"

MyMouse::MyMouse()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);

    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    hin = GetStdHandle(STD_INPUT_HANDLE);
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);
    SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    buttonX = 1;
    buttonY = 1;
    ReadConsoleInput(hin, &InputRecord, 1, &Events);
}

void MyMouse::ReadMouseInput()
{
    ReadConsoleInput(hin, &InputRecord, 1, &Events);
}

void MyMouse::drawpixel(unsigned char x, unsigned char y, unsigned char Color) {
    setcolor(Color);
    gotoxy(x, y); printf("Û");
}
//*****************************************************************************

void MyMouse::drawpixel2(unsigned char x, unsigned char y, unsigned char Color, char character) {
    setcolor(Color);
    gotoxy(x, y); printf("%c", character);
}

//*****************************************************************************

void MyMouse::drawcircle(int x, int y, int a, int b, int color) {
    int wx, wy;
    int thresh;
    int asq = a * a;
    int bsq = b * b;
    int xa, ya;

    drawpixel(x, y + b, color);
    drawpixel(x, y - b, color);

    wx = 0;
    wy = b;
    xa = 0;
    ya = asq * 2 * b;
    thresh = asq / 4 - asq * b;

    for (;;) {
        thresh += xa + bsq;

        if (thresh >= 0) {
            ya -= asq * 2;
            thresh -= ya;
            wy--;
        }

        xa += bsq * 2;
        wx++;

        if (xa >= ya)
            break;


        drawpixel(x + wx, y - wy, color);
        drawpixel(x - wx, y - wy, color);
        drawpixel(x + wx, y + wy, color);
        drawpixel(x - wx, y + wy, color);
    }

    drawpixel(x + a, y, color);
    drawpixel(x - a, y, color);

    wx = a;
    wy = 0;
    xa = bsq * 2 * a;

    ya = 0;
    thresh = bsq / 4 - bsq * a;

    for (;;) {
        thresh += ya + asq;

        if (thresh >= 0) {
            xa -= bsq * 2;
            thresh = thresh - xa;
            wx--;
        }

        ya += asq * 2;
        wy++;

        if (ya > xa)
            break;

        drawpixel(x + wx, y - wy, color);
        drawpixel(x - wx, y - wy, color);
        drawpixel(x + wx, y + wy, color);
        drawpixel(x - wx, y + wy, color);
    }
}

//*****************************************************************************

void MyMouse::drawline(int x0, int y0, int x1, int y1, int color) {
    int pix = color;
    int dy = y1 - y0;
    int dx = x1 - x0;
    int stepx, stepy;

    if (dy < 0) { dy = -dy;  stepy = -1; }
    else { stepy = 1; }
    if (dx < 0) { dx = -dx;  stepx = -1; }
    else { stepx = 1; }
    dy <<= 1;                                                  // dy is now 2*dy
    dx <<= 1;                                                  // dx is now 2*dx

    drawpixel(x0, y0, pix);
    if (dx > dy) {
        int fraction = dy - (dx >> 1);                         // same as 2*dy - dx
        while (x0 != x1) {
            if (fraction >= 0) {
                y0 += stepy;
                fraction -= dx;                                // same as fraction -= 2*dx
            }
            x0 += stepx;
            fraction += dy;                                    // same as fraction -= 2*dy
            drawpixel(x0, y0, pix);
        }
    }
    else {
        int fraction = dx - (dy >> 1);
        while (y0 != y1) {
            if (fraction >= 0) {
                x0 += stepx;
                fraction -= dy;
            }
            y0 += stepy;
            fraction += dx;
            drawpixel(x0, y0, pix);
        }
    }
}

//*****************************************************************************


void MyMouse::drawframe(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, char text_[]) {
    unsigned i, j, m; {

        m = (sx - x);                       //differential
        j = m / 8;                          //adjust
        j = j - 1;                          //more adjustment
        gotoxy(x, y); printf("É");       //Top left corner of drawframe
        gotoxy(sx, y); printf("»");      //Top right corner of drawframe
        gotoxy(x, sy); printf("È");      //Bottom left corner of drawframe
        gotoxy(sx, sy); printf("¼");     //Bottom right corner of drawframe

        for (i = x + 1; i < sx; i++) {
            gotoxy(i, y); printf("Í");     // Top horizontol line
            gotoxy(i, sy); printf("Í");    // Bottom Horizontal line
        }

        for (i = y + 1; i < sy; i++) {
            gotoxy(x, i); printf("º");     //Left Vertical line
            gotoxy(sx, i); printf("º");    //Right Vertical Line
        }

        gotoxy(x + j, y); printf(text_); //put Title
        gotoxy(1, 24);
    }
}

//*****************************************************************************

void MyMouse::drawfilledrectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol) {
    int x, y;
    setcolor(bkcol);                       //Set to color bkcol

    for (y = y1; y < y2; y++) {                    //Fill Y Region Loop
        for (x = x1; x < x2; x++) {              //Fill X region Loop
            gotoxy(x, y); printf(" ");       //Draw Solid space
        }
    }
}

//*****************************************************************************

void MyMouse::drawwindow(unsigned x, unsigned y, unsigned sx, unsigned sy,
    unsigned char col, unsigned char col2, unsigned char bkcol, char text_[]) {
    drawfilledrectangle(x, y, sx, sy, bkcol);
    drawframe(x, y, sx, sy, col, col2, text_);
}

MyMouse::~MyMouse()
{
    FlushConsoleInputBuffer(hin);
}