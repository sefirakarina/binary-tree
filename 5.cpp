#include <iostream>
using namespace std ;

int main (){
	
	int a,b,c,d,e;
	a=28 ; b=32 ; c=37 ; d=24 ; e=33 ;
	
	int sum = a+b+c+d+e;
	float average = sum % 5;
	
	cout <<"sum = "<<sum<<endl;
	cout << "average = "<<average ;
	
	return 0;
}
