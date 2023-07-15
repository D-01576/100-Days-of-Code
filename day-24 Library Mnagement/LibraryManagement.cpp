#include <iostream>
#include <fstream>
#include <string>
#define max 100
#define m 100
using namespace std;
struct books{
	string title;
	string author;
	int serialno;
	int quantity;
};

struct borrow{
	string name;
	string email;
	int id;
};

books Book[max];
borrow borrows[m];
int count = 0;
int borrowCount = 0 ;
class library{
	public:
		void bookback();
		void reportback();
		void borrowerback();
		void transationback();
		void home();
		void book();
		void addbook();
		void searchbook();
		void updatebook();
		void removebook();
		void borrower();
		void addborrower();
		void searchborrower();
		void updateborrower();
		void removeborrower();
		void transation();
		void checkout();
		void returnbook();
		void report();
		void listallbook();
		void listborrowedbook();
		void savebooks();
		void readbooks();
		void saveborrowers();
		void readborrower();
};
void library::home(){
	int key;
	library lib;
	lib.readbooks();
	lib.readborrower();
	again:
	cout<<"Welcome to the Library Management System!";
	cout<<"\nPlease select an option:";
	cout<<"\n1. Book Management";
	cout<<"\n2. Borrower Management";
	cout<<"\n3. Transaction Management";
	cout<<"\n4. Reports";
	cout<<"\n5. Exit";
	cout<<"\nEnter your choice: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.book();
	}
	else if(key == 2){
		system("cls");
		lib.borrower();
	}
	else if(key == 3){
		system("cls");
		lib.transation();
	}
	else if(key == 4){
		system("cls");
		lib.report();
	}
	else if(key == 5){
		
	}
	else{
		system("cls");
		goto again;
	}
	lib.savebooks();
	lib.saveborrowers();
}

void library::book(){
	int key;
	library lib;
	again:
	cout<<"Book Management System!";
	cout<<"\nPlease select an option:";
	cout<<"\n1. Add Book";
	cout<<"\n2. Search Book";
	cout<<"\n3. Update Book";
	cout<<"\n4. Remove Book";
	cout<<"\n5. Go Back";
	cout<<"\n6. Exit";
	cout<<"\nEnter your choice: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.addbook();
		lib.savebooks();
		lib.bookback();
	}
	else if(key == 2){
		system("cls");
		lib.searchbook();
		lib.savebooks();
		lib.bookback();
	}
	else if(key == 3){
		system("cls");
		lib.updatebook();
		lib.savebooks();
		lib.bookback();
	}
	else if(key == 4){
		system("cls");
		lib.removebook();
		lib.savebooks();
		lib.bookback();
	}
	else if(key == 5){
		system("cls");
		lib.home();
	}
	else if(key == 6){
		
	}
	else{
		system("cls");
		goto again;
	}
}

void library::addbook(){
	library lib;
	books newbook;
	cout<<"Adding a New Book:";
	cout<<"\nEnter Title: ";
	cin>>newbook.title;
	for(int i = 0; i <= count; i++){
		if(Book[i].title == newbook.title){
			cout<<"\nBook already exist\n";
			return;
		}
	}
	cout<<"\nEnter Author: ";
	cin>>newbook.author;
	cout<<"\nEnter serial No: ";
	cin>>newbook.serialno;
	cout<<"\nEnter item quantity: ";
	cin>>newbook.quantity;
	Book[count] = newbook;
	count++;
	cout<<"\nBook succesfully added\n";
}

void library::searchbook(){
	library lib;
	string title;
	cout<<"Searching for a Book:";
    cout << "\nEnter search keyword:";
    cin >> title;

    int i;
    for (i = 0; i < count; i++)
    {
        if (Book[i].title == title)
        {
        	cout <<"\nFound book:";
            cout << "\nTitle: " << Book[i].title << endl;
            cout << "Author: " << Book[i].author << endl;
            cout << "Serial No: " << Book[i].serialno  << endl;
            cout << "Quantity: " << Book[i].quantity << endl;
            return;
        }
    }
    cout<<"Book Not Found!";
}

void library::updatebook(){
	int serialNo;
	cout<<"Updating a Book:";
	cout<<"Enter Book serial Number: ";
	cin>> serialNo;
	for(int i = 0 ; i < count; i++){
		if(Book[i].serialno == serialNo){
			int quantity;
			cout<<"Enter new quantity: ";
			cin>> quantity;
			Book[i].quantity = quantity;
			cout<<"\nBook details updated successfully!";
			return;
		}
	}
	cout<<"Book No is not exist";
}

void library::removebook(){
	int serialNo;
	cout<<"Removing a Book:";
	cout<<"Enter Book serial Number: ";
	cin>> serialNo;
	for(int i = 0 ; i < count; i++){
		if(Book[i].serialno == serialNo){
			count--;
			cout<<"Book Successfully removed";
			break;
		}
	}
}

void library::borrower(){
	int key;
	library lib;
	again:
	cout<<"Borrower Management System!";
	cout<<"\nPlease select an option:";
	cout<<"\n1. Add Borrower";
	cout<<"\n2. Search Borrower";
	cout<<"\n3. Update Borrower";
	cout<<"\n4. Remove Borrower";
	cout<<"\n5. Go Back";
	cout<<"\n6. Exit";
	cout<<"\nEnter your choice: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.addborrower();
		lib.saveborrowers();
		lib.borrowerback();
	}
	else if(key == 2){
		system("cls");
		lib.searchborrower();
		lib.saveborrowers();
		lib.borrowerback();
	}
	else if(key == 3){
		system("cls");
		lib.updateborrower();
		lib.saveborrowers();
		lib.borrowerback();
	}
	else if(key == 4){
		system("cls");
		lib.removeborrower();
		lib.saveborrowers();
		lib.borrowerback();
	}
	else if(key == 5){
		system("cls");
		lib.home();
	}
	else if(key == 6){
		
	}
	else{
		system("cls");
		goto again;
	}
	
}

void library::addborrower(){
	library lib;
	borrow newborrow;
	cout<<"Adding a New Borrower:";
	cout<<"\nEnter name: ";
	cin>>newborrow.name;
	cout<<"\nEnter Email: ";
	cin>>newborrow.email;
	cout<<"\nEnter New id NO: ";
	cin>>newborrow.id;
	borrows[borrowCount] = newborrow;
	borrowCount++;
	cout<<"\nBorrower succesfully added\n";
}

void library::searchborrower(){
	int id;
	cout<<"Searching for a Borrowers:";
    cout << "\nEnter Borrowe id No: ";
    cin >> id;

    int i;
    for (i = 0; i < borrowCount; i++)
    {
        if (borrows[i].id == id)
        {
        	cout <<"\nFound borrower:";
            cout << "\nName: " << borrows[i].name << endl;
            cout << "Email: " << borrows[i].email << endl;
            cout << "Id: " << borrows[i].id  << endl;
            return;
        }
    }
    cout<<"Borrowers Not Found!";
}

void library::updateborrower(){
	int id;
	cout<<"Updating a Borrowers:";
	cout<<"Enter Borrower Id: ";
	cin>> id;
	for(int i = 0 ; i < borrowCount; i++){
		if(borrows[i].id == id){
			string email;
			cout<<"Enter new Email: ";
			cin>> email;
			borrows[i].email = email;
			cout<<"\nBorrower details updated successfully!";
			return;
		}
	}
	cout<<"Borrower id is not exist";
}

void library::removeborrower(){
	int id;
	cout<<"Removing a Borrowers:";
	cout<<"Enter Borrower id: ";
	cin>> id;
	for(int i = 0 ; i < borrowCount; i++){
		if(borrows[i].id = id){
			break;
		}
	}
	count--;
    cout<<"Borrower Successfully removed";
}

void library::transation(){
	int key;
	library lib;
	again:
	cout<<"Transaction Management System!";
	cout<<"\nPlease select an option:";
	cout<<"\n1. Check out book";
	cout<<"\n2. Return Book";
	cout<<"\n3. Go Back";
	cout<<"\n4. Exit";
	cout<<"\nEnter your choice: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.checkout();
		lib.transationback();
	}
	else if(key == 2){
		system("cls");
		lib.returnbook();
		lib.transationback();
	}
	else if(key == 3){
		system("cls");
		lib.home();
	}
	else if(key == 4){
		
	}
	else{
		system("cls");
		goto again;
	}
}

void library::checkout(){
	int id;
	int serialno;
	cout<<"Checking Out a Book:";
	cout<<"Enetr Borrower id Number: ";
	cin>>id;
	for(int i = 0; i < borrowCount; i++){
		if(borrows[i].id == id){
			cout<<"Enter Books serial NO:";
			cin>>serialno;
			for(int j = 0; j < count; j++){
				if(Book[j].serialno == serialno){
					if(Book[j].quantity > 0){
					int a = Book[j].quantity;
					Book[j].quantity = a - 1;
					cout<<"\nBook checked out successfully!";
				    }
				    else{
				    	cout<<"\nThe book has sold out";
					}
					return;
				}
			}
		}
	}
	cout<<"Borrower id or book serial no incorrect";
}

void library::returnbook(){
	int id;
	int serialno;
	cout<<"Checking Out a Book:";
	cout<<"Enetr Borrower id Number: ";
	cin>>id;
	for(int i = 0; i < borrowCount; i++){
		if(borrows[i].id == id){
			cout<<"Enter Books serial NO:";
			cin>>serialno;
			for(int j = 0; j < count; j++){
				if(Book[j].serialno == serialno){
					int a = Book[j].quantity;
					Book[j].quantity = a + 1;
					cout<<"\nBook Returned successfully!";
					return;
				}
			}
		}
	}
	cout<<"Borrower id or book serial no incorrect";
}

void library::report(){
	int key;
	library lib;
	again:
	cout<<"Report Management System!";
	cout<<"\nPlease select an option:";
	cout<<"\n1. List of Books";
	cout<<"\n2. List of Borrowers";
	cout<<"\n3. Go Back";
	cout<<"\n4. Exit";
	cout<<"\nEnter your choice: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.listallbook();
		lib.reportback();
	}
	else if(key == 2){
		system("cls");
		lib.listborrowedbook();
		lib.reportback();
	}
	else if(key == 3){
		system("cls");
		lib.home();
	}
	else if(key == 4){
		
	}
	else{
		system("cls");
		goto again;
	}
}

void library::listallbook(){
	cout<<"All Books:\n";
	for(int i = 0; i < count; i++){
		cout << " - " << "Title: " << Book[i].title << "\n   Author:" << Book[i].author << "\n   Serial NO: " << Book[i].serialno << "\n   Quantity: " << Book[i].quantity << endl;
	}
}

void library::listborrowedbook(){
	cout<<"All Borrowers:\n";
	for(int i = 0; i < borrowCount; i++){
		cout << " - " << "Name: " << borrows[i].name << "\n   Email:" << borrows[i].email << "\n   Id No: " << borrows[i].id << endl;
	}
}

void library::savebooks(){
	ofstream save;
	save.open("Books.txt");
	save<<count<<endl;
	for(int i = 0; i < count; i++){
		save << Book[i].title << "," << Book[i].author << "," << Book[i].serialno << "," << Book[i].quantity << endl; 
	}
	save.close();
}

void library::readbooks(){
	ifstream read;
	read.open("Books.txt");
	read>>count;
	read.ignore();
	for(int i = 0 ; i < count; i++){
		getline(read, Book[i].title , ',');
		getline(read, Book[i].author , ',');
		read>>Book[i].serialno;
		read.ignore();
		read>>Book[i].quantity;
		read.ignore();
	}
	read.close();
}

void library::saveborrowers(){
	ofstream save;
	save.open("Borrowers.txt");
	save<<borrowCount<<endl;
	for(int i = 0; i < borrowCount; i++){
		save << borrows[i].name << "," << borrows[i].email << "," << borrows[i].id << endl; 
	}
	save.close();
}

void library::readborrower(){
	ifstream read;
	read.open("Borrowers.txt");
	read>>borrowCount;
	read.ignore();
	for(int i = 0 ; i < borrowCount; i++){
		getline(read, borrows[i].name , ',');
		getline(read, borrows[i].email , ',');
		read>>borrows[i].id;
		read.ignore();
	}
	read.close();
}

void library::bookback(){
	library lib;
	int key;
	cout<<"\n\n1)Go back";
	cout<<"\n2) Exit";
	again:
	cout<<"\nEnter option: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.book();
	}
	else if(key == 2){
		
	}
	else{
		goto again;
	}
}

void library::borrowerback(){
	library lib;
	int key;
	cout<<"\n\n1)Go back";
	cout<<"\n2) Exit";
	again:
	cout<<"\nEnter option: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.borrower();
	}
	else if(key == 2){
		
	}
	else{
		goto again;
	}
}

void library::transationback(){
	library lib;
	int key;
	cout<<"\n\n1)Go back";
	cout<<"\n2) Exit";
	again:
	cout<<"\nEnter option: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.transation();
	}
	else if(key == 2){
		
	}
	else{
		goto again;
	}
}

void library::reportback(){
	library lib;
	int key;
	cout<<"\n\n1)Go back";
	cout<<"\n2) Exit";
	again:
	cout<<"\nEnter option: ";
	cin>>key;
	if(key == 1){
		system("cls");
		lib.report();
	}
	else if(key == 2){
		
	}
	else{
		goto again;
	}
}
int main(){
	library lib;
	lib.home();
}
