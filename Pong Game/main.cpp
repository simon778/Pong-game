// Pong Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	GameManager g(40, 20);
	g.Run();
	return 0;
}


