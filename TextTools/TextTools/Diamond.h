#pragma once

#include "MyMouse.h"
// Prints diamond pattern with 2n rows

class Diamond : public Coordinates {
public:
    int GetType() {
        return 2;
    }
    void DrawD(int n,int x1,int y1, MyMouse m)
    {
        n /= 6;
        int space = n - 1;

        
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < space; j++) {
                cout << " ";
            }
            
            for (int j = 0; j <= i; j++) {

                cout << "* ";
            }
            cout << endl;
            m.gotoxy(x1++, y1++);
            space--;
        }

        
        space = 0;

        
        for (int i = n; i > 0; i--)
        {
            
            for (int j = 0; j < space; j++)
                cout << " ";

            
            for (int j = 0; j < i; j++) {

                cout << "* ";
            }
                

            cout << endl;
            m.gotoxy(x1++, y1++);
            space++;
        }
    }
};

/*
Sources Cited:
    https://codescracker.com/cpp/program/cpp-program-print-diamond-pattern.htm
    https://vcccd.instructure.com/courses/47662/pages/textbrush-in-class-code?module_item_id=4475548
*/


