#include <iostream>
#include <vector>
using namespace std;
struct quiz
{
	string question;
	string options;
	int key;
};
int main()
{
	int ke;
	int mark = 0;
	quiz quiz1;

	quiz1.question = "Identify the correct extension of the user-defined header file in C++.\n";
	quiz1.options = "1) .cpp\n2) .hg\n3) .html\n";
	quiz1.key = 1;

	cout << quiz1.question;
	cout << quiz1.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz1.key == ke)
	{
		mark++;
	}
	quiz quiz2;

	quiz2.question = "Which of the following data type is supported in C++ but not in C?\n";
	quiz2.options = "1) int\n2) bool\n3) float\n";
	quiz2.key = 2;

	cout << quiz2.question;
	cout << quiz2.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz2.key == ke)
	{
		mark++;
	}
	quiz quiz3;

	quiz3.question = "Identify the correct syntax for declaring arrays in C++.\n";
	quiz3.options = "1) int[10]\n2) int ar[10]\n3) array ar[10]\n";
	quiz3.key = 2;

	cout << quiz3.question;
	cout << quiz3.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz3.key == ke)
	{
		mark++;
	}
	quiz quiz4;

	quiz4.question = "Size of wchat_t is.\n";
	quiz4.options = "1) .cpp\n2) 2\n3) depends on the number of bits in the system\n";
	quiz4.key = 3;

	cout << quiz4.question;
	cout << quiz4.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz4.key == ke)
	{
		mark++;
	}
	quiz quiz5;

	quiz5.question = "Which of the following is �address of operator�?.\n";
	quiz5.options = "1) []\n2) &\n3) *\n";
	quiz5.key = 2;

	cout << quiz5.question;
	cout << quiz5.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz5.key == ke)
	{
		mark++;
	}
	quiz quiz6;

	quiz6.question = "Which of the following loops is best when we know the number of iterations?\n";
	quiz6.options = "1) for loop\n2) while loop\n3) do while\n";
	quiz6.key = 1;

	cout << quiz6.question;
	cout << quiz6.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz6.key == ke)
	{
		mark++;
	}
	quiz quiz7;

	quiz7.question = "Identify the scope resolution operator.\n";
	quiz7.options = "1) =\n2) :\n3) ::\n";
	quiz7.key = 3;

	cout << quiz7.question;
	cout << quiz7.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz7.key == ke)
	{
		mark++;
	}
	quiz quiz8;

	quiz8.question = "Choose the correct default return value of function.\n";
	quiz8.options = "1) int\n2) char\n3) float\n";
	quiz8.key = 1;

	cout << quiz8.question;
	cout << quiz8.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz8.key == ke)
	{
		mark++;
	}
	quiz quiz9;

	quiz9.question = "Using which of the following data type can 19.54 be represented?";
	quiz9.options = "1) float\n2) char\n3) int\n";
	quiz9.key = 1;

	cout << quiz9.question;
	cout << quiz9.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz9.key == ke)
	{
		mark++;
	}
	quiz quiz10;

	quiz10.question = "Identify the correct function from which the execution of C++ program starts?\n";
	quiz10.options = "1) start()\n2) main()\n3) new()\n";
	quiz10.key = 2;

	cout << quiz10.question;
	cout << quiz10.options;
	cout << "\nEnter the option : ";
	cin >> ke;
	if (quiz10.key == ke)
	{
		mark++;
	}
	cout << "\nscore" << mark;
	cout << "\npercentage: " << (mark * 100) / 10;
}
