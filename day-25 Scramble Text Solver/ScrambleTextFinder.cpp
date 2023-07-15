#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void FindScrambleText(const string &letters, const vector<string> &wordlist)
{
    vector<string> words;

    for (vector<string>::size_type i = 0; i < wordlist.size(); ++i)
    {
        const string &word = wordlist[i];
        if (word.length() >= 2 && word.length() <= 7)
        {
            string temp = letters;
            bool isScramble = true;
            for (string::size_type j = 0; j < word.length(); ++j)
            {
                string::size_type pos = temp.find(word[j]);
                if (pos == string::npos)
                {
                    isScramble = false;
                    break;
                }
                else
                {
                    temp.erase(pos, 1);
                }
            }
            if (isScramble)
            {
                words.push_back(word);
            }
        }
    }

    if (words.empty())
    {
        cout << "No words can be formed using the provided letters." << endl;
    }
    else
    {
        cout << "Matching words: ";
        for (vector<string>::size_type i = 0; i < words.size(); ++i)
        {
            const string &word = words[i];
            cout << word << endl;
        }
        cout << endl;
    }
}

int main()
{
    string letters;
    cout << "Enter the letters: ";
    cin >> letters;

    vector<string> wordlist;
    string words;
    ifstream file("list.txt");
    while (getline(file, words))
    {
        wordlist.push_back(words);
    };
    file.close();

    FindScrambleText(letters, wordlist);

    return 0;
}
