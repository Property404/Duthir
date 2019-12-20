#pragma once
#include <gmpxx.h>

namespace Duthir
{
	namespace RSA
	{
		class AbstractRSAKey{
			mpz_class modulus; 
			mpz_class exponent;
			public:


			const mpz_class& getModulus() const;
			const mpz_class& getExponent() const;

			void setModulus(mpz_class&& new_modulus);
			void setExponent(mpz_class&& new_exponent);
			void setModulus(const mpz_class& new_modulus);
			void setExponent(const mpz_class& new_exponent);
		};

		class PublicKey:public AbstractRSAKey{
			public:
			PublicKey(){};

			void encrypt(mpz_class& ciphertext, const mpz_class& plaintext) const;
		};

		class PrivateKey:public AbstractRSAKey{
			public:
			PrivateKey(){};

			void decrypt(mpz_class& plaintext, const mpz_class& ciphertext) const;
		};

		class KeyPair{
			PrivateKey private_key;
			PublicKey public_key;

			public:
			KeyPair(){};

			std::pair<mpz_class, mpz_class> primes;
			mpz_class lambda;

			// Generate RSA key pair
			void generate(mpz_class p=0, mpz_class q=0, mpz_class e=0);
			void generate(int size);

			// Get individual keys
			const PrivateKey& getPrivate() const;
			const PublicKey& getPublic() const;
		};

	}
};
