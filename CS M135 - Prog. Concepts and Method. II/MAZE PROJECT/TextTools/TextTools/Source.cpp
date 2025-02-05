#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Coordinates.h"
#include <Windows.h>
using namespace std;

struct position //datatype that holds two integers
{
    int x;
    int y;
};

class MyStack
{
public:
    position arr[1000]; //array of positions used to keep track of previous locations
    int T; //used to track location within array
    MyStack() { T = 0; } //constructor
    void push(int x, int y); //used to append postions within the location array
    position pop(); //used to pop positions within the loaction array
    position peek(); //used to view the previous position without popping it
};

void MyStack::push(int x, int y)
{
    position p; //defining a position and giving it the passed values
    p.x = x;
    p.y = y;
    arr[T] = p; //appending the value to the array
    T++; //moving along the array
}

position MyStack::pop()
{
    T--; //moving alone the array
    return arr[T]; //returning the values of T's location within the array
}

position MyStack::peek()
{
    return arr[T - 1]; //peeking and returning the position before current
}


MyStack S;
char board[22][50];
int value;
int xpos, ypos, ux, uy, dy, dx;
Coordinates C;

bool mySleep() //sleep function that does not prevent user from moving
{
    double d = 0;
    while (d < 12) //will loop untill d=12, interrupted by a 1 milisecond sleep to simulate time. will break if user hits anything
    {
        if (_kbhit())
        {
            return false;
        }
        d += 1;
        Sleep(1);
    }
}

// returns false of xy same as top of stack
bool CheckTopStack(int x, int y)
{
    position p;
    p = S.peek(); //sets p equal to previous location
    if (p.x == x && p.y == y) //if p = passed variables, return false
        return false;
    return true; //return true otherwise
}

bool autoMouse() {
    
    C.gotoxy(xpos, ypos); //go to current position
    C.setForeGroundAndBackGroundColor(5, 0); //set color to purple
    cout << "%"; //print the autoMouse
    if (board[ypos][xpos] == '2') //if we are on a 2
    {
        C.gotoxy(xpos + 1, ypos); 
        cout << "DONE!!" << endl; //print done
        return false; //return false (used to end program)
    }
    mySleep(); //pause
    C.gotoxy(xpos, ypos); //go to current location
    cout << ' '; //print a blank

    /* Using RDLU (right down left up), respond accordingly */
    /* If (RDLU) is a valid move and not a wall, move into it */

    if ((board[ypos][xpos + 1] != '1') && (CheckTopStack(xpos + 1, ypos))) //move right
    {
        S.push(xpos, ypos); //add the current location to the stack
        xpos++; //increase x-position
    }
    else if ((board[ypos + 1][xpos] != '1') && (CheckTopStack(xpos, ypos + 1))) //move down
    {
        S.push(xpos, ypos);
        ypos++; //increase y position
    }
    else if ((board[ypos][xpos - 1] != '1') && (CheckTopStack(xpos - 1, ypos))) //move left
    {
        S.push(xpos, ypos);
        xpos--; //decrease x position
    }
    else if ((board[ypos - 1][xpos] != '1') && (CheckTopStack(xpos, ypos - 1))) //move up
    {
        S.push(xpos, ypos);
        ypos--; //decrease y position
    }
    else // dead end
    {
        C.gotoxy(xpos, ypos); //go to current location
        cout << char(219); //print a wall
        board[ypos][xpos] = '1'; //set the board value to a wall
        position p;
        p = S.pop(); //set p = previous position
        xpos = p.x; //set x/y values to precious positions
        ypos = p.y;
        
        return true; //had error where this would default return false, so now no error
    }
}

/* the exact same thing as autoMouse, except this will be used to simulate the user's autocompeletion */
void autocomplete() {
    while (1) {
       
            C.gotoxy(ux, uy);
            C.setForeGroundAndBackGroundColor(10, 0);
            cout << "X";
            if (board[uy][ux] == '2')
            {
                C.gotoxy(ux + 1, uy);
                cout << "DONE!!" << endl;
                break;
            }
            mySleep();
            C.gotoxy(ux, uy);
            cout << ' ';
            if ((board[uy][ux + 1] != '1') && (CheckTopStack(ux + 1, uy)))
            {
                S.push(ux, uy);
                ux++;
            }
            else if ((board[uy + 1][ux] != '1') && (CheckTopStack(ux, uy + 1)))
            {
                S.push(ux, uy);
                uy++;
            }
            else if ((board[uy][ux - 1] != '1') && (CheckTopStack(ux - 1, uy)))
            {
                S.push(ux, uy);
                ux--;
            }
            else if ((board[uy - 1][ux] != '1') && (CheckTopStack(ux, uy - 1)))
            {
                S.push(ux, uy);
                uy--;
            }
            else // dead end
            {
                C.gotoxy(ux, uy);
                cout << char(219);
                board[uy][ux] = '1';
                position p;
                p = S.pop();
                ux = p.x;
                uy = p.y;
                

            }
        
    }
}

void main()
{
    
    ifstream input("c:\\temp\\mazeinterface.txt"); //opening maze file
    for (int i = 0; i < 22; i++) //storing maze file contents within board
        for (int j = 0; j < 50; j++)
            input >> board[i][j];

    for (int i = 0; i < 22; i++) //printing the maze
    {
        for (int j = 0; j < 50; j++)
        {
            if (board[i][j] == '1') //if 1, print wall
                cout << char(219);
            else if (board[i][j] == '2') //if 2, print faded wall (represents end of maze)
                cout << char(176);
            else //else, print a space
                cout << ' ';
        }
        cout << endl;
    }
    C.gotoxy(51, 0);
    cout << "USE ARROW KEYS TO MOVE";
    C.gotoxy(51, 1);
    cout << "A = AUTOCOMPLETE";
    C.gotoxy(51, 2);
    cout << "D = DESTROY";
    //setting values/positions to start of maze
    xpos = ux = dx = 0;
    ypos = uy = dy = 1;
    char c;
    C.gotoxy(ux, uy);
    cout << "X";
    while (autoMouse()) //while autoMouse is running
    {
        if (_kbhit()) { //if user does something
            c = _getch(); //record what he did
            if (c == 'd' || c == 'D') { //if user hit D, delete a 3x3 space centered at user's current location
                dx = ux - 1; // moveing to (1,1) of the 3x3 space
                dy = uy - 1;
                //moving along the 3x3 grid centered at user, deleting walls
                for (int i = 0; i < 3; i++)
                {
                    for (int K = 0; K < 3; K++)
                    {
                        if (board[dy][dx] != 2 && dx < 50 && dy < 21) {
                            board[dy][dx] = '0';
                            C.gotoxy(dx, dy);
                            cout << ' ';
                            dy++;
                        }
                    }
                    dx++;
                    dy -= 3;
                }
                C.setForeGroundAndBackGroundColor(10, 0);
                C.gotoxy(ux, uy);
                cout << 'X';


            }
            if (c == 'a' || c == 'A') { //if user hit a, the maze will auto complete.
                autocomplete();
                break;
            }
            if (c == -32) { //if user hit an arrow key
                c = _getch(); //which arrow key did user hit
                //the following if/else statements will move the user's mouse along the screen
                //in accordance with whatever key/arrow they hit
                if (board[uy][ux + 1] != '1' && c == 77) { //right
                    C.gotoxy(ux, uy);
                    cout << ' ';
                    ux++;
                    C.gotoxy(ux, uy);
                    C.setForeGroundAndBackGroundColor(10, 0);
                    cout << 'X';
                }
                else if (board[uy - 1][ux] != '1' && c == 72 && uy != 0) { //up
                    C.gotoxy(ux, uy);
                    cout << ' ';
                    uy--;
                    C.gotoxy(ux, uy);
                    C.setForeGroundAndBackGroundColor(10, 0);
                    cout << 'X';
                }
                else if (board[uy][ux - 1] != '1' && c == 75) { //left
                    C.gotoxy(ux, uy);
                    cout << ' ';
                    ux--;
                    C.gotoxy(ux, uy);
                    C.setForeGroundAndBackGroundColor(10, 0);
                    cout << 'X';
                }
                else if (board[uy + 1][ux] != '1' && c == 80) { //down
                    C.gotoxy(ux, uy);
                    cout << ' ';
                    uy++;
                    C.gotoxy(ux, uy);
                    C.setForeGroundAndBackGroundColor(10, 0);
                    cout << 'X';
                }
                if (board[uy][ux] == '2') {
                    C.setForeGroundAndBackGroundColor(10, 0);
                    C.gotoxy(ux + 1, uy);
                    cout << "DONE!!!";
                    break;
                }
            }
        }
    }


}


