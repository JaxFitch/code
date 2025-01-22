// Jackson Fitch

// Tries to solve a maze using a recursive solution
// Shows path through the maze if one exists

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

const int FILENAMESIZE = 255;
const int MAXROWS = 22;
const int MAXCOLS = 81;

// ASCII characters to use for display
const char WALL = (char)219;
const char WALLINFILE = '0';
const char START = 'S';
const char DEST = 'D';
const char EMPTY = ' ';
const char PATH = '*';
const char DEAD = 'X';

/*
* getFile will get a filename from the user. It then attmpts
* to open the file, read its contents, and store the maze
* structure into the maze array, based on the contents of the file.
* A WALLINFILE character in the file represents a maze wall, while
* an EMPTY character represents a free pathway. The file should also
* contain a single START character and a single DEST character.
* The function stops reading and exits the program if > MAXCOLS-1
* characters are found on one row, or if > MAXROWS rows are
* found in the file.  If the function is successful, then
* startX and startY will be set to the row and column number of
* where the START character is located in the maze.
*/
void getMaze(char maze[][MAXCOLS], int& startX, int& startY);

/*
* display is used to draw the maze on the screen.
*/
void display(const char maze[][MAXCOLS]);

// Solve the maze recursively by exploring all possible paths
// Parameters:
// - x: The current row position in the maze
// - y: The current column position in the maze
// - prevX: The previous row position in the maze
// - prevY: The previous column position in the maze
// - maze: The 2D array representing the maze
// - found: A reference to a boolean variable indicating if the destination was found
// - recursiveCalls: A reference to an integer variable counting the number of recursive calls
void mazeSolver(int x, int y, int prevX, int prevY, char maze[][MAXCOLS], bool& found, int& recursiveCalls);

// Check if a move is valid and return true if it is, false otherwise
// Parameters:
// - x: The row position of the move being checked
// - y: The column position of the move being checked
// - prevX: The previous row position in the maze
// - prevY: The previous column position in the maze
// - maze: The 2D array representing the maze
// Returns:
// - true if the move is valid, false otherwise
bool isValidMove(int x, int y, int prevX, int prevY, const char maze[][MAXCOLS]);

// Clean up any dead ends in the maze and restore the START and DEST characters
// Parameters:
// - maze: The 2D array representing the maze
// - startX: The row position of the START character in the maze
// - startY: The column position of the START character in the maze
void cleanUpMaze(char maze[][MAXCOLS], int startX, int startY);


int main()
{
    char maze[MAXROWS][MAXCOLS]; // Array to store the maze
	int startX = 0; // Variable to store the starting position
    int startY = 0; // Variable to store the starting position
    bool found = false; // Variable to indicate if the destination was found
    int recursiveCalls = 0; // Variable to count recursive calls

    // Get the maze from the file
    getMaze(maze, startX, startY);

    // Display the maze
    display(maze);

    // Wait for user to press ENTER
    cout << "\n\nPress ENTER to solve maze" << endl;
    cin.ignore();
    cin.get();

    // Solve the maze
    mazeSolver(startX, startY, -1, -1, maze, found, recursiveCalls);

    // Display the maze with the path
	cleanUpMaze(maze, startX, startY);
    display(maze);

    // Display the number of recursive calls
    if(!found)
    {
        cout << "\n               No solution to this maze -- " << recursiveCalls << " recursive calls" << endl;
    }
    else
    {
        cout << "\n                        Solution Found! -- " << recursiveCalls << " recursive calls" << endl;
    }

    return 0;
}

void getMaze(char maze[][MAXCOLS], int& startX, int& startY)
{
    // Initialize the maze array with all EMPTY characters
    for(int i = 0; i < MAXROWS; i++)
    {
        for(int j = 0; j < MAXCOLS; j++)
        {
            maze[i][j] = EMPTY;
        }
    }

    ifstream inFile;
    int row = 0;

    // Get the filename from the user
    char filename[FILENAMESIZE];
    cout << "Enter the name of a TXT file containing the maze (don't enter 'txt'): " << endl;
    cin >> filename;

    // Append .txt to the filename
    strncat_s(filename, ".txt", sizeof(filename) - strlen(filename) - 1);

    // Open the file
    inFile.open(filename);
    if(!inFile)
    {
        cerr << "ERROR: Input file cannot be opened." << endl;
        exit(1);
    }

    char line[MAXCOLS + 1];

    // Read the file line by line
    while (inFile.getline(line, MAXCOLS + 1) && row < MAXROWS)
    {
        if (strlen(line) > MAXCOLS - 1)
        {
            cerr << "ERROR: Line " << row + 1 << " in input file contains more than " << MAXCOLS - 1 << " chars" << endl;
            exit(1);
        }

        // Process each character in the line
        for (int col = 0; col < strlen(line); ++col)
        {
            maze[row][col] = (line[col] == WALLINFILE) ? WALL : line[col];
            if (maze[row][col] == START)
            {
                startX = row;
                startY = col;
            }
        }
        row++;
    }

    if(!inFile.eof() && row >= MAXROWS)
    {
        cerr << "ERROR: The file contains more than " << MAXROWS << " rows." << endl;
        exit(1);
    }
    inFile.close();
}

bool isValidMove(int x, int y, int prevX, int prevY, const char maze[][MAXCOLS])
{
    // Check if a move is valid and return true or false
    bool valid = (x >= 0 && x < MAXROWS && y >= 0 && y < MAXCOLS &&
        (maze[x][y] == EMPTY || maze[x][y] == DEST) && (x != prevX || y != prevY));
    return valid;
}

void mazeSolver(int x, int y, int prevX, int prevY, char maze[][MAXCOLS], bool& found, int& recursiveCalls)
{
    // Increment the recursive calls counter
    recursiveCalls++;

    if(found || maze[x][y] == DEST)
    {
        found = true;
        return;
    }

    // Mark the current cell as part of the path
    maze[x][y] = PATH;

	// Display the maze
	//display(maze);

    //Up
    if(isValidMove(x - 1, y, x, y, maze))
    {
        mazeSolver(x - 1, y, x, y, maze, found, recursiveCalls);
    }

    //Right
    if(isValidMove(x, y + 1, x, y, maze))
    {
        mazeSolver(x, y + 1, x, y, maze, found, recursiveCalls);
    }

    //Down
    if(isValidMove(x + 1, y, x, y, maze))
    {
        mazeSolver(x + 1, y, x, y, maze, found, recursiveCalls);
    }

    //Left
    if(isValidMove(x, y - 1, x, y, maze))
    {
        mazeSolver(x, y - 1, x, y, maze, found, recursiveCalls);
    }

    // If the destination was not found, mark the current cell as EMPTY
    if(!found)
    {
        maze[x][y] = DEAD;
		found = false;
    }
}

void display(const char maze[][MAXCOLS])
{
    // system("cls") clears the screen; only works on Windows machines
    // You will probably need to comment this out if working on
    // a non-Windows machine
    system("cls");

    // Display the maze
    for(int i = 0; i < MAXROWS; i++)
    {
        for(int j = 0; j < MAXCOLS; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

void cleanUpMaze(char maze[][MAXCOLS], int startX, int startY)
{
    // Clean up any dead ends in the maze
    for(int i = 0; i < MAXROWS; i++)
    {
        for(int j = 0; j < MAXCOLS; j++)
        {
            if(maze[i][j] == DEAD)
            {
                maze[i][j] = EMPTY;
            }
        }
    }

    // Add the START and DEST characters back in
    maze[startX][startY] = START;
}