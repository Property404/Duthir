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

		void PublicKey::encrypt(mpz_class& ciphertext, const mpz_class& plaintext) const
		{
			mpz_powm(ciphertext.get_mpz_t(), plaintext.get_mpz_t(), getExponent().get_mpz_t(), getModulus().get_mpz_t());
		}

		void PrivateKey::decrypt(mpz_class& plaintext, const mpz_class& ciphertext) const
		{
			mpz_powm(plaintext.get_mpz_t(), ciphertext.get_mpz_t(), getExponent().get_mpz_t(), getModulus().get_mpz_t());
		}

		void KeyPair::generate(mpz_class p, mpz_class q, mpz_class e)
		{
			/*
			 * from https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Key_generation
			 */
			mpz_class d; 
			mpz_class modulus = p*q;

			// carmichael totient function of n
			// = lcm(p-1, q-1)
			p-=1; q-=1; 
			mpz_lcm(lambda.get_mpz_t(), p.get_mpz_t(), q.get_mpz_t()); 
			p+=1; q+=1;
			
			// Private exponent is the inverse of the public exponent mod lambda(modulus)
			mpz_invert(d.get_mpz_t(), e.get_mpz_t(), lambda.get_mpz_t());


			// Store values
			public_key.setModulus(modulus);
			public_key.setExponent(std::move(e));
			private_key.setModulus(modulus);
			private_key.setExponent(std::move(d));

			primes.first = std::move(p);
			primes.second = std::move(q);
		}

		void KeyPair::generate(int size)
		{
			/*
			 * from https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Key_generation
			 */

			// Recommended value
			constexpr auto LARGE_E=(1<<16)+1;

			// Use an insecure value for small keys
			// since they're already insecure
			constexpr auto SMALL_E=3;

			// Message to be tested
			constexpr auto message=42;
			mpz_class cipher, decrypted_message;

			mpz_class d,p,q,e;
			
			while(true)
			{
				// Generate large primes
				generatePrime(p, size/2);
				do
				{
					generatePrime(q, size/2);
				} while(q==p);


				// Public exponent
				e = size<1024?SMALL_E:LARGE_E;

				generate(p,q,e);

				public_key.encrypt(cipher, message);
				private_key.decrypt(decrypted_message, cipher);
				if(message == decrypted_message)
					break;
			}

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


