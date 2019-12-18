#include <gmpxx.h>
using namespace Duthir{
	using namespace Primatives{

		// Input:
		// 		NUT - Number Under Test
		// Ouput
		// 		True - NUT is prime
		// 		False - NUT is non-prime
		bool isPrime(const mpz_class& nut)
		{
			if(nut<=1)
				return false;
			if(nut<=3)
				return true;

			if(n%2==0 || n%3 == 0)
				return false;

			for(mpz_class i=5;i*i<nut;i+=6)
			{
				if(n%i == 0 || n%(i+1)==0)
					return false;
			}

			return true;
		}
	}
}
