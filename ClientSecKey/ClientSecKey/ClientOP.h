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

	// ��ԿЭ��
	bool seckeyAgree();

	// ��ԿУ��
	void seckeyCheck();

	// ��Կע��
	void seckeyVerification();

private:
	ClientInfo m_info;
};

