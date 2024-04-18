#include "MyCircle.h"

void MyCircle::DrawCircle()
{
    int c = 0;
    int val;
    int counter = 0;

    const int width = m_radius;
    const int length = m_radius * 1.5;

    for (int yy = width; yy >= -width; yy -= 2) 
    {
        gotoxy(m_x, m_y + counter++);
        for (int xx = -length; xx <= length; xx++)
        {
            val = (int) sqrt(pow(xx, 2) + pow(yy, 2));

            if (val == m_radius)
                cout << "*";
            else 
                cout << " ";
        }       
    }
}