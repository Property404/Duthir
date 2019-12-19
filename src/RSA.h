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
		};

		class PrivateKey:public AbstractRSAKey{
			public:
			PrivateKey(){};
		};

		class KeyPair{
			PrivateKey private_key;
			PublicKey public_key;

			public:
			KeyPair(){};

			// Generate RSA key pair
			void generate(int size);

			// Get individual keys
			const PrivateKey& getPrivate() const;
			const PublicKey& getPublic() const;
		};

	}
};
