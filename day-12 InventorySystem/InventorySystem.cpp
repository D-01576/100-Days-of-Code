#include <iostream>
#include <fstream>
#include <string>

#define max 100
using namespace std;
struct item{
	int id;
    string name;
    string description;
    int quantity;
    double price;	
};

item items[max];
int count = 0;
class inventry{
	public:
		void login();
		void home();
		void add();
		void remove();
		void update();
		void check();
		void report();
		void savedata();
		void readdata();
};

void inventry::login(){
	string user;
	string pass;
	inventry i;
	cout<<"\t\t\t------- Inventry Mangement --------";
	cout<<"\n\nEnter your username: ";
	cin>>user;
	cout<<"\nEnter your password: ";
	cin>>pass;
	if(user == "admin" && pass == "123"){
		system("cls");
		i.home();
	}
	else{
		i.login();
	}
}

void inventry::home(){
	int choice;
	inventry opt;
	
		opt.readdata();
	
	do{
	cout<<"1) Add item";
	cout<<"\n2) Remove item";
	cout<<"\n3) Update item";
	cout<<"\n4) View inventry";
	cout<<"\n5) Genrate report";
	cout<<"\n0) Exit";
	cout<<"\n\nEnter the choice: ";
	cin>>choice;
	
	if(choice == 1){
		opt.add();
	}
	
	else if(choice == 2){
		opt.remove();
	}
	
	else if(choice == 3){
		opt.update();
	}
	
	else if(choice == 4){
		opt.check();
	}
	else if(choice == 5){
		opt.report();
	}
	
	else if(choice == 0){
		cout<<"Thanks";	
	}
	else {
		cout<<"Invalid key\n";
	}
	opt.savedata();
}while(choice != 0);
}

void inventry::add(){
	inventry add;
	item newitem;
	cout<<"\nEnter item id no: ";
	cin>>newitem.id;
	for(int i = 0; i <= count; i++){
		if(items[i].id == newitem.id){
			cout<<"\nid already exist\n";
			return;
		}
	}
	cout<<"\nEnter item name: ";
	cin>>newitem.name;
	cout<<"\nEnter item description: ";
	cin>>newitem.description;
	cout<<"\nEnter item quantity: ";
	cin>>newitem.quantity;
	cout<<"\nEnter item price: ";
	cin>>newitem.price;
	items[count] = newitem;
	count++;
	cout<<count;
	cout<<"\nitem succesfully added\n";
}

void inventry::remove(){
	int id;
	cout<<"\nEnter item id: ";
	cin>>id;
	for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            break;
        }
    }
    count--;
    cout<<"\nitem successfully removed!\n";
}

void inventry::update(){
	int id,quantity;
	cout<<"\nEnter item id: ";
	cin>>id;
	for(int i = 0; i < count; i++){
		if(items[i].id == id){
			cout<<"\nEnter item new quantity: ";
			cin>>quantity;
			items[i].quantity = quantity;
			return;
		}
	}
	cout<<"item not exist!";
}

void inventry::check(){
	int id;
    cout << "Enter item id: ";
    cin >> id;

    int i;
    for (i = 0; i < count; i++)
    {
        if (items[i].id == id)
        {
            cout << "\nitem id: " << items[i].id << endl;
            cout << "item Name: " << items[i].name << endl;
            cout << "item description: " << items[i].description  << endl;
            cout << "item quantity: " << items[i].quantity << endl;
            cout << "item price: " << items[i].price << "$\n\n";
            return;
        }
    }
    cout << "\nAccount not found.\n" << endl;
}

void inventry::savedata(){
	ofstream file("items.txt");
    if (!file) {
        cout << "Error opening file for writing." << std::endl;
        return;
    }

    file << count << endl;

    for (int i = 0; i < count; i++) {
        file << items[i].id << "," << items[i].name << "," << items[i].description << "," << items[i].quantity << "," << items[i].price <<std::endl;
    }

    file.close();
}

void inventry::readdata(){
	ifstream read("items.txt");
	
	read >> count;
	read.ignore();
	for(int i = 0; i < count; i++){
		getline(read, items[i].name, ',');
		getline(read, items[i].description, ',');
		read>>items[i].id;
		read.ignore();
		read>>items[i].quantity;
		read.ignore();
		read>>items[i].price;
		read.ignore();
	}
	read.close();
}
void inventry::report(){
	int totalstock = 0;
    double totalvalue = 0;
    for(int i = 0; i < count; i++){
    	totalstock += items[i].quantity;
        totalvalue += items[i].quantity * items[i].price;
	}
	
	cout<<"\n\ntotal  items: "<<totalstock;
	cout<<"\ntotal value : "<<totalvalue<<"$\n\n";
}
int main(){
	inventry start;
	start.login();
}
