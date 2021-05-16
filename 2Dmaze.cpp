#include <iostream>
using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;


// Decalring function prototypes
void printMaze(char maze[][WIDTH], int crux, int cury);
bool validMove(char maze[][WIDTH], int newx, int newY);
bool move(char maze[][WIDTH], int &curX, int &curY, int newX, int newY);


// Return true or false if moc=ving to the specisifed coordinate is valid

bool validMove(char maze[][WIDTH], int newX, int newY)
{
    // check for going off the maze edges

    if(newX < 0 || newX >= WIDTH)
        return false;

    if (newY < 0 || newY >= HEIGHT)
        return false;

    // check if target is a wall

    if (maze[newY][newX] == 'X')
        return false;
    
    return true;
}



//Make the move on the maze to move to a new coordinate
//I passsed curX and curY by reference so they are changed to the 
// new cooordinates. I assume the move coordinates are valid.
// This returns true if we move onto the exit, false otherwise.

bool move (char maze[][WIDTH], int &curX, int &curY, int newX, int newY)
{

    bool foundExit = false;
    if (maze[newY][newX] =='E') // check for exit
        foundExit = true;
    
    curX = newX;
    curY = newY;

    return foundExit;

}

// Display the maze in ASCII 
void printMaze(char maze[][WIDTH], int curx, int cury)
{

    for (int y =0; y< HEIGHT; y++)
    {
        for (int x=0; x < WIDTH; x++)
        {
            if ((x==curx) && (y == cury))
                    cout << "@";
            else
                    cout << maze[y][x];
        }

        cout << endl;
    }
}

int main()
{

    char maze[HEIGHT][WIDTH] = {

        {'X','X','X','X','X','X','X','X','X','X'},
        {'X',' ',' ',' ',' ',' ','X',' ',' ','X'},
        {'X',' ','X',' ',' ',' ','X',' ',' ','X'},
        {'X',' ','X','X','X',' ','X',' ',' ','X'},
        {'X',' ',' ',' ','X',' ','X',' ',' ','X'},
        {'X',' ',' ',' ','X',' ',' ',' ','X','X'},
        {'X',' ','X','X','X',' ',' ',' ',' ','X'},
        {'X',' ','X',' ',' ',' ','X',' ',' ','X'},
        {'X',' ',' ',' ',' ',' ','X',' ','E','X'},
        {'X','X','X','X','X','X','X','X','X','X'}

   };

   int x=1, y =1;
   bool foundExit = false;

    while(!foundExit) 
    {
        printMaze(maze, x, y);
        cout << "Enter WASD to move. " << endl;
        char c;
        cin>> c;
        c = tolower(c);

        switch(c)
        {
                case 'w':
                    if (validMove(maze, x,y-1))
                            foundExit = move(maze, x,y,x,y-1);
                    break;

                case 'a':
                    if (validMove(maze, x-1, y))
                            foundExit = move(maze, x, y, x-1, y);
                    break;

                case 's':
                    if (validMove(maze, x, y+1))
                            foundExit = move (maze, x, y, x, y+1);
                    break;

                case 'd':
                    if (validMove(maze, x+1, y))
                            foundExit = move(maze, x, y, x+1, y);


        }
    }
}
 