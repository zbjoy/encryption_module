#pragma once

#include <iostream>
#include <string>

using namespace std;

struct ClientInfo
{
	string serverID;
	string clientID;
	string ip;
	unsigned short port;
};

class ClientOP
{
public:
	ClientOP(string jsonFile);
	~ClientOP();

	// 密钥协商
	bool seckeyAgree();

	// 密钥校验
	void seckeyCheck();

	// 密钥注销
	void seckeyVerification();

private:
	ClientInfo m_info;
};

