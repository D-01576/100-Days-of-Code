#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
class login{
	private:
		int key;
		string name,username,password,age,email;
		string checkusername,checkpassword;
	public:
		void homepage(void);
		void loginform(void);
		void registratinform(void);
//		void forgotform(void);
			
};
		int k;
void login::homepage(){
	login options;
	cout<<"\t\t\t\t\tRegisteration system";
	cout<<"\n\n1) login";
	cout<<"\n2) register";
	cout<<"\n3) Exit";
	cout<<"\n\nEnter the key from above options: ";
	cin>>key;
	if(key==1){
		options.loginform();
	}
	else if(key==2){
		options.registratinform();
	}
	else if(key==3){
	}
	else{
		system("cls");
		options.homepage();
	}
}
void login::loginform(){
	string data;
	cout<<"\n\nEnter your username: ";
	cin>>checkusername;
	cout<<"\nEnter your password: ";
	cin>>checkpassword;
	ifstream check("reg_user.txt");
	while(getline(check,data)){
		size_t pos = data.find(',');
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
		if(checkusername == storedusername && checkpassword == storedpassword){
			check.close();
			
			cout<<"\nsuccessfully login!";
			cout<<"\n\nyour account detail are:";
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
void login::registratinform(){
	cout<<"\n\nEnter your name: ";
	cin>>name;
	cout<<"\nEnter your username: ";
	cin>>username;
	cout<<"\nEnter new passowrd: ";
	cin>>password;
	cout<<"\nEnter your age: ";
	cin>>age;
	cout<<"\nEnter your email: ";
	cin>>email;
	ofstream add("reg_user.txt", ios::app);
	add<<name<<","<<username<<","<<password<<","<<age<<","<<email<<"\n";
	add.close();
	cout<<"\nAccount successfully created!";
	
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
//void login::forgotform(){
//	string modify,usernam;
//	cout<<"\n\nEnter your username: ";
//	cin>>usernam;
//	ofstream input("hhhhhh.txt",ios::app);
//	ifstream output("reg_user.txt");
//	while(getline(output,modify)){
//		size_t pos = modify.find(',');
//		string storedname = modify.substr(0,pos);
//		modify.erase(0,pos+1);
//		
//		 pos = modify.find(',');
//		string storedusername = modify.substr(0,pos);
//		modify.erase(0,pos+1);
//		
//		 pos = modify.find(',');
//		string storedpassword = modify.substr(0,pos);
//		modify.erase(0,pos+1);
//		
//		 pos = modify.find(',');
//		string storedage = modify.substr(0,pos);
//		modify.erase(0,pos+1);
//		
//		 pos = modify.find(',');
//		string storedemail = modify.substr(0,pos);
//		modify.erase(0,pos+1);
//		if(usernam == storedusername){
//			output.close();
//		    string newpassword;
//		    cout<<"\nEnter new password: ";
//			cin>>newpassword;
//			storedpassword=newpassword;
//			input<<storedname<<","<<storedusername<<","<<storedpassword<<","<<storedage<<","<<storedemail<<"\n";
//		}
//		else{
//		input<< modify << '\n';
//	}
//	}
//	input.close();
//	remove("reg_user.txt");
//    rename("hhhhhh.txt", "reg_user.txt");
//	again: 
//	cout<<"\n\n1) Go back"<<"\n2) Exit";
//	cout<<"\n\nEnter the key: ";
//	cin>>k;
//	if(k==1){
//		system("cls");
//		homepage();
//	}
//	else if(k==2){
//		
//	} 
//	else{
//		goto again;
//	}
//}
int main(){
	login start;
	start.homepage();
}
