#include <iostream>
using namespace std;

int mark[7],tatal;
float percentage;
class grading{
	public:
		int maxmarks;
		void input();
		void logic();
	    
};
void grading::input(){
	cout<<"\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t[      Grading System      ]\n";
	cout<<"\t\t\t\t\t----------------------------\n";
	cout<<"\nEnter the max mark for all subject: ";
	cin>>maxmarks;
	cout<<"Enter the marks from the below subjects\n\n";
	string sub[] = {"Math", "Sindhi", "Urdu", "Computer", "English", "Chemistry", "Physics"} ;
	int temp = 0;
	for (int i=0; i<7; i++){
		cout<<sub[i] + ": ";
		cin>>temp;
		if (temp>maxmarks){
			cout<<"You extend the marks limits\n";
			i--;
		}
		else{
			mark[i] = temp;
		}
		
	}
}
void grading::logic(){
	    tatal = mark[0]+mark[1]+mark[2]+mark[3]+mark[4]+mark[5]+mark[6];
	    cout<<"\nTatal: "<<tatal;
     	percentage = tatal * 100 / (maxmarks * 7);
     	cout<<"\npercentage: "<<percentage<<"%";
     	if(percentage>30){
     		cout<<"\nStatus: Pass";
		 }
		else{
			cout<<"\nStatus: fail";
		}
		if(percentage >= 30 && percentage <= 44){
			cout<<"\nGrade: E";
		}
		else if(percentage >= 45 && percentage <= 54){
			cout<<"\nGrade: D";
		}
		else if(percentage >= 55 && percentage <= 64){
			cout<<"\nGrade: C";
		}
		else if(percentage >= 65 && percentage <= 74){
			cout<<"\nGrade: B";
		}
		else if(percentage >= 75 && percentage <= 84){
			cout<<"\nGrade: A";
		}
		else if(percentage >=85){
		    cout<<"\nGrade: A1";			
		}
		else{
			cout<<"\nGrade: ?";
		}
}
int main(){
	grading grade;
	grade.input();
	grade.logic();
}
