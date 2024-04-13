#include "MyGraph.h"

//Kevin: array of the 5 node letters to be used in the 
//below function
string vvs[] = { "A","B","C","D","E" };

//Kevin: added this recursive function to print the full shortest path (all letters in the path)
//it is not part of the class, but it is called in my printTable function
void printPath(int parent[], int j)//recursive printPath
{
    // Base Case is: If j is source ends rercursion
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << vvs[j] << " "; //cout << j << " ";
}



void MyGraph::moveText_Right(int moveright, int textsize, int color)
{
    vector<vector<int>> coordText{
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
{177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,220,177,177,223,177,177,219,223,223,220,177,219,223,223,219,177,223,223,219,223,223,177,219,223,223,177,219,223,223,177},
{177,219,177,177,177,177,219,177,177,219,177,219,177,177,219,177,219,220,220,223,177,219,177,177,219,177,223,219,223,177,219,177,177,219,177,219,220,220,219,177,177,177,219,177,177,177,219,223,223,177,223,223,219,177},
{177,219,220,220,219,177,223,223,223,223,177,223,223,223,223,177,223,177,223,223,177,223,223,223,177,177,223,223,223,177,223,177,177,223,177,223,177,177,223,177,177,177,223,177,177,177,223,223,223,177,223,223,223,177},
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 5; i++)//move down
    {
        for (int j{ 0 }; j < textsize; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(j + moveright, i + 1);
            cout << char(coordText[i][j]);
        }
    }

}
void MyGraph::startText_Left(int moveright, int textsize, int color)
{
    vector<vector<int>> coordText{
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
{177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,220,177,177,223,177,177,219,223,223,220,177,219,223,223,219,177,223,223,219,223,223,177,219,223,223,177,219,223,223,177},
{177,219,177,177,177,177,219,177,177,219,177,219,177,177,219,177,219,220,220,223,177,219,177,177,219,177,223,219,223,177,219,177,177,219,177,219,220,220,219,177,177,177,219,177,177,177,219,223,223,177,223,223,219,177},
{177,219,220,220,219,177,223,223,223,223,177,223,223,223,223,177,223,177,223,223,177,223,223,223,177,177,223,223,223,177,223,177,177,223,177,223,177,177,223,177,177,177,223,177,177,177,223,223,223,177,223,223,223,177},
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 5; i++)//move down
    {
        for (int j{ 53 }; j > textsize; j--) //move right 
        {
            SetConsoleTextAttribute(hConsole, color);
            gotoxy(j + moveright, i + 1);
            if (j >= 0) //Kevin Volkov: I added j>=0, otherwise crash can happen j=-1
                cout << char(coordText[i][j]);
        }
    }
}

void MyGraph::DisplayGraphBorders()
{
    MyRectangle borderTitle(0, 0, 116, 7, char(219), true, BX_N_BRDR_COLOR); //border for graph title
    borderTitle.Draw();

    MyRectangle coordinateTitle(115, 0, 56, 7, char(219), true, BX_N_BRDR_COLOR); //weight title border
    coordinateTitle.Draw();

    MyRectangle edgeBorder(0, 0, 171, 60, char(219), true, BX_N_BRDR_COLOR); //border around the console edge
    edgeBorder.Draw();

    MyRectangle Bordersplit(115, 0, 56, 60, char(219), true, BX_N_BRDR_COLOR); //border separates graph and weight
    Bordersplit.Draw();

    MyRectangle marioBorder(115, 28, 56, 32, char(219), true, BX_N_BRDR_COLOR); //mario border
    marioBorder.Draw();

    //Kevin: extra seperator between shortest path table and adjacency matrix
    MyRectangle myBorder(116, 46, 54, 1, char(219), true, BX_N_BRDR_COLOR); //added border
    myBorder.Draw();
}

void MyGraph::DisplayMarioAsciiArt()
{
    SetConsoleTextAttribute(hConsole, 9);

    vector<vector<int>> marioArt{
    {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,177,177,177,177,177,177,32,32,32,32,219,219,219,219,219,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,177,177,177,177,177,177,177,177,177,177,177,177,32,32,219,219,219,219,219,219,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,177,177,177,177,177,177,32,32,32,32,32,32,32,32,32,32,32,32,219,219,219,219,32,32,32,32,},
{32,32,32,32,32,32,32,177,177,177,177,177,177,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,219,32,32,32,32,32,},
{32,32,32,32,32,32,32,177,177,32,32,32,32,219,219,219,219,219,219,219,219,219,219,219,219,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,219,219,219,219,219,219,32,32,219,219,32,32,219,219,32,32,177,177,177,177,32,32,32,32,},
{32,32,32,32,32,219,219,32,32,32,32,219,219,219,219,219,219,32,32,219,219,32,32,219,219,32,32,32,177,177,177,32,32,32,32,},
{32,32,32,32,219,219,219,219,219,32,32,32,32,219,219,219,219,219,219,219,219,219,219,219,219,219,219,32,32,177,177,32,32,32,32,},
{32,32,32,32,219,219,219,32,219,32,32,219,219,219,219,32,32,219,219,219,219,219,219,219,219,219,219,32,32,177,177,32,32,32,32,},
{32,32,32,32,32,223,219,219,219,219,219,219,219,219,32,32,32,32,32,32,32,219,219,219,219,32,32,32,32,177,177,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,219,219,219,219,219,219,219,32,32,32,32,32,32,32,32,32,32,32,177,177,177,177,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,32,32,219,219,219,219,219,219,219,219,219,219,32,32,177,177,177,177,177,32,32,32,32,32,},
{32,32,32,32,32,32,32,177,177,177,177,32,32,32,32,32,32,32,32,32,32,32,32,32,32,177,177,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,177,177,177,177,177,177,177,177,32,176,220,176,32,32,32,32,32,220,176,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,176,177,177,177,177,177,177,177,177,32,176,32,32,219,219,219,219,32,32,32,176,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,176,177,177,177,177,177,177,177,32,32,219,219,219,219,219,219,219,219,32,176,176,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,176,176,32,177,177,177,177,177,177,177,177,32,219,219,219,219,32,32,32,176,176,176,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,176,176,176,32,177,177,177,177,177,177,32,32,32,32,32,32,32,176,176,176,176,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,176,176,176,176,32,32,32,32,32,176,176,176,176,176,176,176,176,176,176,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,176,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,176,176,176,176,176,176,176,176,176,32,176,176,176,176,176,176,176,32,254,254,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,176,176,176,176,176,176,176,176,176,32,32,32,176,176,176,176,32,254,254,254,254,32,32,32,32,},
{32,32,32,32,32,254,254,254,254,176,176,176,176,176,176,176,176,32,32,32,32,32,32,32,254,254,254,254,254,254,254,254,32,32,32,},
{32,32,32,32,254,254,254,254,254,176,176,176,176,176,176,176,32,32,32,32,32,32,32,32,254,254,254,254,254,254,254,32,32,32,32,},
{32,32,32,32,254,254,254,254,254,176,176,176,176,176,32,32,32,32,32,32,32,32,32,32,32,254,254,254,254,32,32,32,32,32,32,},
{32,32,32,32,254,254,254,254,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,},
{32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,} };

    for (int i{ 0 }; i < 28; i++)//move down
    {
        for (int j{ 0 }; j < 33; j++) //move right
        {
            if (marioArt[i][j] == 176)
            {
                SetConsoleTextAttribute(hConsole, 9);
            }
            if (marioArt[i][j] == 177)
            {
                SetConsoleTextAttribute(hConsole, 12);
            }
            if (marioArt[i][j] == 219)
            {
                SetConsoleTextAttribute(hConsole, 14);
            }
            if (marioArt[i][j] == 254)
            {
                SetConsoleTextAttribute(hConsole, 6);
            }
            if (marioArt[i][j] == 220)
            {
                SetConsoleTextAttribute(hConsole, 15);
            }
            if (marioArt[i][j] == 223)
            {
                SetConsoleTextAttribute(hConsole, 15);
            }
            gotoxy(j + 125, i + 30);
            cout << char(marioArt[i][j]);
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(143, 32);
    cout << "M";
}

//Kevin: added this function to validate the adjacency matrix
void MyGraph::validateAdjacencyMatrix(int x, int y)
{
    for (int i = 0; i < m_ROWS; i++)
    {
        for (int j = 0; j < m_ROWS; j++)
        {
            if (m_graph_array[i][j] != m_graph_array[j][i])
            {//matrix is invalid: show some error

                SetConsoleTextAttribute(hConsole, 12);//red text
                gotoxy(x, y); cout << "Invalid adjacency matrix:";
                gotoxy(x, y + 1); cout << "[" << i << "][" << j << "] != [" << j << "][" << i << "].";
                SetConsoleTextAttribute(hConsole, 7);//back to default
                break;
            }
        }
    }
}

//Kevin: added this function to display the adjancency matrix used
void MyGraph::displayAdjacencyMatrix(int x, int y)
{
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(x + 5, y); cout << "Adjacency Matrix: ";//title
    SetConsoleTextAttribute(hConsole, 9);
    gotoxy(x + 2, y + 1); cout << "A    B    C    D    E";//upper row
    for (int i = 0; i < 5; i++)
    {//left side column
        gotoxy(x, y + 3 + i);
        cout << char(65 + i);
    }
    SetConsoleTextAttribute(hConsole, 12);
    MyRectangle matrixBox;//box to print matrix numbers inside
    matrixBox.DrawSkelaton(x + 1, y + 2, 25, 6, "", 7);
    SetConsoleTextAttribute(hConsole, 240);
    for (int i = 0; i < 5; i++)
    {
        gotoxy(x + 2, y + 3 + i);
        for (int j = 0; j < 5; j++)
        {
            cout << m_graph_array[i][j];//print each matrix number
            int num_spaces;
            if (j == 4) num_spaces = 4; else num_spaces = 5;
            for (int k = 0; k < num_spaces - (to_string(m_graph_array[i][j]).length()); k++) cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);//back to default white text
}
//Kevin: This function is called from the dijkstraAlgorithm function and it is used to print the
//shortest path table
void MyGraph::printTable(int dist[], int prevVertexIndex[], int parent[], int x, int y)
{
    SetConsoleTextAttribute(hConsole, 12);//red box

    //box to draw the shortest path table inside of
    MyRectangle tableBox;
    tableBox.DrawSkelaton(x, y, 46, 9, "");

    SetConsoleTextAttribute(hConsole, 240);//black on white text

    //print the text
    gotoxy(x + 1, y + 1); cout << "        Shortest Distance Previous           " << endl;
    gotoxy(x + 1, y + 2); cout << "Vertex:  From Start (";
    SetConsoleTextAttribute(hConsole, 249);
    cout << char(65 + startNodeIndex);
    SetConsoleTextAttribute(hConsole, 240);
    cout << "):  Vertex:  Full Path:" << endl;

    for (int i = 0; i < m_ROWS; i++)
    {
        //start cleaning pevious
        gotoxy(x + 1, y + 4 + i);//first clean, what left from previous!
        cout << " " << "     ";
        cout << "                ";
        cout << "                       ";
        //end cleaning previous

        //now print the information
        gotoxy(x + 1, y + 4 + i);
        cout << "   " << char(65 + i) << "            " << dist[i];
        for (int j = 0; j < 13 - to_string(dist[i]).length(); j++) cout << " ";
        if (i != startNodeIndex)
        {
            cout << char(prevVertexIndex[i] + 65) << "     ";
            cout << char(startNodeIndex + 65) << " ";//evfix
            printPath(parent, i);//recurcievly print full path based on parent
        }
    }
    SetConsoleTextAttribute(hConsole, 12);//red lines

    //extra lines and corner pieces to seperate information
    gotoxy(x, y + 3); cout << char(195);
    for (int i = 0; i < 45; i++) cout << char(196);
    cout << char(180);
    gotoxy(x + 8, y); cout << char(194);
    for (int i = 0; i < 8; i++)
    {
        gotoxy(x + 8, y + 1 + i);
        cout << char(179);
    }
    gotoxy(x + 8, y + 3); cout << char(197);
    gotoxy(x + 8, y + 9); cout << char(193);
    gotoxy(x + 26, y); cout << char(194);
    for (int i = 0; i < 8; i++)
    {
        gotoxy(x + 26, y + 1 + i);
        cout << char(179);
    }
    gotoxy(x + 26, y + 3); cout << char(197);
    gotoxy(x + 26, y + 9); cout << char(193);
    gotoxy(x + 35, y);   cout << char(194);
    for (int i = 0; i < 8; i++)
    {
        gotoxy(x + 35, y + 1 + i);
        cout << char(179);
    }
    gotoxy(x + 35, y + 3); cout << char(197);
    gotoxy(x + 35, y + 9); cout << char(193);
}//end function printTable

//Kevin: This function is called from the dijkstraAlgorithm function and is used to find the index
//of the unisited node with the shortest distance from the start node
int MyGraph::findClosestNodeIndex(int distances[], bool visited[])
{
    int shortestDistance = INT_MAX;//to hold the shortest distance
    int shortestDistanceIndex;   //to hold the index of the node with the shortest distance

    for (int i = 0; i < m_ROWS; i++)
        if (visited[i] == false && distances[i] <= shortestDistance)
        {//new closest unvisited node found
            shortestDistance = distances[i];
            shortestDistanceIndex = i;
        }

    return shortestDistanceIndex;//return the index of the closest unvisited node
}

//Kevin: I added this function to find the shortest path to each node from the start using the
//Dijkstra algorithm. This information will be displaed in a table on the screen
//I found the code for this here:
//https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
//and then modified it to create this function, findClosestNodeIndex, printTable, and printPath
void MyGraph::dijkstraAlgorithm()
{
    int distances[m_ROWS];//to hold the shortest distance of each node from the start
    bool visited[m_ROWS];//will be true for each node that has been visited
    int prevVertexIndex[m_ROWS];//to hold the index of the last node used in the shortest path
    string fullPathStr[m_ROWS];//to hold the list of vertecies visited in the shortest path

    // Initialize all distances to INT_MAX and visited verticies as false
    for (int i = 0; i < m_ROWS; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
        prevVertexIndex[i] = 0;
        fullPathStr[i] = "";
    }

    distances[startNodeIndex] = 0;//Distance of the vertex from itself is always 0

    // Parent array is used to store shortest path tree
    int parent[m_ROWS] = { 0,0,0,0,0 };
    parent[startNodeIndex] = -1;

    string str = "";//for the fullpathstr

    // Find shortest path for all vertices
    for (int i = 0; i < m_ROWS - 1; i++)
    {
        //find the index of the unvisited node with the shortest path
        //This is aways the start node index on the first iteration
        int closestNodeIndex = findClosestNodeIndex(distances, visited);

        visited[closestNodeIndex] = true;//this index has now been visited
        int prevVisited = closestNodeIndex;//save this to be used as the preious vertex
        //fullPathStr[closestNodeIndex]=fullPathStr[closestNodeIndex]+char(closestNodeIndex+65)+" ";

        str = str + char(65 + prevVisited) + " ";//add the previously visited letter
        fullPathStr[prevVisited] = str;//add the tring to the array

        //update the distance of the nodes adjacent to the one recently visited
        for (int j = 0; j < m_ROWS; j++)
        {
            //update the distances[j] and prevVertexIndex[j] if the node is unvisited, is connected
            //to the recently visited node, and the weight of this path is less than the current 
            //disances[j]
            if (!visited[j] && m_graph_array[closestNodeIndex][j]
                && distances[closestNodeIndex] != INT_MAX
                && distances[closestNodeIndex] + m_graph_array[closestNodeIndex][j] < distances[j])
            {
                distances[j] = distances[closestNodeIndex] + m_graph_array[closestNodeIndex][j];
                parent[j] = closestNodeIndex;//added to the shortest path
                prevVertexIndex[j] = prevVisited;
            }
        }
    }

    //Now we have the information needed to print the table
    printTable(distances, prevVertexIndex, parent, 119, 30);

    //auto maxsize = WindowsConsole::GetMaxWindowSize();//get the max window size
    //coords.gotoxy(0, get<1>(maxsize) - 5);//use it to move the cursor to the bottom of the screen
    //cout << "Exiting program. "; system("pause");

    //displayAdjacencyMatrix(173,10);
    //getStartNodeIndexFromUser(119,40);
}

//Kevin: added this function to let the user selsct the starting node from which to calculate
//the shortest path. It is called at the end of the DrawGraph function
void MyGraph::getStartNodeIndexFromUser(int x, int y)
{
    //Explain to the user what to do
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(x, y); cout << "The current starting vertex is ";
    SetConsoleTextAttribute(hConsole, 9);
    cout << char(65 + startNodeIndex);
    SetConsoleTextAttribute(hConsole, 15);
    cout << ".";
    gotoxy(x, y + 1); cout << "Select a new vertex ";
    SetConsoleTextAttribute(hConsole, 10);//green text
    cout << "(press the corresponding key)";
    SetConsoleTextAttribute(hConsole, 15);//back to default
    gotoxy(x, y + 2); cout << "to see the above shortest path table change, or ";
    gotoxy(x, y + 3); cout << "press ESC to exit the program";
    gotoxy(0, 0);//so it does not scroll to the bottom
    while (true)//"endless" loop: until the user presses A-E or ESC
    {
        char c = _getch();
        if (c == 'a' || c == 'A')
        {//user selescted 'A'
            startNodeIndex = 0;
            dijkstraAlgorithm();
            break;
        }
        if (c == 'b' || c == 'B')
        {//user selected 'B'
            startNodeIndex = 1;
            dijkstraAlgorithm();
            break;
        }
        if (c == 'c' || c == 'C')
        {//user selected 'C'
            startNodeIndex = 2;
            dijkstraAlgorithm();
            break;
        }
        if (c == 'd' || c == 'D')
        {//user selected 'D'
            startNodeIndex = 3;
            dijkstraAlgorithm();
            break;
        }
        if (c == 'e' || c == 'E')
        {//user selected 'E'
            startNodeIndex = 4;
            dijkstraAlgorithm();
            break;
        }
        if (c == 27)
        {//user pressed 'ESC'
            gotoxy(x, y + 5); cout << "Exiting program. "; system("pause");
            gotoxy(0, 59); exit(1);
        }
    }
}

//Kevin: this function is called from DrawGraph and it simply calls my dijkstraAlgorithm function
// to calculate each shortest path and displa the table
void MyGraph::DisplayShortestPathTable()
{
    dijkstraAlgorithm();//m_graph_array, 0);  
    //Kevin: graph drawn: now let the user select a new start node
}

void MyGraph::DisplayCoordinatesText()
{
    /*vector<vector<int>> coordinatesText{//Kevin: origional "coordinates" text
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
{177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,220,177,177,223,177,177,219,223,223,220,177,219,223,223,219,177,223,223,219,223,223,177,219,223,223,177,219,223,223,177},
{177,219,177,177,177,177,219,177,177,219,177,219,177,177,219,177,219,220,220,223,177,219,177,177,219,177,223,219,223,177,219,177,177,219,177,219,220,220,219,177,177,177,219,177,177,177,219,223,223,177,223,223,219,177},
{177,219,220,220,219,177,223,223,223,223,177,223,223,223,223,177,223,177,223,223,177,223,223,223,177,177,223,223,223,177,223,177,177,223,177,223,177,177,223,177,177,177,223,177,177,177,223,223,223,177,223,223,223,177},
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };*/

    vector<vector<int>> coordinatesText{//Kevin: changed to "connections"
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
{177,219,223,223,219,177,219,223,223,219,177,219,223,223,220,177,219,223,223,220,177,219,223,223,177,219,223,223,177,223,223,219,223,223,177,177,223,177,177,219,223,223,219,177,219,223,223,220,177,219,223,223,177,177},
{177,219,177,177,177,177,219,177,177,219,177,219,177,177,219,177,219,177,177,219,177,219,223,223,177,219,177,177,177,177,177,219,177,177,177,223,219,223,177,219,177,177,219,177,219,177,177,219,177,223,223,219,177,177},
{177,219,220,220,219,177,223,223,223,223,177,223,177,177,223,177,223,177,177,223,177,223,223,223,177,223,223,223,177,177,177,223,177,177,177,223,223,223,177,223,223,223,223,177,223,177,177,223,177,223,223,223,177,177},
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 5; i++)//move down
    {
        for (int j{ 0 }; j < 54; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 116, i + 1);
            cout << char(coordinatesText[i][j]);
        }
    }
}

void MyGraph::DisplayGraphDataStructureText()
{
    vector<vector<int>> datastructureText{
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
{177,177,177,177,177,177,177,177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,223,223,219,177,219,177,177,219,177,177,177,177,177,219,223,223,220,177,219,223,223,219,177,223,223,219,223,223,177,219,223,223,219,177,177,177,177,177,219,223,223,223,219,177,223,223,219,223,223,177,219,223,223,219,177,219,177,177,219,177,219,223,223,177,223,223,219,223,223,177,219,177,177,219,177,219,223,223,219,177,219,223,223,177,177,177,177,177,177,177},
{177,177,177,177,177,177,177,177,219,177,220,220,177,219,220,220,223,177,219,220,220,219,177,219,177,177,219,177,219,223,223,219,177,177,177,177,177,219,177,177,219,177,219,220,220,219,177,177,177,219,177,177,177,219,220,220,219,177,177,177,177,177,223,223,223,220,220,177,177,177,219,177,177,177,219,220,220,223,177,219,177,177,219,177,219,177,177,177,177,177,219,177,177,177,219,177,177,219,177,219,220,220,223,177,219,223,223,177,177,177,177,177,177,177},
{177,177,177,177,177,177,177,177,219,220,220,219,177,223,177,223,223,177,223,177,177,223,177,219,223,223,223,177,223,177,177,223,177,177,177,177,177,219,220,220,223,177,223,177,177,223,177,177,177,223,177,177,177,223,177,177,223,177,177,177,177,177,219,220,220,220,219,177,177,177,223,177,177,177,223,177,223,223,177,177,223,223,223,177,223,223,223,177,177,177,223,177,177,177,177,223,223,223,177,223,177,223,223,177,223,223,223,177,177,177,177,177,177,177},
{177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 5; i++)//move down
    {
        for (int j{ 0 }; j < 114; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 1, i + 1);
            cout << char(datastructureText[i][j]);
        }
    }
}

void MyGraph::drawB_box()
{
    MyRectangle B_box(20, 13, 20, 10, char(219), true, BX_N_BRDR_COLOR);
    B_box.Draw();

    vector<vector<int>> B_letter{
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,187,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,203,188,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,203,188,177,177,177,177,177},
    {177,177,177,177,177,200,205,205,205,205,205,188,177,177,177,177,177,177},
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 8; i++)//move down
    {
        for (int j{ 0 }; j < 18; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 21, i + 14);
            cout << char(B_letter[i][j]);
        }
    }
}
void MyGraph::drawC_box()
{
    MyRectangle C_box2(80, 13, 20, 10, char(219), true, BX_N_BRDR_COLOR);
    C_box2.Draw();

    vector<vector<int>> C_letter{
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
    {177,177,177,177,177,177,219,219,219,219,219,187,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,219,219,186,177,177,200,205,188,177,177,177,177,177},
    {177,177,177,177,177,219,219,186,177,177,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,200,219,219,219,219,219,201,188,177,177,177,177,177},
    {177,177,177,177,177,177,200,205,205,205,205,188,177,177,177,177,177,177},
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 8; i++)//move down
    {
        for (int j{ 0 }; j < 18; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 81, i + 14);
            cout << char(C_letter[i][j]);
        }
    }
}
void MyGraph::drawD_box()
{
    MyRectangle D_box4(10, 48, 20, 10, char(219), true, BX_N_BRDR_COLOR);
    D_box4.Draw();

    vector<vector<int>> D_letter{

    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,187,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,219,219,186,177,177,219,219,186,177,177,177,177,177},
    {177,177,177,177,177,219,219,186,177,177,219,219,186,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,201,188,177,177,177,177,177},
    {177,177,177,177,177,200,205,205,205,205,205,188,177,177,177,177,177,177},
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 8; i++)//move down
    {
        for (int j{ 0 }; j < 18; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 11, i + 49);
            cout << char(D_letter[i][j]);
        }
    }
}
void MyGraph::drawA_box()
{
    MyRectangle A_box3(50, 33, 20, 10, char(219), true, BX_N_BRDR_COLOR);
    A_box3.Draw();

    vector<vector<int>> a_Letter
    { {177,177,177,177,177, 177, 177, 177, 177, 177, 177, 177, 177, 177,177,177,177,177},
    {177,177,177,177,177, 177, 219, 219, 219, 219, 219, 187, 177, 177,177 ,177,177,177},
    {177,177,177,177,177, 219, 219, 201, 205, 205, 219, 219, 187, 177,177,177,177,177},
    {177,177,177,177,177, 219, 219, 219, 219, 219, 219, 219, 186, 177,177,177,177,177},
    {177,177,177,177,177, 219, 219, 201, 205, 205, 219, 219, 186, 177,177,177,177,177},
    {177,177,177,177,177, 219, 219, 186, 177, 177, 219, 219, 186, 177,177,177,177,177},
    {177,177,177,177,177, 200, 205, 188, 177, 177, 200, 205, 188, 177,177,177,177,177},
    {177,177,177,177,177, 177, 177, 177, 177, 177, 177, 177, 177, 177,177,177,177,177} };

    for (int i{ 0 }; i < 8; i++)//move down
    {
        for (int j{ 0 }; j < 18; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 51, i + 34);
            cout << char(a_Letter[i][j]);
        }
    }
}
void MyGraph::drawE_box()
{
    MyRectangle E_box5(90, 48, 20, 10, char(219), true, BX_N_BRDR_COLOR);
    E_box5.Draw();

    vector<vector<int>> E_letter{
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,205,205,188,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,187,177,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,201,205,205,188,177,177,177,177,177,177,177},
    {177,177,177,177,177,219,219,219,219,219,219,219,187,177,177,177,177,177},
    {177,177,177,177,177,200,205,205,205,205,205,205,188,177,177,177,177,177},
    {177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177,177} };

    for (int i{ 0 }; i < 8; i++)//move down
    {
        for (int j{ 0 }; j < 18; j++) //move right
        {
            SetConsoleTextAttribute(hConsole, 62);
            gotoxy(j + 91, i + 49);
            cout << char(E_letter[i][j]);
        }
    }
}

void MyGraph::connectA_to_B()
{
    SetConsoleTextAttribute(hConsole, 13); //change font color - Pink

    horizontalLine(40, 18, 14);//create horizontal lines with parameters (x axis, y axis, and length)
    horizontalLine(40, 19, 14);

    verticalLine(53, 19, 14);//create vertical lines
    verticalLine(54, 19, 14);

    gotoxy(54, 18); //print corners
    cout << char(187);
    gotoxy(53, 19);
    cout << char(187);
}

void MyGraph::connectA_to_C()
{
    SetConsoleTextAttribute(hConsole, 6); //change font color - dark yellow
    horizontalLine(65, 18, 15);//create horizontal lines
    horizontalLine(65, 19, 15);

    verticalLine(64, 19, 14);//create vertical lines
    verticalLine(65, 19, 14);

    gotoxy(64, 18);//print corners
    cout << char(201);
    gotoxy(65, 19);
    cout << char(201);
}

void MyGraph::connectA_to_D()
{
    SetConsoleTextAttribute(hConsole, 9); //change font color - Blue 
    horizontalLine(30, 51, 22);//create horizontal lines
    horizontalLine(30, 52, 24);

    verticalLine(52, 43, 8);//create vertical lines
    verticalLine(53, 43, 10);

    gotoxy(52, 51);//print corners
    cout << char(188);
    gotoxy(53, 52);
    cout << char(188);
}

void MyGraph::connectA_to_E()
{
    SetConsoleTextAttribute(hConsole, 5); //change font color - dark Pink
    horizontalLine(68, 51, 22);//create horizontal lines
    horizontalLine(66, 52, 24);

    verticalLine(67, 43, 8);//create vertical lines
    verticalLine(66, 43, 10);

    gotoxy(67, 51); //print corners
    cout << char(200);
    gotoxy(66, 52);
    cout << char(200);
}

void MyGraph::connectB_to_C()
{
    SetConsoleTextAttribute(hConsole, 4); //change font color - dark Red
    horizontalLine(40, 15, 40);//create horizontal lines
    horizontalLine(40, 16, 40);
}

void MyGraph::connectB_to_D()
{
    SetConsoleTextAttribute(hConsole, 15); //change font color - Blue
    verticalLine(23, 23, 25);//create vertical lines
    verticalLine(24, 23, 25);
}

void MyGraph::connectB_to_E()
{
    SetConsoleTextAttribute(hConsole, 11); //change font color -  Cyan
    verticalLine(29, 11, 2);//create vertical lines
    verticalLine(30, 11, 2);

    gotoxy(29, 10);//print corners
    cout << char(201);
    gotoxy(30, 11);
    cout << char(201);

    horizontalLine(30, 10, 75);//create horizontal lines
    horizontalLine(31, 11, 75);

    verticalLine(105, 11, 37);//create vertical lines
    verticalLine(104, 11, 37);

    gotoxy(105, 10);//print corners
    cout << char(187);
    gotoxy(104, 11);
    cout << char(187);
}

void MyGraph::connectC_to_D()
{
    SetConsoleTextAttribute(hConsole, 12); //change font color - Red

    horizontalLine(15, 8, 75);//create horizontal lines
    horizontalLine(14, 9, 76);

    verticalLine(90, 9, 4);//create vertical lines
    verticalLine(89, 9, 4);

    verticalLine(14, 9, 39);//create vertical lines
    verticalLine(15, 9, 39);

    gotoxy(14, 8); //print corners
    cout << char(201);
    gotoxy(15, 9);
    cout << char(201);

    gotoxy(90, 8);
    cout << char(187);
    gotoxy(89, 9);
    cout << char(187);
}

void MyGraph::connectC_to_E()
{
    SetConsoleTextAttribute(hConsole, 1); //change font color - Dark Blue

    verticalLine(96, 23, 25);//create vertical lines
    verticalLine(95, 23, 25);
}

void MyGraph::connectD_to_E()
{
    SetConsoleTextAttribute(hConsole, 10); //change font color - Green

    horizontalLine(30, 54, 60);//create horizontal lines
    horizontalLine(30, 55, 60);
}




MyGraph::MyGraph()
{
}
MyGraph::MyGraph(std::string inputFILE)
{
    m_inputFile.open(inputFILE); //open input file

    while (!m_inputFile.eof())
    {
        for (int i = 0; i < 5; i++) // for loop to pass elements of input file into member array
        {
            for (int j = 0; j < 5; j++)
            {
                m_inputFile >> m_graph_array[i][j];
            }
        }
    }
    m_inputFile.close();
}
void MyGraph::gotoxy(int x, int y)
{
    hideCursor();

    //move cursor to a position
    _COORD pos{};
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
}
void MyGraph::verticalLine(int x, int y, int lenght)
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            gotoxy(i + x, j + y);
            cout << char(186);
        }
    }
}
void MyGraph::horizontalLine(int x, int y, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            gotoxy(i + x, j + y);
            cout << char(205);
        }
    }
}

void MyGraph::resizeConsoleWindow(int width, int height)
{
    HWND hwnd = GetConsoleWindow(); //Increase or decrease console window size
    //x,  y, width, height
    RECT rect = { 00, 00, width, height };
    MoveWindow(hwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
}

void MyGraph::hideCursor()
{
    //This will hide the cursor every time gotoxy function is called
    CONSOLE_CURSOR_INFO CURSOR{};
    BOOL result;
    CURSOR.dwSize = 1;
    CURSOR.bVisible = FALSE;
    result = SetConsoleCursorInfo(hConsole, &CURSOR);
}

MyGraph::MyGraph(int input_array[m_ROWS][m_COLUMS])
{
    //for loop to pass the input array into the class member array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            m_graph_array[j][i] = input_array[j][i];
        }
    }
}


void MyGraph::DrawGraph()
{
    hideCursor(); //hide console cursor

    //resizeConsoleWindow(1300, 1030); //Kevin:increase or decrease console window size, width & height

    //Kevin: programmatically set console font size to 12 (even if it was 16 before)
  //see https://stackoverflow.com/questions/35382432/how-to-change-the-console-font-size
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 12;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;// FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    //Kevin : end console window/font tricks

    //Kevin: changed the console title
    SetConsoleTitleA("This is my modified MyGraph drawing"); //change console title

    //Kevin: now I maximize window to full size
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);//set the window to max size so the entire graph can be seen


    DisplayGraphBorders(); // use object's functions to print borders
    DisplayCoordinatesText(); // print ascii text Kevin: "connections" instead of "coordinates"
    DisplayGraphDataStructureText();
    //DisplayMarioAsciiArt();//Kevin: commented this out

    validateAdjacencyMatrix(75, 27);//Kevin: added this
    DisplayShortestPathTable();//Kevin: added this
    displayAdjacencyMatrix(129, 48);//Kevin: added this

    drawA_box(); // display each node
    drawB_box();
    drawC_box();
    drawD_box();
    drawE_box();

    MyRectangle weightBox;//Kevin: box to put the weight number in

    //if A is connected to B
    if (m_graph_array[0][1] != 0 && m_graph_array[1][0] != 0)
    {
        connectA_to_B(); // display A to B connection if the element in the array is greater than 1

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(50, 20, to_string(m_graph_array[0][1]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 13);//pink text

        gotoxy(51, 21); //print weight

        cout << m_graph_array[0][1];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is connected to B"; // display text confirming connection

        SetConsoleTextAttribute(hConsole, 13); //change font color - Pink
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[0][1];

        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is NOT connected to B"; // display text confirming no connection
        m_y_counter += 2;
    }
    //if A is connected to C
    if (m_graph_array[0][2] != 0 && m_graph_array[2][0] != 0)
    {
        connectA_to_C(); // call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(66, 20, to_string(m_graph_array[0][2]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 6);//yellow text

        gotoxy(67, 21);//print weight
        cout << m_graph_array[0][2];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is connected to C";

        SetConsoleTextAttribute(hConsole, 6); //change font color - Dark Orange
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[0][2];
        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is NOT connected to C";
        m_y_counter += 2;
    }

    //if A is connected to D
    if (m_graph_array[0][3] != 0 && m_graph_array[3][0] != 0)
    {
        connectA_to_D();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(49, 46, to_string(m_graph_array[0][3]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 9);//blue text

        gotoxy(50, 47);//print weight
        cout << m_graph_array[0][3];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is connected to D";

        SetConsoleTextAttribute(hConsole, 9); //change font color - Dark Blue
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[0][3];
        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is NOT connected to D";
        m_y_counter += 2;
    }

    //if A is connected to E
    if (m_graph_array[0][4] != 0 && m_graph_array[4][0] != 0)
    {
        connectA_to_E();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(68, 46, to_string(m_graph_array[0][4]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 5);//purple text

        gotoxy(69, 47);//print weight
        cout << m_graph_array[0][4];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is connected to E";

        SetConsoleTextAttribute(hConsole, 5); //change font color - Dark Pink
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[0][4];

        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "A is NOT connected to E";
        m_y_counter += 2;
    }

    //if B is connected to C
    if (m_graph_array[1][2] != 0 && m_graph_array[2][1] != 0)
    {
        connectB_to_C();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(59, 12, to_string(m_graph_array[1][2]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 4);//red text

        gotoxy(60, 13);//print weight
        cout << m_graph_array[1][2];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is connected to C";

        SetConsoleTextAttribute(hConsole, 4); //change font color - Red
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[1][2];

        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is NOT connected to C";
        m_y_counter += 2;
    }

    //if B is connected to D
    if (m_graph_array[1][3] != 0 && m_graph_array[3][1] != 0)
    {
        connectB_to_D();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box and text
        weightBox.DrawSkelaton(25, 34, to_string(m_graph_array[1][3]).length() + 1, 2, "", 15);

        gotoxy(26, 35);//print weight
        cout << m_graph_array[1][3];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is connected to D";

        SetConsoleTextAttribute(hConsole, 15); //change font color - White
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[1][3];

        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is NOT connected to D";
        m_y_counter += 2;
    }

    //if B is connected to E
    if (m_graph_array[1][4] != 0 && m_graph_array[4][1] != 0)
    {
        connectB_to_E();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(101, 12, to_string(m_graph_array[1][4]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 11);//light blue text

        gotoxy(102, 13);//print weight
        cout << m_graph_array[1][4];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is connected to E";

        SetConsoleTextAttribute(hConsole, 11); //change font color - Cyan
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[1][4];
        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "B is NOT connected to E";
        m_y_counter += 2;
    }

    //if C is connected to D
    if (m_graph_array[2][3] != 0 && m_graph_array[3][2] != 0)
    {
        connectC_to_D();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(16, 10, to_string(m_graph_array[2][3]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 12);//red text

        gotoxy(17, 11);//print weight
        cout << m_graph_array[2][3];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "C is connected to D";

        SetConsoleTextAttribute(hConsole, 12); //change font color - Orange
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[2][3];
        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "C is NOT connected to D";
        m_y_counter += 2;
    }

    //if C is connected to E
    if (m_graph_array[2][4] != 0 && m_graph_array[4][2] != 0)
    {
        connectC_to_E();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(92, 34, to_string(m_graph_array[2][4]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 1);//blue text

        gotoxy(93, 35);//print weight
        cout << m_graph_array[2][4];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "C is connected to E";

        SetConsoleTextAttribute(hConsole, 1); //change font color - Dark Blue
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[2][4];
        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "C is NOT connected to E";
        m_y_counter += 2;
    }

    //if D is connected to E
    if (m_graph_array[3][4] != 0 && m_graph_array[4][3] != 0)
    {
        connectD_to_E();// call function to connect nodes

        //Kevin: made it so the connector's weight is drawn inside a box
        SetConsoleTextAttribute(hConsole, 15);//white box
        weightBox.DrawSkelaton(59, 56, to_string(m_graph_array[3][4]).length() + 1, 2, "", 15);
        SetConsoleTextAttribute(hConsole, 10);//green text

        gotoxy(60, 57);//print weight
        cout << m_graph_array[3][4];

        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "D is connected to E";
        SetConsoleTextAttribute(hConsole, 10); //change font color - Green
        horizontalLine(horizontal_X, m_y_counter, 5);
        cout << ' ' << m_graph_array[3][4];

        m_y_counter += 2;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 15); //change font color - WHITE
        gotoxy(125, m_y_counter);
        cout << "D is NOT connected to E";
        m_y_counter += 2;
    }
    //Kevin: graph drawn: now let the user select a new start node
    while (true)//"endless" loop to let the user select a new start node as many times as needed
    {
        getStartNodeIndexFromUser(119, 40);
    }
}
