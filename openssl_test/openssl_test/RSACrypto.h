#pragma once

#include <iostream>
#include <string>
#include <openssl/rsa.h>
#include <openssl/pem.h>

enum SignLevel
{
	Level1 = NID_md5,
	Level2 = NID_sha1,
	Level3 = NID_sha224,
	Level4 = NID_sha256,
	Level5 = NID_sha384,
	Level6 = NID_sha512
};

class RSACrypto
{
public:
	RSACrypto();
	RSACrypto(std::string filename, bool isPrivate = true);
	
	// 生成RSA密钥对
	void generateRsakey(int bits, std::string pub = "public.pem", std::string pri = "private.pem");

	// 公钥加密
	std::string rsaPubKeyEncrypt(std::string data);

	// 私钥解密
	std::string rsaPriKeyDecrypt(std::string encData);

	// 使用RSA签名
	std::string rsaSign(std::string data, SignLevel level = Level3);

	// 使用RSA验证签名
	bool rsaVerify(std::string data, std::string signData, SignLevel level = Level3);

	~RSACrypto();

private:

	// 得到公钥
	bool initPublicKey(std::string pubfile);

	// 得到私钥
	bool initPrivateKey(std::string prifile);

private:

	RSA* m_publicKey;
	RSA* m_privateKey;
	
};

