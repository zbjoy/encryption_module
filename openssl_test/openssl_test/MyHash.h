#pragma once
#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <openssl/sha.h>

enum HashType
{
	T_MD5,
	T_SHA1,
	T_SHA224,
	T_SHA256,
	T_SHA384,
	T_SHA512
};

class MyHash
{
public:
	MyHash(HashType type);

	void addData(std::string str);

	std::string result();

	~MyHash();

private:

	inline void md5Init()
	{
		MD5_Init(&this->m_md5);
	}

	inline void md5AddData(const char* data)
	{
		MD5_Update(&m_md5, data, strlen(data));
	}
	std::string md5Result();

	inline void sha1Init()
	{
		SHA1_Init(&this->m_sha1);
	}

	inline void sha1AddData(const char* str)
	{
		SHA1_Update(&this->m_sha1, str, strlen(str));
	}

	std::string sha1Result();

	inline void sha224Init()
	{
		SHA224_Init(&this->m_sha224);
	}

	inline void sha224AddData(const char* str)
	{
		SHA224_Update(&m_sha224, str, strlen(str));
	}
	std::string sha224Result();

	// sha256
	inline void sha256Init() { SHA256_Init(&m_sha256); }
	inline void sha256AddData(const char* data)
	{
		SHA256_Update(&m_sha256, data, strlen(data));
	}
	std::string sha256Result();

	// sha384
	inline void sha384Init() { SHA384_Init(&m_sha384); }
	inline void sha384AddData(const char* data)
	{
		SHA384_Update(&m_sha384, data, strlen(data));
	}
	std::string sha384Result();

	// sha512
	inline void sha512Init() { SHA512_Init(&m_sha512); }
	inline void sha512AddData(const char* data)
	{
		SHA512_Update(&m_sha512, data, strlen(data));
	}
	std::string sha512Result();

private:

	HashType m_type;
	MD5_CTX m_md5;
	SHA_CTX m_sha1;
	SHA256_CTX m_sha224;
	SHA256_CTX m_sha256;
	SHA512_CTX m_sha384;
	SHA512_CTX m_sha512;
};

