#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int main(){
	time_t currentTime = time(NULL);
	
	tm* localTime = localtime(&currentTime);
	int second = localTime->tm_sec;
	int minute = localTime->tm_min;
	int hour = localTime->tm_hour;
	while(true){
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
	}
}
