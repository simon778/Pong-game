#pragma once
#include "eDir.h"
#include <stdlib.h>
#include <iostream>



class Ball
{
private:
	int x, y; // position of the ball
	int originalX, originalY;
	eDir direction;
public:
	Ball(int posX, int posY):originalX(posX),originalY(posY), x(posX), y(posY) {
		direction = STOP;
	}
	void Reset() ;
	void changeDirection(eDir d) {
		direction = d;
	}
	void randomDirection() {
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() {return x;	}
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	void Move() ;
	
	friend std::ostream & operator<<(std::ostream & ost, Ball c) {
		ost << "Ball [" << c.x << ", " << c.y << "] ["<< c.direction << "]" << std::endl ;
		return ost;
	}

};



