// Jackson Fitch

// Life simulation

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

const int MAXWORLDROWS = 25;
const int MAXWORLDCOLS = 80;
const int MAXROWS = MAXWORLDROWS + 2;
const int MAXCOLS = MAXWORLDCOLS + 2;
const int FILENAMESIZE = 255;

// ASCII characters to use for display
// https://theasciicode.com.ar/extended-ascii-code/block-graphic-character-ascii-code-219.html
// for interesting effect use code 219 and 176 instead of the asterisk and space
const unsigned char CELL = '*';  // 219;
const unsigned char EMPTY = ' '; // 176;

enum class State { dead = 0, alive = 1 };

/*
* initWorld is used to initialize all positions in the world
* array to the 'dead' state
*/
void initWorld(State world[][MAXCOLS]);

/*
* display is used to draw the 'world' onto the screen
* for each 'alive' cell, the value CELL is displayed
* for each 'dead' cell, the value EMPTY is displayed
* does NOT display any items in:
*   row 0, row MAXROWS-1, column 0, or column MAXCOLS-1
* since these rows and columns are used as a "border"
* around the world grid
*/
void display(State world[][MAXCOLS]);

/*
* getFile will get a filename from the user. It then attmpts
* to open the file, read its contents, and update the world
* based on the contents of the file. The file should contain
* only spaces and asterisks. A space represents a 'dead' cell
* and an asterisk represents an 'alive' cell.
* The function stops reading and exits the program if > MAXWORLDCOLS
* characters are found on one row, or if > MAXWORLDROWS rows are
* found in the file.
*/
void getFile(State world[][MAXCOLS]);

/*
* calcNewWorld is used to calculate the new state of the world
* (i.e. a new generation) based upon analyzing the current world state
*/
void calcNewWorld(State world[][MAXCOLS]);

/*
* neighborCount is used to count the number of 'alive' cells in
* the 8 neighboring positions which are surrounding position
* [row][col] in world
*/
int neighborCount(State world[][MAXCOLS], int row, int col);

int main()
{
	State world[MAXROWS][MAXCOLS];
	int generation = 0;
	bool stop = false;
	
	
	// TODO: set up and initialize the 'world' array

	generation = -1;
	initWorld(world);
	getFile(world);

	do
	{
		// system("cls") clears the screen; only works on Windows machines
		// You will probably need to comment this out if working on
		// a non-Windows machine
		system("cls");

		display(world);
		generation++;
		cout << "Generation: " << generation << "\t";
		cout << "<ENTER> to continue / <Q + ENTER> to quit: ";
		
		// TODO: get input from user and decide whether to quit the loop
		// and whether to compute a new generation

		// Capture the entire line of input
		string input;
		getline(cin, input);

		// Check if the input is "q" or "Q" to quit the loop
		if (input == "q" || input == "Q") 
		{
			stop = true; // Quit the loop
		}
        else if (input.empty() && generation > 0)
        {
            calcNewWorld(world); // Advance to the next generation
        }

	} while (!stop);

	return 0;
}

int neighborCount(State world[][MAXCOLS], int row, int col)
{
	// This code checks to make sure you aren't trying to count neighbors for any
	// position on row #0, or on row #MAXWORLDROWS+1,
	// or in column 0, or in columnn MAXWORLDCOLUMNS+1
	// because if you are, you are going to run into array out-of-bounds problems
	if (row < 1 || row > MAXWORLDROWS)
	{
		cerr << "ERROR: invalid row parameter " << row << " in neighborCount\n";
		exit(1);
	}
	else if (col < 1 || col > MAXWORLDCOLS)
	{
		cerr << "ERROR: invalid col parameter " << col << " in neighborCount\n";
		exit(1);
	}

	int i = 0;

	// TODO: write neighborCount code
	
	for(int r = row - 1; r <= row + 1; r++)
	{
		for(int c = col - 1; c <= col + 1; c++)
		{
			if((r != row || c != col) && world[r][c] == State::alive) // Exclude the cell itself
			{
				i++;
			}
		}
	}


	return i;
}

void calcNewWorld(State world[][MAXCOLS])
{
	// TODO: write calcNewWorld code

	// Create a new world to store the next generation
	State newWorld[MAXROWS][MAXCOLS];
	initWorld(newWorld);

	for(int row = 1; row <= MAXWORLDROWS; row++)
	{
		for(int col = 1; col <= MAXWORLDCOLS; col++)
		{
			int neighbors = neighborCount(world, row, col);
			if(world[row][col] == State::alive)
			{
				if(neighbors < 2 || neighbors > 3)
				{
					newWorld[row][col] = State::dead;
				}
				else
				{
					newWorld[row][col] = State::alive;
				}
			}
			else
			{
				if(neighbors == 3)
				{
					newWorld[row][col] = State::alive;
				}
				else
				{
					newWorld[row][col] = State::dead;
				}
			}
		}
	}

	// Copy the new world to the current world
	for(int row = 1; row <= MAXWORLDROWS; row++)
	{
		for(int col = 1; col <= MAXWORLDCOLS; col++)
		{
			world[row][col] = newWorld[row][col];
		}
	}

}

void getFile(State world[][MAXCOLS])
{
	ifstream inFile;
	int row = 1;

	// TODO: Write getFile code
	// Make sure row is incremented each time you read a line from the file
	row = 0;

	// Get the filename from the user
	string filename;
	cout << "Enter the filename containing the initial structure: " << endl;
	cin >> filename;

	// Open the file
	inFile.open(filename.c_str());
	if(!inFile) 
	{
		cout << "ERROR: Input file cannot be opened." << endl;
		exit(1);
	}

	string line;

	// Read the file line by line
	while(getline(inFile, line) && row <= MAXWORLDROWS) 
	{
		if(line.length() > MAXWORLDCOLS) 
		{
			cout << "ERROR: Line " << row << " in input file contains more than " << MAXWORLDCOLS << " characters." << endl;
			exit(1);
		}

		// Process each character in the line
		for(int col = 1; col <= line.length(); ++col) 
		{
			world[row][col] = (line[col - 1] == '*') ? State::alive : State::dead;
			
		}
		row++;
	}

	// After file reading is finished, this code checks to see if the reading stopped
	// because of too many characters on a line in the file, or too many rows in the file
	// It is possible that you might have to change the conditions here depending on
	// exactly how you choose to read the file
    if (inFile.eof() && row > MAXWORLDROWS) 
	{
        cout << "ERROR: There are more than " << MAXWORLDROWS << " lines in the file" << endl;
        exit(1);
    }
	inFile.close();
}

void display(State world[][MAXCOLS])
{
	// TODO: write the display code

	for(int row = 1; row <= MAXWORLDROWS; row++)
	{
		for(int col = 1; col <= MAXWORLDCOLS; col++)
		{
			if(world[row][col] == State::alive)
			{
				cout << CELL;
			}
			else
			{
				cout << EMPTY;
			}
		}
		cout << endl;
	}
}

void initWorld(State world[][MAXCOLS])
{
	// TODO: write initWorld code

	for(int row = 0; row < MAXROWS; row++)
	{
		for(int col = 0; col < MAXCOLS; col++)
		{
			world[row][col] = State::dead;
		}
	}
}