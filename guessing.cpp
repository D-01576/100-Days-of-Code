#include<iostream>
#include<cstdlib>
using namespace std;
class game{
	public:
		int numguess;
		int random = (rand() % 100);
		void guess();
};
void game::guess(){
	int i;
   cout<<"\t\t\t------------------------------"<<endl;
   cout<<"\t\t\t[         GUESSING GAME      ]"<<endl;
   cout<<"\t\t\t------------------------------"<<endl;
   cout<<"\nYou have only ten chance for guessing the number"<<endl;
   for(i=1;i<=10;i++){
   	cout<<"\nNow guess the number: ";
   	cin>>numguess;
   	if(numguess<random){
   		cout<<"Too low";
		cout<<"\n\t\t\t------------------------------"<<endl;
        cout<<"\t\t\t[         GUESS AGAIN        ]"<<endl;
        cout<<"\t\t\t------------------------------"<<endl;
	   }
	else if(numguess>random){
		cout<<"Too high";
		cout<<"\n\t\t\t------------------------------"<<endl;
        cout<<"\t\t\t[         GUESS AGAIN        ]"<<endl;
        cout<<"\t\t\t------------------------------"<<endl;
	}   
	else{
		cout<<"you win";
		break;
	}
	if(i==10){
   	cout<<"\n\nyou loss the game";
   }
   }
   if(i==10){
   	cout<<"you loss the game";
   }
   slice:
   int key;
   cout<<"\n\n1) I want to play again";
   cout<<"\n2) exit";
   cout<<"\n\nEnter the key: ";
   	cin>>key;
   	if(key==1){
   		guess();
	   }
	else if(key==2){
		
	}   
	else{
		goto slice;
	}
}
int main(){
	game play;
	play.guess();
}
