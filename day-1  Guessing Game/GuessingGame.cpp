#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class game{
	public:
		int numguess;
		int random = rand() % 100 + 1;
		void guess();
};
void game::guess(){
	int i;
 int numguess;
 int random = rand() % 100 + 1;
 srand(time(0));
   cout<<"\t\t------------------------------"<<endl;
   cout<<"\t\t[         GUESSING GAME      ]"<<endl;
   cout<<"\t\t------------------------------"<<endl;
   cout<<"\nYou have only 5 chance for guessing the number"<<endl;
   for(i=1;i<=5;i++){
   	cout<<"\nNow guess the number: ";
   	cin>>numguess;
   	if(numguess<random){
   		cout<<"Too low";
		cout<<"\n\t\t------------------------------"<<endl;
        cout<<"\t\t[         GUESS AGAIN        ]"<<endl;
        cout<<"\t\t------------------------------"<<endl;
	   }
	else if(numguess>random){
		cout<<"Too high";
		cout<<"\n\t\t------------------------------"<<endl;
        cout<<"\t\t[         GUESS AGAIN        ]"<<endl;
        cout<<"\t\t------------------------------"<<endl;
	}   
	else{
		cout<<"You won";
  cout<<"\nyou won the game win "<<i<<" move";
		break;
	}
	if(i==5){
   	cout<<"\n\nyou loss the game";
   cout<<"\nthe number is "<<random;
   }
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
    