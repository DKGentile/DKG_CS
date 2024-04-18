#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Coordinates.h"
#include "MyMouse.h"
using namespace std;

class Node //creating linked list class
{
public:
    char letter; //object contains a letter
    bool hLight; //booleon value, if true program will change color of object so user knows where their curser is
    Node* next; //pointer value to point to next object
    Node* prev; //point to previous object
    Node(char cc) //constructor which creates the new node
    {
        letter = cc;
        next = prev = nullptr;
    }
};

Node* rows[10];

/*|***The Following functions do as the name implies. Code was modularized to make simulation easier.***|*/

//the following function I stole from you >:^D
void DeleteLetter(int currentrow, char c)
{
    Node* start = rows[currentrow]->next;
    
    while (1)
    {
        if (start == nullptr) { return; }
        start = rows[currentrow]->next;
        while (start != nullptr)
        {
            
            if (start->letter == c)
            {
                if (start->next != nullptr)
                {
                    Node* a1;
                    Node* a2;
                    a1 = start->next;
                    a2 = start->prev;
                    a1->prev = a2;
                    a2->next = a1;
                    delete start;
                    start = a2;
                }
                else
                {
                    start->prev->next = nullptr;
                    delete start;
                    return;
                }
            }
            start = start->next;
            
        }
    }

}

//will move curser back one
Node* Back(Node* &c, Node* &b, int currentRow) {
    if (rows[currentRow]->next != nullptr) {
        if (c != nullptr) { //if we already have a curser pointing, simply move it back
            if (c->prev != nullptr && c->prev->letter != '.') {
                c->hLight = false; //un-highlighting the node
                c = c->prev; //moving the node back
                c->hLight = true; //highlighting the new node
            }
        }
        else { //if we do not already have a curser:
            b = rows[currentRow];
            while (b->next != nullptr) //loop the the end of the line
            {
                b = b->next;
            }
            c = b->prev; //assign the curser pointer to the previous one, simulating moving back
            c->hLight = true; //highlight the new curser pointer
        }
    }
    return c, b;
}

//will add/append to the list
Node* Append(Node* &c, Node* &b, Node* &f, int currentRow, char parameter) {
    
    Node* newnode = new Node(parameter); //creating a new node to append/add
    if (rows[currentRow]->next == nullptr) //if the list is empty:
    {
        rows[currentRow]->next = newnode; //start the list
        newnode->prev = rows[currentRow]; //link the list
    }
    else //if the list is not empty:
    {
        if (c != nullptr) { //if we have a curser pointer:
            c->hLight = false; //un-highlight the curser pointer
            f = newnode; //assign f as the new node
            b = c->next; //hold the next node in variable b
            f->prev = c; //link f to the curser pointer (c)
            f->next = b; //link the new node to the b node
            c->next = f; //link the curser to the new node
            b->prev = f; //link b to the new node
            c = f; //move the curser up
            c->hLight = true; //highlight the new curser pointer

        }
        else { //if we do not have a curser pointer:
            Node* end; //new node
            end = rows[currentRow]->next; //loop it to the end of the list
            while (end->next != nullptr)
            {
                end = end->next;
            }
            end->next = newnode; //add the new node to the end of the list
            newnode->prev = end; //link the new node to the list
        }
    }
    return c, b, f;
}

//delete selected node
Node* bSpace(Node* &c, Node* &b, Node* &f, int currentRow) {
    if (c != nullptr && c->letter != '.') { //if we have a curser that is not at the beggining of the list:
        c->hLight = false; //un-highlight the curser node
        f = c->prev; //hold the previous node in 'f'
        b = c->next; //hold the next node in 'b' 
        c = nullptr; //delete the curser node
        f->next = b; //link the previous to the next
        if (b != nullptr) { b->prev = f; } //if 'b' existed, link it to 'f'
        c = f; //move the curser to 'f'
        c->hLight = true; //highlight the curser
    }
    else { //if we do not have a curser
        Node* end; //loop to the end of the list (should have made this it's own function)
        end = rows[currentRow]->next;
        while (end->next != nullptr)
        {
            end = end->next;
        }
        end = nullptr;//delete the node at the end of the list
    }
    return c, b, f;
}

//print the entire list (used for 'simulation')
void print(int x, int y, MyMouse N) {
    //x and y values used for printing
    x = 10;
    y = 0;
    Node* t = nullptr; //new node used for printing
    for (int i = 0; i < 10; i++) //looping through every row
    {
        t = rows[i]->next; //move after beggining of list
        if (t != nullptr) //if 't' exists:
        {
            while (t != nullptr) //while 't' exists:
            {
                N.gotoxy(x, y); //move to relevant location for printing
                if (t->hLight) { //if the node should be highlighted:
                    N.setForeGroundAndBackGroundColor(0, 2); //change f/bg color to simulate highlight
                    cout << t->letter; //print the letter within node
                    t = t->next; //move node
                }
                else { //if node shouldnt be highlighted:
                    N.setForeGroundAndBackGroundColor(2, 0);//reset f/bg color
                    cout << t->letter; //print the node's color
                    t = t->next; //move node
                }
                x++; //move print location right one, so as to not print over previous node letter
            }
            N.setForeGroundAndBackGroundColor(0, 0); //set f/bg color to black
            cout << "                              "; //print empty spaces to get rid of excess letters
        }
        else { //if 't' does not exist:
            N.gotoxy(x, y);//go to relevant location
            cout << "                                              "; //print blanks to get rid of excess letters
        }
        N.setForeGroundAndBackGroundColor(2, 0);//reset color scheme
        x = 10; //reset x
        y++; //increment y to simulate new line
    }
}

//printing a notch so user knows where along the input the code is reading from
void notch(MyMouse N, int x, int y) {
    N.gotoxy(x, y-1); //go to relevant location
    cout << "    "; //print a space
    N.gotoxy(x, y); //move down one
    cout << "<<<";   //print notch so user knows where code is reading from
    
}



void main()
{
    MyMouse p; //used to print letters in correct location
    string command; //used to store letters read from input file
    char parameter; //used to store chars
    Node* start = nullptr; //node used to start
    int currentRow = 0; //used to increment through rows
    Node* b = nullptr; //the following variables are place holders used for curser pointer movement
    Node* f = nullptr;
    Node* c = nullptr;
    int x1 = 0; //the following four variables are used to move print locations
    int y1 = 0;
    int x2 = 10;
    int y2 = 0;
    for (int i = 0; i < 10; i++) //emptying out the list so it is prepared for appending
    {
        rows[i] = new Node('.');
        rows[i]->next = nullptr;
        rows[i]->prev = nullptr;
    }

    ifstream toop("c:\\temp\\input.txt");   //opening the input file 
    while (toop.peek() != -1) //while reading something valid:
    {
        x1 = 0; //resetting x value
        p.gotoxy(x1, y1); //go to relevant location
        toop >> command; //storing the read command
        cout << command; //printing the command
        if (command == "A") //if we read an 'A' command:
        {
            toop >> parameter; //read the parameter
            x1 += 2; //move over two spaces
            p.gotoxy(x1, y1);
            cout << parameter; //print the command
        }
        else if (command == "DX" || command == "DL") //if we read a "DX" or "DL" command:
        {
            toop >> parameter; //read the parameter
            x1 += 3; //move over three
            p.gotoxy(x1, y1);
            cout << parameter; //print the parameter
        }
        y1++; //increment y value to print next line
    }
    toop.close(); //closing file when nothing left to read

    Sleep(1500); //sleep for a second so user can verify input read contents
    y1 = 0; //reset y
    ifstream input("c:\\temp\\input.txt"); //open input file again
    while (input.peek() != -1)//while there is something to read
    {       
        p.gotoxy(x2, y2); //go to relevant location
        input >> command; //read the input
        if (command == "NL") //if the command is "NL"
        {
            if (c != nullptr) { //if we have a curser pointer
                c->hLight = false; //un-highlight the curser pointer
            }
            c = nullptr; //set all of the curser pointer variables to null so as to not point to the wrong locaitons in the future
            b = nullptr;
            f = nullptr;
            currentRow++; //increment the current row
            if (currentRow > 10) { currentRow = 0; } //if we go to row 11, which does not exist, go back to row 1 (0)
            notch(p, 5, y1); //notch function
        }
        else if (command == "DL") //if the command is "DL"
        {
            input >> parameter; //read the parameter
            DeleteLetter(currentRow, parameter); //call the DeleteLetter function passing the currentRow and parameter
            print(x2, y2, p); //print the new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "A") //if the command is "A"
        {
            input >> parameter; //reading the parameter           
            Append(c, b, f, currentRow, parameter); //call Append, passing curser pointers, parameter, and current row
            print(x2, y2, p); //print the new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "DX") //if the command is "DX"
        {
            input >> parameter; //read the parameter
            for (int i = 0; i < 10; i++) { //loop through every row
                
                DeleteLetter(i, parameter); //DeleteLetter, passing row number (i) and parameter
            }
            print(x2, y2, p); //print new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "B") //if the command is "B"
        {
            Back(c, b, currentRow); //call Back
            print(x2, y2, p); //print new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "F") //if the command is "F"
        {
            if (c != nullptr && c->next != nullptr) {//if we have a curser pointer AND we wont be moving into a nullptr
                c->hLight = false; //un-highlight it
                c = c->next; //move it
                c->hLight = true; //highlight new node
            }
            print(x2, y2, p); //print new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "DR") //if the command is "DR"
        {
            rows[currentRow] = new Node('.'); //reset the row
            rows[currentRow]->next = nullptr;
            rows[currentRow]->prev = nullptr;            
            if (currentRow > 0) { //if we are not in row 0, decrement
                currentRow--;
            }
            c = b = f = nullptr; //reset curser pointers
            print(x2, y2, p); //print new lists
            notch(p, 5, y1); //notch
        }
        else if (command == "BS") //if the command is "BS"
        {
            bSpace(c, b, f, currentRow); //call bSpace, passing curser pointers and current row
            print(x2, y2, p); //print new list
            notch(p, 5, y1); //notch
        }
        Sleep(500); //half second pause so user can see what is happening
        y1++; //increment y1 so notch can move down
    }    
    print(x2, y2, p); //printing the new lists again
    input.close(); //closing the input file
    p.gotoxy(0, y1); //go to relevent location
    cout << "DONE!"; //inform user the program is done
    while (1) {} //while loop so program doesn't 'end'
}

