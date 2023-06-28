#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class rps
{
public:
	void game();
};
void rps::game()
{
	srand(time(0));
	int random = rand() % 3 + 1;
	int choice;
	cout << "\t\t\t\t\t--------------------------------" << endl;
	cout << "\t\t\t\t\t[          R.P.S GAME          ]" << endl;
	cout << "\t\t\t\t\t--------------------------------" << endl;
	cout << "Select you chioce: ";
	cout << "\n1)rock\n2)paper\n3)scissors";
	cout << "\n\nEnter your choice: ";
	cin >> choice;
	if ((choice == 1 && random == 2) || (choice == 2 && random == 3) || (choice == 3 && random == 1))
	{
		if (random == 1)
		{
			cout << "Computer choice is rock\n";
		}
		else if (random == 2)
		{
			cout << "Computer choice is paper\n";
		}
		else
		{
			cout << "Computer choice is scissors\n";
		}
		cout << "You lose!";
	}
	else if (choice == random)
	{
		if (random == 1)
		{
			cout << "Computer choice is rock\n";
		}
		else if (random == 2)
		{
			cout << "Computer choice is paper\n";
		}
		else
		{
			cout << "Computer choice is scissors\n";
		}
		cout << "it's tie!";
	}
	else
	{
		if (random == 1)
		{
			cout << "Computer choice is rock\n";
		}
		else if (random == 2)
		{
			cout << "Computer choice is paper\n";
		}
		else
		{
			cout << "Computer choice is scissors\n";
		}
		cout << "You win!";
	}
	int key;
again:
	cout << "\n\n1) I want to play again";
	cout << "\n2) exit";
	cout << "\n\nEnter the key: ";
	cin >> key;
	if (key == 1)
	{
		system("clear");
		game();
	}
	else if (key == 2)
	{
	}
	else
	{
		goto again;
	}
}
int main()
{
	rps play;
	play.game();
}
