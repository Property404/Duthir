#include <gmpxx.h>
#include <cstdint>
#include <iostream>
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
			constexpr int rounds = 30;
			return !!mpz_probab_prime_p(n.get_mpz_t(), rounds);
		}
		
		static uint32_t generateRandomWord()
		{
			auto urandom = fopen("/dev/urandom", "r");
			uint32_t rv;
			fread(&rv, sizeof(rv), 1, urandom);
			fclose(urandom);
			return rv;
		}
		void generateRandomNumber(mpz_class& number, int size)
		{
			number = 0;
			for(int word=0;word<size/4;word++)
			{
				const uint32_t random_word = generateRandomWord();
				for(int bit=0;bit<32;bit++)
				{
					if(word+bit >=size)
						return;

					const bool bit_value = random_word &
						(1<<bit);

					if(bit_value)
						mpz_setbit(number.get_mpz_t(), bit+word*32);
					else
						mpz_clrbit(number.get_mpz_t(), bit+word*32);
				}
			}
		}

		void generatePrime(mpz_class& prime, int size)
		{
			prime = 0;
			while(true)
			{
				if(prime == 0)
				{
					generateRandomNumber(prime, size);
					mpz_setbit(prime.get_mpz_t(), size-1);
					//has to be odd
					mpz_setbit(prime.get_mpz_t(), 0);
				}
				else
				{
					mpz_nextprime(prime.get_mpz_t(), prime.get_mpz_t());
				}

				if(isProbablyPrime(prime))
					return;
			}
		}

	}
}
