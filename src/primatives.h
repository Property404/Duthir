#pragma once
#include <gmpxx.h>
namespace Duthir{
	namespace Primatives{

		// Input:
		// 		NUT - Number Under Test
		// Ouput
		// 		True - NUT is prime
		// 		False - NUT is non-prime
		bool isPrime(const mpz_class& nut);

		// Input
		// 		prime - prime number to be returned
		// 		size - size in bits
		void generatePrime(mpz_class& prime, int size);

		// Input
		// 		number - random number to be returned
		// 		size - size in bits
		void generateRandomNumber(mpz_class& number, int size);
	};
};
