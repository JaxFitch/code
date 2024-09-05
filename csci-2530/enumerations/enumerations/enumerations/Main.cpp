//Main.cpp
//Author: Jackson Fitch

#include <iostream>
using namespace std;

enum class Direction {NORTH, EAST, SOUTH, WEST};

Direction RightFrom(Direction z);
void PrintDirection(Direction z);

int main()
{
	Direction x, y;

	x = Direction::WEST;
	y = x;

	printf("Starting direction: ");
	PrintDirection(x);
    printf("\n");

	y = RightFrom(x);
	printf("Right from starting direction: ");
	PrintDirection(y);
    printf("\n");

	return 0;
}

Direction RightFrom(Direction z)
{
    return (Direction)(((int)z + 1) % 4);
}

void PrintDirection(Direction z)
{
    switch(z)
    {
        case Direction::NORTH:
            printf("North");
            break;
        case Direction::EAST:
            printf("East");
            break;
        case Direction::SOUTH:
            printf("South");
            break;
        case Direction::WEST:
            printf("West");
            break;
    }
}