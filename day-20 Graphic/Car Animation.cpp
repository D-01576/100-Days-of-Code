#include <graphics.h>
#include <iostream>
#include <conio.h>

void drawcar(int positionX, int positionY)
{
	setcolor(YELLOW);
	rectangle(positionX, positionY, positionX + 120, positionY + 50);

	setcolor(YELLOW);
	circle(positionX + 30, positionY + 50, 15);
	circle(positionX + 90, positionY + 50, 15);

	setcolor(WHITE);
	line(0, 400 + 200, 2000, 400 + 200);
}

int main()
{

	int positionX = 50;
	int positionY = 337 + 200;
	initwindow(1800, 1800);
	drawcar(positionX, positionY);
	while (positionX < 2200)
	{
		positionX += 1;
		cleardevice();
		drawcar(positionX, positionY);
		delay(5);
		if (positionX >= 1550)
		{
			positionX = -127;
		}
	}
	getch();
}
