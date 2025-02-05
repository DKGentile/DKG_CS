#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <queue>
using namespace std;
class Piano {
public:
    queue <char> notes;
    char x;
    void LoadNotes(string a) {
        ifstream input(a);
        while (input.peek() != -1)
        {
            input >> x;
            notes.push(x);
        }
    }
    void PlayNotes() 
    {
        while (notes.empty()!=true) {
            switch (notes.front())
            {
            case 'a':
                Beep(261, 250);
                break;
            case 's':
                Beep(293, 250);
                break;
            case 'd':
                Beep(329, 250);
                break;
            case 'f':
                Beep(349, 250);
                break;
            case 'g':
                Beep(392, 250);
                break;
            case 'h':
                Beep(440, 250);
                break;
            case 'j':
                Beep(493, 250);
                break;
            case 'k':
                Beep(523, 250);
                break;
            case 'l':
                Beep(587, 250);
                break;
            case ';':
                Beep(659, 250);
                break;
            case '\'':
                Beep(698, 250);
                break;
            case '\\':
                Beep(784, 250);
                break;
            case 'w':
                Beep(277, 250);
                break;
            case 'e':
                Beep(311, 250);
                break;
            case 't':
                Beep(370, 250);
                break;
            case 'y':
                Beep(415, 250);
                break;
            case 'u':
                Beep(466, 250);
                break;
            case 'o':
                Beep(554, 250);
                break;
            case 'p':
                Beep(622, 250);
                break;
            case ']':
                Beep(740, 250);
                break;
            }
            notes.pop();

        }
    }
};
void main()
{
    Piano mypiano;
    mypiano.LoadNotes("c:\\temp\\pianonotes.txt");
    mypiano.PlayNotes();
}