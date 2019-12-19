#include <iostream>
#include "primatives.h"
using namespace std;
int main()
{
	mpz_class prime = 1;
	Duthir::Primatives::generatePrime(prime, 2048);
	cout<<"prime: "<<prime<<endl;
}
