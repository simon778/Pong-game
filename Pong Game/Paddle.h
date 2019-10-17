#pragma once
#include <stdlib.h>
#include <iostream>

class Paddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	Paddle() ;
	Paddle(int x, int y) ;
	void Reset();
	int getX() { return x; }
	int getY() { return y; }
	void moveUp() { y--; }
	void moveDown() { y++; }
	friend std::ostream& operator<<(std::ostream& ost, Paddle c) {
		ost << "Paddle [" << c.x << ", " << c.y << "] " << std::endl;
		return ost;
	}
};

