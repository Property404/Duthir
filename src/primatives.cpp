#include <gmpxx.h>
#include "primatives.h"
namespace Duthir{
	namespace Primatives{

		static bool basicPrimeCheck(const mpz_class& nut, const mpz_class& limit)
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

		bool isPrime(const mpz_class& nut)
		{
			const mpz_class limit = nut;
			return basicPrimeCheck(nut, limit);
		}


		static bool isProbablyPrime(const mpz_class& n)
		{
			constexpr int rounds = 40;
			return !!mpz_probab_prime_p(n.get_mpz_t(), rounds);
		}

		void generatePrime(mpz_class& prime, int size)
		{
			gmp_randclass randobject(gmp_randinit_default);
			mpz_class minimum_value;
			mpz_class maximum_value;
			mpz_ui_pow_ui(minimum_value.get_mpz_t(), 2, size-1);
			mpz_ui_pow_ui(maximum_value.get_mpz_t(), 2, size);
			minimum_value*=1.5;
			const mpz_class difference = maximum_value - minimum_value;

			while(true)
			{
				prime = randobject.get_z_range(difference)+minimum_value;
				if(isProbablyPrime(prime))
					return;
			}
		}

	}
}
