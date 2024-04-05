#pragma once

#include <string>
#include <openssl/rsa.h>
#include <openssl/pem.h>

using namespace std;

enum SignLevel
{
	Level1 = NID_md5,
	Level2 = NID_sha1,
	Level3 = NID_sha224,
	Level4 = NID_sha256,
	Level5 = NID_sha384,
	Level6 = NID_sha512
};

class RsaCrypto
{
public:

	RsaCrypto();
	RsaCrypto(string fileName, bool isPrivate = true);
	~RsaCrypto();

	// ����RSA��Կ��
	void generateRsakey(int bits, string pub = "public.pem", string pri = "private.pem");

	// ��Կ����
	string rsaPubKeyEncrypt(string data);

	// ˽Կ����
	string rsaPriKeyDecrypt(string encData);

	// ʹ��RSAǩ��
	string rsaSign(string data, SignLevel level = Level3);

	// ʹ��RSA��֤ǩ��
	bool rsaVerify(string data, string signData, SignLevel level = Level3);
	
private:

	// �õ���Կ
	bool initPublicKey(string pubfile);

	//�õ�˽Կ
	bool initPrivateKey(string prifile);

private:

	RSA* m_publicKey; //��Կ
	RSA* m_privateKey; //˽Կ

};

