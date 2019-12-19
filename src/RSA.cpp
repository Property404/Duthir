#include "RSA.h"
#include "primatives.h"
namespace Duthir
{
	namespace RSA
	{
		using namespace Primatives;

		const mpz_class& AbstractRSAKey::getModulus() const
		{
			return modulus;
		}

		const mpz_class& AbstractRSAKey::getExponent() const
		{
			return exponent;
		}

		void AbstractRSAKey::setModulus(const mpz_class& new_modulus)
		{
			modulus = new_modulus;
		}

		void AbstractRSAKey::setModulus(mpz_class&& new_modulus)
		{
			modulus = std::move(new_modulus);
		}

		void AbstractRSAKey::setExponent(const mpz_class& new_exponent)
		{
			exponent = new_exponent;
		}

		void AbstractRSAKey::setExponent(mpz_class&& new_exponent)
		{
			exponent = std::move(new_exponent);
		}

		void KeyPair::generate(int size)
		{
			/*
			 * from https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Key_generation
			 */
			constexpr auto LARGE_E=(1<<16)+1;
			constexpr auto SMALL_E=3;

			
			mpz_class p;
			generatePrime(p, size/2);

			mpz_class q;
			generatePrime(q, size/2);
			mpz_class modulus = p*q;

			p-=1;
			q-=1;

			// carmichael totient function of n
			// = lcm(p-1, q-1)
			mpz_class lambda;
			mpz_lcm(lambda.get_mpz_t(), p.get_mpz_t(), q.get_mpz_t());

			mpz_class e = lambda>LARGE_E?SMALL_E:LARGE_E;

			mpz_class d; 
			mpz_invert(d.get_mpz_t(), e.get_mpz_t(), lambda.get_mpz_t());

			public_key.setModulus(modulus);
			public_key.setExponent(std::move(e));
			private_key.setModulus(modulus);
			private_key.setExponent(std::move(d));

		}

		const PrivateKey& KeyPair::getPrivate() const
		{
			return private_key;
		}
		const PublicKey& KeyPair::getPublic() const
		{
			return public_key;
		}
	}
}


