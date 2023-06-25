#include <iostream>
using namespace std;
template <class data>
class checkequality{
	private:
		data num;
	public:
		checkequality(data num1,data num2) : num(!(num1 ^ num2)){
		}
		data input(){
	    	return num;
		}
};
int main(){
	float n,m;
	cout<<"\nenter first number: ";
	cin>>n;
	cout<<"\nenter second number: ";
	cin>>m;
	checkequality<int> intcheck(n,m);
	
	if(intcheck.input())
	{
		cout<<"Numbers are equal.";
	}
	else{
		cout<<"Numbers are not eqaul.";
	}
}
