#include <gmpxx.h>
#include <iostream>
using namespace std;
int main()
{
	mpz_class a,b,c;
	a=1234;
	b="-5678";
	c=a+b;
	cout<<"Sum is "<<c<<"\n";
	cout<<"Absolute value is "<<abs(c)<<"\n";
}
