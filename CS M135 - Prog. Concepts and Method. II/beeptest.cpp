#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Piano {
public:
    char note[25];
    void LoadNotes(string a) {
        ifstream input(a);
        for (int i = 0; i < 25; i++) {
            input >> note[i];
        }
    }
    void PlayNotes() {
        for (int i = 0; i < 25; i++) {
            switch (note[i])
            {
            case 'a':
                Beep(261, 100);
                break;
            case 's':
                Beep(293, 100);
                break;
            case 'd':
                Beep(329, 100);
                break;
            case 'f':
                Beep(349, 100);
                break;
            case 'g':
                Beep(392, 100);
                break;
            case 'h':
                Beep(440, 100);
                break;
            case 'j':
                Beep(493, 100);
                break;
            case 'k':
                Beep(523, 100);
                break;
            case 'l':
                Beep(587, 100);
                break;
            case ';':
                Beep(659, 100);
                break;
            case '\'':
                Beep(698, 100);
                break;
            case '\\':
                Beep(784, 100);
                break;
            case 'w':
                Beep(277, 100);
                break;
            case 'e':
                Beep(311, 100);
                break;
            case 't':
                Beep(370, 100);
                break;
            case 'y':
                Beep(415, 100);
                break;
            case 'u':
                Beep(466, 100);
                break;
            case 'o':
                Beep(554, 100);
                break;
            case 'p':
                Beep(622, 100);
                break;
            case ']':
                Beep(740, 100);
                break;
            }
            Sleep(250);
        }
    }

};

void main()
{
    Piano mypiano;
    mypiano.LoadNotes("c:\\temp\\pianonotes.txt");
    mypiano.PlayNotes();
}


