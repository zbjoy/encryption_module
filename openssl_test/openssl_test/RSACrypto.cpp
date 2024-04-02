#include "RSACrypto.h"
#include <openssl/err.h>
#include <openssl/bio.h>

RSACrypto::RSACrypto()
{
	this->m_publicKey = RSA_new();
	this->m_privateKey = RSA_new();
}

RSACrypto::RSACrypto(std::string filename, bool isPrivate)
{
	this->m_publicKey = RSA_new();
	this->m_privateKey = RSA_new();

	if (isPrivate)
	{
		this->initPrivateKey(filename);
	}
	else
	{
		this->initPublicKey(filename);
	}
}

void RSACrypto::generateRsakey(int bits, std::string pub, std::string pri)
{
	RSA* rsa = RSA_new();
	BIGNUM* e = BN_new();
	BN_set_word(e, 456787);
	int ret = RSA_generate_key_ex(rsa, bits, e, NULL);
	/*if (ret)
	{
		std::cout << "test1" << std::endl;
	}*/

	// 创建bio对象
	BIO* pubBio = BIO_new_file(pub.data(), "w");

	// 公钥以pem格式写入到文件中
	PEM_write_bio_RSAPublicKey(pubBio, rsa);

	BIO_flush(pubBio);
	BIO_free(pubBio);

	// 创建bio对象
	BIO* priBio = BIO_new_file(pri.data(), "w");
	
	// 私钥以pem格式写入文件
	PEM_write_bio_RSAPrivateKey(priBio, rsa, NULL, NULL, 0, NULL, NULL);
	BIO_flush(priBio);
	BIO_free(priBio);

	// 得到公钥和私钥
	this->m_publicKey = RSAPublicKey_dup(rsa);
	this->m_privateKey = RSAPrivateKey_dup(rsa);

	BN_free(e);
	RSA_free(rsa);
}

std::string RSACrypto::rsaPubKeyEncrypt(std::string data)
{
	// 计算公钥长度
	int keyLen = RSA_size(this->m_publicKey);
	// 申请内存空间
	char* encode = new char[keyLen + 1]; // 不加1会怎么样

	int ret = RSA_public_encrypt(data.size(), (const unsigned char*)data.data(), (unsigned char*)encode, this->m_publicKey, RSA_PKCS1_PADDING);

	std::string retStr = std::string();
	if (ret >= 0)
	{
		retStr = std::string(encode, ret);
	}
	
	delete[] encode;
	return retStr;
}

std::string RSACrypto::rsaPriKeyDecrypt(std::string encData)
{
	int keyLen = RSA_size(this->m_privateKey);
	char* decode = new char[keyLen + 1]; // keyLen不加1会怎么样

	int ret = RSA_private_decrypt(encData.size(), (const unsigned char*)encData.data(), (unsigned char*)decode, this->m_privateKey, RSA_PKCS1_PADDING);

	std::string retStr = std::string();
	if (ret >= 0)
	{
		retStr = std::string(decode, ret);
	}
	delete[] decode;
	return retStr;
}

std::string RSACrypto::rsaSign(std::string data, SignLevel level)
{
	unsigned int len;
	char* signBuf = new char[RSA_size(m_privateKey) + 1];
	RSA_sign(level, (const unsigned char*)data.data(), data.size(), (unsigned char*)signBuf, &len, this->m_privateKey);

	std::string retStr = std::string(signBuf, len);
	delete[] signBuf;
	return retStr;
}

bool RSACrypto::rsaVerify(std::string data, std::string signData, SignLevel level)
{
	int ret = RSA_verify(level, (const unsigned char*)data.data(), data.size(), (const unsigned char*)signData.data(), signData.size(), this->m_publicKey);

	if (ret != 1)
	{
		return false;
	}
	return true;
}

RSACrypto::~RSACrypto()
{
	RSA_free(this->m_publicKey);
	RSA_free(this->m_privateKey);
}

bool RSACrypto::initPublicKey(std::string pubfile)
{
	BIO* pubBio = BIO_new_file(pubfile.data(), "r");

	if (PEM_read_bio_RSAPublicKey(pubBio, &this->m_publicKey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(pubBio);
	return true;
}

bool RSACrypto::initPrivateKey(std::string prifile)
{
	BIO* priBio = BIO_new_file(prifile.data(), "r");

	if (PEM_read_bio_RSAPrivateKey(priBio, &this->m_privateKey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(priBio);
	return true;
}
