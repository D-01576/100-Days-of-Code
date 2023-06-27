#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int k;
class Accountsmanager{
	private:
		int key;
		string platform,name,username,password,age,email;
	public:
		void homepage(void);
		void add(void);
		void manage(void);
			
};
void Accountsmanager::homepage(){
	Accountsmanager options;
	cout<<"\t\t\t\t\t\tAccounts manager";
	cout<<"\n\n1) Add new account";
	cout<<"\n2) Manage account";
	cout<<"\n3) Exit";
	cout<<"\n\nEnter the key from above options: ";
	cin>>key;
	if(key==2){
		options.add();
	}
	else if(key==1){
		options.manage();
	}
	else if(key==3){
	}
	else{
		system("cls");
		options.homepage();
	}
}
void Accountsmanager::add(){
	string data;
	cout<<"\n\nEnter platform name: ";
	cin>>platform;
	ifstream check("manager.txt");
	while(getline(check,data)){
		size_t pos = data.find(',');
		string storedplatform = data.substr(0,pos);
		data.erase(0,pos+1);
		
		pos = data.find(',');
		string storedname = data.substr(0,pos);
		data.erase(0,pos+1);
		
		pos = data.find(',');
		string storedusername = data.substr(0,pos);
		data.erase(0,pos+1);
		
		 pos = data.find(',');
		string storedpassword = data.substr(0,pos);
		data.erase(0,pos+1);
		
		 pos = data.find(',');
		string storedage = data.substr(0,pos);
		data.erase(0,pos+1);
		
		 pos = data.find(',');
		string storedemail = data.substr(0,pos);
		data.erase(0,pos+1);
		if(platform==storedplatform){
			check.close();
			cout<<"\n\n\t\t\t\t\t\t"<<platform<<" accounts detail:";
			cout<<"\nname: "<<storedname<<"\nuser name: "<<storedusername<<"\npassword: "<<storedpassword<<"\nage: "<<storedage<<"\nemail: "<<storedemail;
		}
	}
	again: 
	cout<<"\n\n1) Go back"<<"\n2) Exit";
	cout<<"\n\nEnter the key: ";
	cin>>k;
	if(k==1){
		system("cls");
		homepage();
	}
	else if(k==2){
		
	} 
	else{
		goto again;
	}
}
void Accountsmanager::manage(){
	cout<<"\n\nEnter platform name:";
	cin>>platform;
	cout<<"\nEnter your name: ";
	cin>>name;
	cout<<"\nEnter your username: ";
	cin>>username;
	cout<<"\nEnter new passowrd: ";
	cin>>password;
	cout<<"\nEnter your age: ";
	cin>>age;
	cout<<"\nEnter your email: ";
	cin>>email;
	ofstream add("manager.txt", ios::app);
	add<<platform<<","<<name<<","<<username<<","<<password<<","<<age<<","<<email<<"\n";
	add.close();
	cout<<"\nAccount successfully Added!";
	
	again: 
	cout<<"\n\n1) Go back"<<"\n2) Exit";
	cout<<"\n\nEnter the key: ";
	cin>>k;
	if(k==1){
		system("cls");
		homepage();
	}
	else if(k==2){
		
	} 
	else{
		goto again;
	}
}
int main(){
	Accountsmanager start;
	start.homepage();
}
