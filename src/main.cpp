#include <iostream>
#include "primatives.h"
#include "RSA.h"
using namespace std;
int main()
{
	Duthir::RSA::KeyPair key_pair;
	key_pair.generate(128);

	cout<<"private-modulus: "<<key_pair.getPrivate().getModulus()<<endl;

	cout<<"public-modulus: "<<key_pair.getPublic().getModulus()<<endl;

	cout<<"private-exponent: "<<key_pair.getPrivate().getExponent()<<endl;

	cout<<"public-exponent: "<<key_pair.getPublic().getExponent()<<endl;

}
