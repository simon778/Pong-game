#include "Ball.h"


void Ball::Reset() {
	x =originalX;
	y = originalY;
	direction = STOP;
}
void Ball::Move() {
	switch (direction) {
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UPLEFT:
		y--;  x--;
		break;
	case UPRIGHT:
		y--;  x++;
		break;
	case DOWNLEFT:
		y++;  x--;
		break;
	case DOWNRIGHT:
		y++;  x++;
		break;
	default:
		break;
	}
}

