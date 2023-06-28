#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameover;
char currentplayer = 'X';
char tic[3][3];
void play()
{
	gameover = false;
}
void draw()
{
	system("cls");
	cout << "\t\t\t " << tic[0][0] << " | " << tic[1][0] << " | " << tic[2][0] << "\n";
	cout << "\t\t\t---|---|---\n";
	cout << "\t\t\t " << tic[0][1] << " | " << tic[1][1] << " | " << tic[2][1] << "\n";
	cout << "\t\t\t---|---|---\n";
	cout << "\t\t\t " << tic[0][2] << " | " << tic[1][2] << " | " << tic[2][2] << "\n";
}
void check()
{
	for (int i = 0; i < 3; ++i)
	{
		if (tic[i][0] == currentplayer && tic[i][1] == currentplayer && tic[i][2] == currentplayer)
		{
			gameover = true;
			cout << currentplayer << " won!";
		}
		else if (tic[0][i] == currentplayer && tic[1][i] == currentplayer && tic[2][i] == currentplayer)
		{
			gameover = true;
			cout << currentplayer << " won!";
		}
	}
	if (tic[0][0] == currentplayer && tic[1][1] == currentplayer && tic[2][2] == currentplayer)
	{
		gameover = true;
		cout << currentplayer << " won!";
	}
	else if (tic[2][0] == currentplayer && tic[1][1] == currentplayer && tic[0][2] == currentplayer)
	{
		gameover = true;
		cout << currentplayer << " won!";
	}
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'q':
			tic[0][0] = currentplayer;
			break;
		case 'a':
			tic[0][1] = currentplayer;
			break;
		case 'z':
			tic[0][2] = currentplayer;
			break;
		case 'w':
			tic[1][0] = currentplayer;
			break;
		case 's':
			tic[1][1] = currentplayer;
			break;
		case 'x':
			tic[1][2] = currentplayer;
			break;
		case 'e':
			tic[2][0] = currentplayer;
			break;
		case 'd':
			tic[2][1] = currentplayer;
			break;
		case 'c':
			tic[2][2] = currentplayer;
			break;
		default:
			gameover = false;
		}
		currentplayer = (currentplayer == 'X') ? 'O' : 'X';
		check();
	}
}
int main()
{
	play();
	while (!gameover)
	{
		draw();
		input();
		Sleep(10);
	}
	return 0;
}
