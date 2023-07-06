#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
        bool gameover;
        const int width=20;
		const int height=20;
		int fruitY;
		int fruitX;
		int x;
		int y;
		int tailX[100],tailY[100],nTail;
		int score;
		enum direction{STOP = 0,UP,DOWN,LEFT,RIGHT};
		direction dir;
class snack{
	public:
		void basic();
		void draw();
		void input();
		void logic();
};
void snack::basic(){
	gameover=false;
	dir=STOP;
	x = width / 2;
	y = height / 2;
	srand(time(0));
	fruitY = rand() % 15;
	fruitX = rand() % 15;
}
void snack::draw(){
	system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (j == fruitY && i == fruitX)
                cout << "F";
            else
            {
                bool printTail = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void snack::input(){
	if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
void snack::logic(){
	int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY= prev2Y;
    }
	

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if(y==fruitX && x==fruitY){
    	score +=1;
    	cout<<"scrore: "<<score;
    	fruitY = rand() % height;
     	fruitX = rand() % width;
     	nTail++;
	}
	else if(x==-2 || y==-2 || x==20 || y==20){
		gameover=true;
	}
}
int main(){
	snack play;
	play.basic();
    while (!gameover)
    {
        play.draw();
        play.input();
        play.logic();
        Sleep(10);
    }
    return 0;
}
