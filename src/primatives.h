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
	};
};
