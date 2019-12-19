#include <iostream>
#include "primatives.h"
#include "RSA.h"
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	Duthir::RSA::KeyPair key_pair;
	key_pair.generate(20);

	const auto n = key_pair.getPrivate().getModulus();
	const auto e = key_pair.getPublic().getExponent();
	const auto d = key_pair.getPrivate().getExponent();

	cout<<"modulus: "<<n<<endl;

	cout<<"public-exponent: "<<e<<endl;
	cout<<"private-exponent: "<<d<<endl;

	if(d!=0)
	{
		srand(time(NULL));
		mpz_class message = rand()%54+1;
		mpz_class cipher=8;
		mpz_class decrypted=7;
		key_pair.getPublic().encrypt(cipher, message);
		key_pair.getPrivate().decrypt(decrypted, cipher);
		cout<<"Message: "<<message<<endl;
		cout<<"Cipher: "<<cipher<<endl;
		cout<<"Decrypted: "<<decrypted<<endl;
	}

}
