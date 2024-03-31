#include <iostream>
#include <openssl/md5.h>
#include <openssl/sha.h>

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
}

int main()
{
	//md5_test(); //md5测试
	//sha224_test();
	//sha256_test();
	return 0;
}