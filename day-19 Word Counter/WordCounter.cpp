#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string text;
	string word;
	int count = 0;
	cout << "Enter text: ";
	getline(cin, text);
	istringstream words(text);
	while (words >> word)
	{
		count++;
	}
	cout << "\nTotal word: " << count;
}
