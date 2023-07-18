#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	string word;
	vector<string> wordlist;
	string words;
	ifstream file("list.txt");
	while (getline(file, words))
	{
		wordlist.push_back(words);
	};
	file.close();
	string text;
	string check;
	cout << "Enter: ";
	cin >> text;
	for (int i = text.length() - 1; i >= 0; i--)
	{
		check += text[i];
	}

	for (int i = 0; i < wordlist.size(); i++)
	{
		if (wordlist[i] == check)
		{
			cout << check << " is the pallindrome of " << text;
			exit(0);
		}
	}
	cout << "The word " << text << " is not a palindrome, ";
	cout << "if we reverse the order of its characters, we get " << check;
	cout << " which is not the same as the original word.";
}
