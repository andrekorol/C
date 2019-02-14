#include <bitcoin/bitcoin.hpp>
#include <string>
#include <iostream>

using namespace bc;

int main()
{
    
	data_chunk seed(16);
	pseudo_random_fill(seed);
	ec_secret secretKey = bitcoin_hash(seed);
	std::string hexKey = encode_base16(secretKey);
	
	std::cout << "Hex secret:\n" << hexKey << '\n';

	ec_secret rawprivateKey;
	decode_base16(rawprivateKey, hexKey);
	wallet::ec_private privateKey(rawprivateKey, 0x8000, true);
	std::cout << "\nPrivate Key Structure:\n" << privateKey.encoded() << '\n';

	ec_secret keyTest = privateKey.secret();
	std::string keyTestString = encode_base16(keyTest);
	if (keyTestString == hexKey)
		std::cout << "Confirmed: " << keyTestString << '\n';
	else
		std::cout << "Error!" << keyTestString << '\n';

	hexKey = "80" + hexKey;
	std::cout << "\nVersioned Key:\n" << hexKey << '\n';

	data_chunk fullKey;
	data_chunk wifVersion;
	byte_array<37u> versionedKey;
	decode_base16(fullKey, hexKey + "1");
	decode_base16(wifVersion, "0x80");
	build_checked_array(versionedKey, {wifVersion, fullKey});
	std::string practiceKey = encode_base58(versionedKey);
	std::cout << "\nBy hand:\n" << practiceKey << '\n';

	return 0;
}
