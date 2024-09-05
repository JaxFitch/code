//Main.cpp
//Author: Jackson Fitch

#include <iostream>
using namespace std;

enum class Direction {NORTH, EAST, SOUTH, WEST};

int main()
{
	Direction x, y;
	y = x;

	PrintDirection(x);

	return 0;
}

Direction RightFrom(Direction z)
{
    return (Direction)((int)z + 1);
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