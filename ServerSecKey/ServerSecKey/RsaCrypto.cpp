#include "RsaCrypto.h"
#include <openssl/bio.h>
#include <openssl/err.h>
#include <iostream>

Cryptographic::Cryptographic()
{
	m_publicKey = RSA_new();
	m_privateKey = RSA_new();
}

Cryptographic::Cryptographic(string fileName, bool isPrivate)
{
	m_publicKey = RSA_new();
	m_privateKey = RSA_new();
	if (isPrivate)
	{
		initPrivateKey(fileName);
	}
	else
	{
		initPublicKey(fileName);
	}
}


Cryptographic::~Cryptographic()
{
	RSA_free(m_publicKey);
	RSA_free(m_privateKey);
}

void Cryptographic::generateRsakey(int bits, string pub, string pri)
{
	RSA* r = RSA_new();
	// ����RSA��Կ��
	// ����bignum����
	BIGNUM* e = BN_new();
	// ��ʼ��bignum����
	BN_set_word(e, 456787);
	RSA_generate_key_ex(r, bits, e, NULL);

	// ����bio�ļ�����
	BIO* pubIO = BIO_new_file(pub.data(), "w");
	// ��Կ��pem��ʽд�뵽�ļ���
	PEM_write_bio_RSAPublicKey(pubIO, r);
	// �����е�����ˢ���ļ���
	BIO_flush(pubIO);
	BIO_free(pubIO);

	// ����bio����
	BIO* priBio = BIO_new_file(pri.data(), "w");
	// ˽Կ��pem��ʽд���ļ���
	PEM_write_bio_RSAPrivateKey(priBio, r, NULL, NULL, 0, NULL, NULL);
	BIO_flush(priBio);
	BIO_free(priBio);

	// �õ���Կ��˽Կ
	m_privateKey = RSAPrivateKey_dup(r);
	m_publicKey = RSAPublicKey_dup(r);

	// �ͷ���Դ
	BN_free(e);
	RSA_free(r);
}

bool Cryptographic::initPublicKey(string pubfile)
{
	// ͨ��BIO���ļ�
	BIO* pubBio = BIO_new_file(pubfile.data(), "r");
	// ��bio�е�pem���ݶ���
	if (PEM_read_bio_RSAPublicKey(pubBio, &m_publicKey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(pubBio);
	return true;
}

bool Cryptographic::initPrivateKey(string prifile)
{
	// ͨ��bio���ļ�
	BIO* priBio = BIO_new_file(prifile.data(), "r");
	// ��bio�е�pem���ݶ���
	if (PEM_read_bio_RSAPrivateKey(priBio, &m_privateKey, NULL, NULL) == NULL)
	{
		ERR_print_errors_fp(stdout);
		return false;
	}
	BIO_free(priBio);
	return true;
}

string Cryptographic::rsaPubKeyEncrypt(string data)
{
	// ���㹫Կ����
	int keyLen = RSA_size(m_publicKey);
	cout << "pubKey len: " << keyLen << endl;
	// �����ڴ�ռ�
	char* encode = new char[keyLen + 1];
	// ʹ�ù�Կ����
	int ret = RSA_public_encrypt(data.size(), (const unsigned char*)data.data(),
		(unsigned char*)encode, m_publicKey, RSA_PKCS1_PADDING);
	string retStr = string();
	if (ret >= 0)
	{
		// ���ܳɹ�
		retStr = string(encode, ret);
	}
	// �ͷ���Դ
	delete[]encode;
	return retStr;
}

string Cryptographic::rsaPriKeyDecrypt(string encData)
{
	// ����˽Կ����
	int keyLen = RSA_size(m_privateKey);
	// ʹ��˽Կ����
	char* decode = new char[keyLen + 1];
	int ret = RSA_private_decrypt(encData.size(), (const unsigned char*)encData.data(),
		(unsigned char*)decode, m_privateKey, RSA_PKCS1_PADDING);
	string retStr = string();
	if (ret >= 0)
	{
		retStr = string(decode, ret);
	}
	delete[]decode;
	return retStr;
}

string Cryptographic::rsaSign(string data, SignLevel level)
{
	unsigned int len;
	char* signBuf = new char[RSA_size(m_privateKey) + 1];
	RSA_sign(level, (const unsigned char*)data.data(), data.size(), (unsigned char*)signBuf,
		&len, m_privateKey);
	cout << "sign len: " << len << endl;
	string retStr = string(signBuf, len);
	delete[]signBuf;
	return retStr;
}

bool Cryptographic::rsaVerify(string data, string signData, SignLevel level)
{
	// ��֤ǩ��
	int ret = RSA_verify(level, (const unsigned char*)data.data(), data.size(),
		(const unsigned char*)signData.data(), signData.size(), m_publicKey);
	if (ret != 1)
	{
		return false;
	}
	return true;
}
