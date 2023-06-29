#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	cout << "\t\t\t\t\t\tPassword generator";
	string characters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890!@#$%^&*";
	string password = "";
	int length;
	cout << "Enter length: ";
	cin >> length;
	srand(time(0));
	for (int i = 0; i < length; ++i)
	{
		int randomIndex = rand() % characters.length();
		password += characters[randomIndex];
	}
	cout << "password: " << password;
}
