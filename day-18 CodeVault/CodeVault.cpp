#include <iostream>
#include <fstream>
#include <string>

#define max 100
using namespace std;
struct Code{
	string title;
    string description;
    string language;
    string snippet;
};

Code codes[max];
int count = 0;
class CodeVault{
	public:
		void home();
		void store();
		void Retrieve();
		void List();
		void Delete();
		void readdata();
		void savedata();
};

void CodeVault::home(){
	cout<<"Welcome to CodeVault!";
	cout<<"\nChoose an action:";
	int choice;
	CodeVault opt;
	
		opt.readdata();
	
	do{
	cout<<"\n1) Store a code snippet";
	cout<<"\n2) Retrieve a code snippet";
	cout<<"\n3) List all stored code snippets";
	cout<<"\n4) Delete a code snippet";
	cout<<"\n0) Exit";
	cout<<"\n\nEnter the choice: ";
	cin>>choice;
	
	if(choice == 1){
		opt.store();
	}
	
	else if(choice == 2){
		opt.Retrieve();
	}
	
	else if(choice == 3){
		opt.List();
	}
	
	else if(choice == 4){
		opt.Delete();
	}
	
	else if(choice == 0){
		cout<<"Exiting CodeVault...\nyou for using CodeVault. Have a great day!";
	}
	else {
		cout<<"Invalid key\n";
	}
}while(choice != 0);
opt.savedata();
}

void CodeVault::store(){
	CodeVault add;
	Code newcode;
	cout<<"\nEnter the title of the code snippet: ";
	cin>>newcode.title;
	for(int i = 0; i <= count; i++){
		if(codes[i].title == newcode.title){
			cout<<"\nalready exist\n";
			return;
		}
	}
	cout<<"\nEnter a brief description: ";
	cin>>newcode.description;
	cout<<"\nEnter the programming language: ";
	cin>>newcode.language;
	cout<<"\nEnter the code snippet: ";
	cin>>newcode.snippet;
	codes[count] = newcode;
	count++;
	cout<<"\ncode snippet successfully stored\n";
}

void CodeVault::Delete(){
	string title;
	cout<<"\nEnter the title of the code snippet to delete: ";
	cin>>title;
	for (int i = 0; i < count; i++) {
        if (codes[i].title == title) {
            break;
        }
    }
    count--;
    cout<<"\nCode snippet "<< title <<"has been deleted successfully.\n";
}

void CodeVault::Retrieve(){
	string title;
    cout << "Enter the title of the code snippet to retrieve: ";
    cin >> title;

    int i;
    for (i = 0; i < count; i++)
    {
        if (codes[i].title == title)
        {
            cout << "\nTitle: " << codes[i].title << endl;
            cout << "Description: " << codes[i].description << endl;
            cout << "Language: " << codes[i].language  << endl;
            cout << "Code: " << codes[i].snippet << endl;
            return;
        }
    }
    cout << "\nAccount not found.\n" << endl;
}

void CodeVault::savedata(){
	ofstream file("snippet.txt");
    if (!file) {
        cout << "Error opening file for writing." << std::endl;
        return;
    }

    file << count << endl;

    for (int i = 0; i < count; i++) {
        file << codes[i].title << "," << codes[i].description << "," << codes[i].language << "," << codes[i].snippet << "," << endl;
    }

    file.close();
}

void CodeVault::readdata(){
	ifstream read("snippet.txt");
	
	read >> count;
	read.ignore();
	for(int i = 0; i < count; i++){
		getline(read, codes[i].title, ',');
		getline(read, codes[i].description, ',');
		getline(read, codes[i].language, ',');
		getline(read, codes[i].snippet, ',');
	}
	read.close();
}
void CodeVault::List(){
	cout<<"\nHere is list stored code snippets\n\n";
	for(int i = 0; i < count;i++){
		cout<<i + 1<<". "<<codes[i].title<<"\n";
	}
	cout<<"\n\n";
	
}
int main(){
	CodeVault start;
	start.home();
}
