#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
bool gameover;
const int width = 12;
const int height = 12;
int carX, carY;
int opX[4], opY[4];
int score;

void play()
{
	srand(time(0));
	gameover = false;
	carY = width / 2;
	carX = 10;
	for (int i = 0; i < rand() % 3 + 1; i++)
	{
		Sleep(500);
		opY[i] = rand() % 8 + 3;
		opX[i] = 0;
	}
}
void draw()
{

	system("cls");
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		cout << "#";
		for (int j = 0; j < width; j++)
		{
			if (j == carY && i == carX)
			{
				cout << "^";
			}
			else
			{
				bool obstaclePresent = false;
				for (int k = 0; k < 3; k++)
				{
					if (i == opX[k] && j == opY[k])
					{
						cout << "O";
						obstaclePresent = true;
						break;
					}
				}
				if (!obstaclePresent)
				{
					cout << "|";
				}
			}
		}
		cout << "#";
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "score: " << score;
}

void moment()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			carY--;
			break;
		case 's':
			carY++;
			break;
		case 'w':
			carX--;
			break;
		case 'x':
			carX++;
			break;
		}
	}
	Sleep(80);
	opX[0]++;
	opX[1]++;
	opX[2]++;
	srand(time(0));
	for (int i = 0; i < rand() % 3 + 3; i++)
		if (opX[i] == 12)
		{
			Sleep(300);
			opY[i] = rand() % 8 + 3;
			opX[i] = 0;
			score++;
		}
	for (int i = 0; i < 4; i++)
	{
		if (carX == opX[i] && carY == opY[i])
		{
			gameover = true;
		}
	}
}
int main()
{
	int key;
	cout << "\t\t\t\tCar Game!\n";
	cout << "Enter 1 to start game: ";
	cin >> key;
	if (key == 1)
	{
	again:
		play();
		while (!gameover)
		{
			moment();
			draw();
		}
	}
	if (gameover == true)
	{
		int k;
		cout << "\n\n1) wanted to play again\n";
		cout << "2) exit";
		cout << "\n\nEnter option: ";
		cin >> k;
		if (k == 1)
		{
			score = 0;
			gameover == false;
			goto again;
		}
	}
}
