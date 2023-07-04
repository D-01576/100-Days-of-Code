#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main(){
	bool start = false;
	int second = 0;
	int minute = 0;
	int hour = 0;
	int range;
	while(!start){
		system("cls");
		cout<< "\t\t\t\t\t" << hour <<" : " << minute <<" : " << second;
	cout<<"\nif start  click on 'A'";
	cout<<"\nif restart click on 'R'";
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				start = true;
			case 'r':
				second = 0;
				minute = 0;
				hour = 0;
		}
	}
	while(start){
		Sleep(1000);
		system("cls");
		second += 1;
		if(second == 60){
			second = 0;
			minute += 1;
			if(minute == 60 ){
				minute = 0;
				hour += 1;
			}
		}
		cout<< "\t\t\t\t\t" << hour <<" : " << minute <<" : " << second;
		cout<<"\nif stop click on 'S'";
		cout<<"\nif restart click on 'R'";
		if(_kbhit()){
		switch(_getch()){
			case 's':
				start = false;
			case 'r':
				second = 0;
				minute = 0;
				hour = 0;
		}
	}
	}
}
}
