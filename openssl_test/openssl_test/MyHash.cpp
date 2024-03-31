#include "MyHash.h"

MyHash::MyHash(HashType type)
{
	m_type = type;
	switch (type)
	{
	case HashType::T_MD5:
		md5Init();
		break;
	case HashType::T_SHA1:
		sha1Init();
		break;
	case HashType::T_SHA224:
		sha224Init();
		break;
	case HashType::T_SHA256:
		sha256Init();
		break;
	case HashType::T_SHA384:
		sha384Init();
		break;
	case HashType::T_SHA512:
		sha512Init();
		break;
	default:
		md5Init();
		break;
	}
}

void MyHash::addData(std::string str)
{
	switch (m_type)
	{
	case HashType::T_MD5:
		md5AddData(str.data());
		break;
	case HashType::T_SHA1:
		sha1AddData(str.data());
		break;
	case HashType::T_SHA224:
		sha224AddData(str.data());
		break;
	case HashType::T_SHA256:
		sha256AddData(str.data());
		break;
	case HashType::T_SHA384:
		sha384AddData(str.data());
		break;
	case HashType::T_SHA512:
		sha512AddData(str.data());
		break;
	default:
		md5AddData(str.data());
		break;
	}
}

std::string MyHash::result()
{
	std::string result = std::string();
	switch (m_type)
	{
	case HashType::T_MD5:
		result = md5Result();
		break;
	case HashType::T_SHA1:
		result = sha1Result();
		break;
	case HashType::T_SHA224:
		result = sha224Result();
		break;
	case HashType::T_SHA256:
		result = sha256Result();
		break;
	case HashType::T_SHA384:
		result = sha384Result();
		break;
	case HashType::T_SHA512:
		result = sha512Result();
		break;
	default:
		result = md5Result();
		break;
	}
	return result;
}

MyHash::~MyHash()
{
}

std::string MyHash::md5Result()
{
	unsigned char md[MD5_DIGEST_LENGTH];
	char res[MD5_DIGEST_LENGTH * 2 + 1];
	MD5_Final(md, &m_md5);
	for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, MD5_DIGEST_LENGTH * 2 + 1);
}

std::string MyHash::sha1Result()
{
	unsigned char md[SHA_DIGEST_LENGTH];
	char res[SHA_DIGEST_LENGTH * 2 + 1];
	SHA1_Final(md, &m_sha1);
	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, SHA_DIGEST_LENGTH * 2 + 1);
}

std::string MyHash::sha224Result()
{
	unsigned char md[SHA224_DIGEST_LENGTH];
	char res[SHA224_DIGEST_LENGTH * 2 + 1];
	SHA224_Final(md, &m_sha224);
	for (int i = 0; i < SHA224_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, SHA224_DIGEST_LENGTH * 2 + 1);
}

std::string MyHash::sha256Result()
{
	unsigned char md[SHA224_DIGEST_LENGTH];
	char res[SHA224_DIGEST_LENGTH * 2 + 1];
	SHA224_Final(md, &m_sha224);
	for (int i = 0; i < SHA224_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, SHA224_DIGEST_LENGTH * 2 + 1);
}

std::string MyHash::sha384Result()
{
	unsigned char md[SHA384_DIGEST_LENGTH];
	char res[SHA384_DIGEST_LENGTH * 2 + 1];
	SHA384_Final(md, &m_sha384);
	for (int i = 0; i < SHA384_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, SHA384_DIGEST_LENGTH * 2 + 1);
}

std::string MyHash::sha512Result()
{
	unsigned char md[SHA512_DIGEST_LENGTH];
	char res[SHA512_DIGEST_LENGTH * 2 + 1];
	SHA512_Final(md, &m_sha512);
	for (int i = 0; i < SHA512_DIGEST_LENGTH; ++i)
	{
		sprintf(&res[i * 2], "%02x", md[i]);
	}
	return std::string(res, SHA512_DIGEST_LENGTH * 2 + 1);
}
