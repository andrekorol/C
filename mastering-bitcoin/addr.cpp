#include <bitcoin/bitcoin.hpp>

int main() {
	// Private secret key.
	bc::ec_secret secret;
	bool success = bc::decode_base16(secret,
									 "038109007313a5807b2eccc082c8c3fbb988a973cacf1a7df9ce725c31b14776");
	assert(success);
	
	// Get public key.
	bc::ec_point public_key = bc::secret_to_public_key(secret);
	std::cout << "Public key: " << bc::encode_hex(public_key) << std:: endl;
	
	return 0;
}
