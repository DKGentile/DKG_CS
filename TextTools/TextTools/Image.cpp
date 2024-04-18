#include "Image.h"

Image::Image()
{
    console = GetConsoleWindow();
    dc = GetDC(console);
}

void Image::DrwImage(string imagePath) {

    BMP image;
    image.ReadFromFile(imagePath.c_str());
    //image.SetBitDepth(32);
    for (int x = 0; x < image.TellWidth(); x++)
    {
        for (int y = 0; y < image.TellHeight(); y++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                SetPixel(dc, x, y, COLOUR);
            }
        }
    }
}