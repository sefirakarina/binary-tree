#include <iostream>
using namespace std ;

int main(){
	
	float price=88.67;
	float tax=price*0.0675;
	float total1= price+tax;
	float tip= 0.2 * total1;
	float total2=total1+tip;
	
	cout << "meal cost = " << price <<endl;
	cout <<"tax amount = " << tax <<endl;
	cout << "tip amount = " << tip << endl;
	cout << "total price = "<< total2 ;
	
	return 0;
}
