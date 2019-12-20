#include "catch.hpp"
#include <iostream>
#include <climits>
#include "RSA.h"
using namespace Duthir::RSA;

TEST_CASE("Wikipedia RSA test", "[KeyPair RSA]")
{
	KeyPair key_pair;

	key_pair.generate(61, 53, 17);

	REQUIRE(key_pair.primes.first==61);
	REQUIRE(key_pair.primes.second==53);
	REQUIRE(key_pair.lambda==780);
	REQUIRE(key_pair.getPublic().getModulus() == 3233);
	REQUIRE(key_pair.getPublic().getExponent() == 17);
	REQUIRE(key_pair.getPrivate().getExponent() == 413);

	mpz_class message = 65;
	mpz_class cipher;
	mpz_class decrypted_message;
	key_pair.getPublic().encrypt(cipher, message);
	REQUIRE(cipher == 2790);
	key_pair.getPrivate().decrypt(decrypted_message, cipher);
	REQUIRE(decrypted_message == message);

}

TEST_CASE("General RSA test", "[KeyPair RSA]")
{
	KeyPair key_pair;
	mpz_class message;
	mpz_class cipher;
	mpz_class decrypted_message;

	// Deterministic seed so we can repeat if necessary
	srand(0xcafebabe);

	for(int size=8;size<64;size+=2)
	{
		for(int i=0;i<20;i++)
		{
			key_pair.generate(size);
			message = rand() % (1<<std::min(31, size-2));
			key_pair.getPublic().encrypt(cipher, message);
			key_pair.getPrivate().decrypt(decrypted_message, cipher);

			CAPTURE(size);
			CAPTURE(key_pair.primes.first);
			CAPTURE(key_pair.primes.second);
			CAPTURE(key_pair.lambda);
			REQUIRE(message == decrypted_message);
		}
	}
}

