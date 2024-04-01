#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

void md5_test()
{
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, "hello world", sizeof("hello world"));
	unsigned char* buf = new unsigned char[MD5_DIGEST_LENGTH];
	char* res = new char[MD5_DIGEST_LENGTH * 2 + 1];
	MD5_Final(buf, &ctx);
	for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", buf[i]);
	}
	std::cout << "md5: " << res << std::endl;
	delete[] buf;
	delete[] res;
}

void sha224_test()
{
	SHA256_CTX ctx;
	SHA224_Init(&ctx);
	std::string buf = "我的世界, ..., haha";
	SHA224_Update(&ctx, buf.data(), buf.size());
	unsigned char* temp = new unsigned char[SHA224_DIGEST_LENGTH];
	SHA224_Final(temp, &ctx);
	char* res = new char[SHA224_DIGEST_LENGTH * 2 + 1];
	for (int i = 0; i < SHA224_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", temp[i]);
	}
	std::cout << res << std::endl;
	delete[] temp;
	delete[] res;
}

void sha256_test()
{
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, "hello, ", sizeof("hello, "));
	SHA256_Update(&ctx, "world", sizeof("world"));
	unsigned char* temp = new unsigned char[SHA256_DIGEST_LENGTH];
	SHA256_Final(temp, &ctx);
	char* res = new char[SHA256_DIGEST_LENGTH * 2 + 1];
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", temp[i]);
	}
	std::cout << res << std::endl;
	delete[] temp;
	delete[] res;
}

void sha512_test()
{
	SHA512_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, "hello, world", sizeof("hello world"));
	unsigned char* temp = new unsigned char[SHA512_DIGEST_LENGTH];
	char* res = new char[SHA512_DIGEST_LENGTH * 2];
	SHA512_Final(temp, &ctx);
	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
	{
		sprintf(&res[i * 2], "%02x", temp[i]);
	}
	std::cout << res << std::endl;
}

void rsa_test()
{
	RSA* rsa = RSA_new();
	BIGNUM* bigNum = BN_new();
	BN_set_word(bigNum, 12345);

	RSA_generate_key_ex(rsa, 1024, bigNum, NULL);
	BIO* bio = BIO_new_file("public.pem", "w");
	PEM_write_bio_RSAPublicKey(bio, rsa);
	BIO_free(bio);
	bio = BIO_new_file("private.pem", "w");
	PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);
	BIO_free(bio);

	BN_free(bigNum);


	RSA_free(rsa);


	RSA* rsa_read_pubKey = RSA_new();
	RSA* rsa_read_priKey = RSA_new();
	BIO* bio_read = BIO_new_file("public.pem", "r");
	PEM_read_bio_RSAPublicKey(bio_read, &rsa_read_pubKey, NULL, NULL);
	BIO_free(bio_read);
	bio_read = BIO_new_file("private.pem", "r");
	PEM_read_bio_RSAPrivateKey(bio_read, &rsa_read_priKey, NULL, NULL);


	//公钥加密
	int keyLen = RSA_size(rsa_read_pubKey);
	unsigned char* encode = new unsigned char[keyLen + 1];
	const char* from = "hello, world";
	int ret = RSA_public_encrypt(13, (const unsigned char*)from, encode, rsa_read_pubKey, RSA_PKCS1_PADDING);
	std::string retStr;
	if (ret >= 0)
	{
		retStr = std::string((char*)encode, ret);
		std::cout << "加密后的数据:" << retStr << std::endl;
	}
	else
	{
		std::cout << "加密失败" << std::endl;
	}


	//私钥解密
	keyLen = RSA_size(rsa_read_priKey);
	char* decode = new char[keyLen + 1];
	ret = RSA_private_decrypt(retStr.size(), (const unsigned char*)retStr.data(), (unsigned char*)decode, rsa_read_priKey, RSA_PKCS1_PADDING);

	std::string myStr;
	if (ret >= 0)
	{
		myStr = std::string(decode, ret);
		std::cout << "解密后的数据:" << myStr << std::endl;
	}

	delete[] encode;
	
	BIO_free(bio_read);
	RSA_free(rsa_read_pubKey);
	RSA_free(rsa_read_priKey);
}

int main()
{
	//md5_test(); //md5测试
	//sha224_test();
	//sha256_test();
	//sha512_test();
	rsa_test();
	return 0;
}