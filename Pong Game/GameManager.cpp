#include "GameManager.h"
void GameManager::Draw() {

	system("cls"); // clear screen
	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int ballx = ball->getX();
			int bally = ball->getY();
			int player1x = player1->getX();
			int player1y = player1->getY();
			int player2x = player2->getX();
			int player2y = player2->getY();
			if (j == 0)
				cout << "\xB2"; // print the wall , top
	
			if (ballx == j && bally == i && end==false)
				cout << "0"; // ball
			else if (player1x == j && player1y == i)
				cout << "\xDB"; // player1
			else if (player1x == j && player1y + 1 == i)
				cout << "\xDB"; // player1
			else if (player1x == j && player1y + 2 == i)
				cout << "\xDB"; // player1
			else if (player1x == j && player1y + 3 == i)
				cout << "\xDB"; // player1

			else if (player2x == j && i != height / 2 && i != height / 2 + 1 && player2y == i && end==true)
				cout << "\xDB"; //player2
			else if (player2x == j && i != height / 2 && i != height / 2 + 1 &&  player2y + 1 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x == j && i != height / 2 && i != height / 2 + 1 && player2y + 2 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x == j && i != height / 2 && i != height / 2 + 1 &&  player2y + 3 == i && end == true)
				cout << "\xDB"; // player2

			else if (player2x  -12 == j && i == height / 2  && player2y == i && end == true)
				cout << "\xDB"; //player2
			else if (player2x -9 == j && i == height / 2 + 1 && player2y == i && end == true)
				cout << "\xDB"; //player2
			else if (player2x - 12 == j && i == height / 2  && player2y + 1 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x - 9 == j && i == height / 2 + 1 && player2y + 1 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x - 12 == j && i == height / 2  && player2y + 2 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x - 9 == j && i == height / 2 + 1 && player2y + 2 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x - 12 == j && i == height / 2 && player2y + 3 == i && end == true)
				cout << "\xDB"; // player2
			else if (player2x - 9 == j && i == height / 2 + 1 && player2y + 3 == i && end == true)
				cout << "\xDB"; // player2

			else if (player2x == j && player2y == i && end == false)
				cout << "\xDB"; //player2
			else if (player2x == j && player2y + 1 == i && end == false)
				cout << "\xDB"; // player2
			else if (player2x == j && player2y + 2 == i && end == false)
				cout << "\xDB"; // player2
			else if (player2x == j && player2y + 3 == i && end == false)
				cout << "\xDB"; // player2


			else if (j == width / 2 -6 && i == height / 2  && end == true && score1> score2) 
				cout << "Player 1 is winner!"; // player1 won

			else if (j == width / 2 -6 && i == height / 2  && end == true && score2 > score1)
				cout << "Player 2 is winner!"; // player2 won

			else if (j == width / 2 - 5 && i == height / 2 + 1 && end == true)
				cout << "q to quit!"; // q to quit

			else cout << " ";

			if (j == width - 13 && i == height / 2 && end == true) // print the wall
				cout << "\xB2";		
			else if(j == width - 10 && i == height / 2  + 1 && end == true)
				cout << "\xB2";
			else if (j == width - 1 && i != height / 2 && i != height / 2 + 1 && end == true)
				cout << "\xB2";
			else if (j == width - 1 && end == false)
				cout << "\xB2";



		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";

	cout << endl;
	cout << "Player 1: up w " << "down s" << endl;
	cout << "Player 2: up i " << "down k" << endl;
	cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
}

void GameManager::Input() {

	ball->Move();

	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player1y = player1->getY();
	int player2x = player2->getX();
	int player2y = player2->getY();

	if (_kbhit()) { // if keyboard is pressed
		char current;
		current = _getch();
		if (current == up1)
			if (player1y > 0)
				player1->moveUp();
		if (current == up2)
			if (player2y > 0)
				player2->moveUp();
		if (current == down1)
			if (player1y + 4 < height)
				player1->moveDown();
		if (current == down2)
			if (player2y + 4 < height)
				player2->moveDown();
		if (ball->getDirection() == STOP)
			ball->randomDirection();
		if (current == 'q')
			quit = true;
	}
}

void GameManager::Logic() {
	int ballx = ball->getX();
	int bally = ball->getY();
	int player1x = player1->getX();
	int player1y = player1->getY();
	int player2x = player2->getX();
	int player2y = player2->getY();

	//left paddle
	for (int i = 0; i < 4; i++) {
		if (ballx == player1x + 1)
			if (bally == player1y + i)
				ball->changeDirection((eDir)((rand() % 3) + 4));
	}

	//right paddle
	for (int i = 0; i < 4; i++) {
		if (ballx == player2x - 1)
			if (bally == player2y + i)
				ball->changeDirection((eDir)((rand() % 3) + 1));
	}
	//bottom wall
	if (bally == height - 1)
		ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
	//top wall
	if (bally == 0)
		ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
	//right wall
	if (ballx == width - 1)
		ScoreUp(player1);
	//left wall
	if (ballx == 0)
		ScoreUp(player2);
	if (score1 >= 10 || score2 >= 10) {
		ball->changeDirection(STOP);
		end = true;
	}

}

void GameManager::ScoreUp(Paddle* player) {
	if (player == player1)
		score1++;
	else if (player == player2)
		score2++;
	ball->Reset();
	player1->Reset();
	player2->Reset();
}

GameManager::GameManager(int w, int h) {
	srand(time(NULL));
	quit = false;
	end = false;
	up1 = 'w'; up2 = 'i';
	down1 = 's'; down2 = 'k';
	score1 = 0; score2 = 0;
	width = w; height = h;
	ball = new Ball(w / 2, h / 2);
	player1 = new Paddle(1, h / 2 - 3);
	player2 = new Paddle(w - 2, h / 2 - 3);
}
GameManager::~GameManager() {
	delete ball, player1, player2;
}