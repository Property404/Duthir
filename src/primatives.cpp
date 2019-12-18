#include <gmpxx.h>
#include "primatives.h"
namespace Duthir{
	namespace Primatives{

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

			if(nut%2==0 || nut%3 == 0)
				return false;

			for(mpz_class i=5;i*i<nut;i+=6)
			{
				if(nut%i == 0 || nut%(i+1)==0)
					return false;
			}

			return true;
		}
	}
}
