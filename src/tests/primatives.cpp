#include "catch.hpp"
#include <iostream>
#include "primatives.h"
using namespace Duthir::Primatives;

TEST_CASE( "isPrime test", "[isPrime]" )
{
	REQUIRE(isPrime(0) == false);
	REQUIRE(isPrime(1) == false);
	REQUIRE(isPrime(2) == true);
	REQUIRE(isPrime(3) == true);
	REQUIRE(isPrime(4) == false);
	REQUIRE(isPrime(5) == true);
	REQUIRE(isPrime(6) == false);
	REQUIRE(isPrime(7) == true);
	REQUIRE(isPrime(97) == true);
	REQUIRE(isPrime(101) == true);
	REQUIRE(isPrime(105) == false);
	REQUIRE(isPrime((1<<7) - 1) == true);
	REQUIRE(isPrime((1<<11) - 1) == false);
}

TEST_CASE( "generatePrime test", "[generatePrime]" )
{
	mpz_class prime;
	for(int size=8;size<=192;size+=2)
	{
		generatePrime(prime, size);
		REQUIRE(mpz_probab_prime_p(prime.get_mpz_t(), 50)>0);
	}
}
