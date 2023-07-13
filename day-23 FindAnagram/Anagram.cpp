#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> FindAnagram(string word, vector<string> wordlist)
{
	vector<string> list = wordlist;
	vector<string> anagrams;
	string w = word;
	sort(w.begin(), w.end());

	for (int i = 0; i < list.size(); i++)
	{
		string a = list[i];
		sort(a.begin(), a.end());
		if (a == w)
		{
			anagrams.push_back(list[i]);
		}
	}
	return anagrams;
}
int main()
{
again:
	string word;
	vector<string> wordlist;
	string words;
	ifstream file("list.txt");
	while (getline(file, words))
	{
		wordlist.push_back(words);
	};
	file.close();
	cout << "Enter word: ";
	cin >> word;
	vector<string> anagrams = FindAnagram(word, wordlist);
	if (anagrams.size() == 0)
	{
		cout << "No Anagram Find For " << word;
	}
	else
	{
		cout << "\nAnagrams for " << word << " given below: \n";
		for (int i = 0; i < anagrams.size(); i++)
		{
			cout << anagrams[i] << endl;
		}
	}
	int key;
	cout << "\n\n1) Wanted to anagram again: ";
	cout << "\n2)Exit: ";
	cout << "\n\enetr option: ";
	cin >> key;
	if (key == 1)
	{
		system("cls");
		goto again;
	}
	else
	{
	}
}
