#include <iostream>
using namespace std;

int main (){
	
	int price = 95;
	float statetax=price * 0.04;
	float countytax=price * 0.02;
	float totaltax = statetax+countytax;
	float totalprice=totaltax+price;
	
	
	cout <<"price = " << price <<endl;
	cout << "total tax= "<< totaltax <<endl;
	cout <<"total price = "<< totalprice;
	
return 0;
}
