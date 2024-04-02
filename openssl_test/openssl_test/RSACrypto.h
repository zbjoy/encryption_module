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
	
	// ����RSA��Կ��
	void generateRsakey(int bits, std::string pub = "public.pem", std::string pri = "private.pem");

	// ��Կ����
	std::string rsaPubKeyEncrypt(std::string data);

	// ˽Կ����
	std::string rsaPriKeyDecrypt(std::string encData);

	// ʹ��RSAǩ��
	std::string rsaSign(std::string data, SignLevel level = Level3);

	// ʹ��RSA��֤ǩ��
	bool rsaVerify(std::string data, std::string signData, SignLevel level = Level3);

	~RSACrypto();

private:

	// �õ���Կ
	bool initPublicKey(std::string pubfile);

	// �õ�˽Կ
	bool initPrivateKey(std::string prifile);

private:

	RSA* m_publicKey;
	RSA* m_privateKey;
	
};

