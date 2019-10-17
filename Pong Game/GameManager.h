#pragma once
#include <iostream>
#include <time.h>
#include "Ball.h"
#include "Paddle.h"
#include "conio.h"
#include <windows.h>

using namespace std;

class GameManager
{

private: 
	int width, height;
	int score1, score2;
	eDir direction;
	char up1, down1, up2, down2;
	bool quit;
	bool end;
	Ball* ball;
	Paddle* player1;
	Paddle* player2;
public:
	GameManager(int w, int h);

	~GameManager();

	void ScoreUp(Paddle* player);

	void Draw();
	
	void Input();

	void Logic();

	void Run()
	{
		while (!quit)
		{
			Draw();
			Input();
			Logic();
			Sleep(25);
		}
	}

};

