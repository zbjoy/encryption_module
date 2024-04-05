#pragma once
#include "Codec.h"
#include <iostream>
#include "Message.pb.h"

using namespace std;

struct RequestInfo
{
    int cmd;
    string clientID;
    string serverID;
    string sign;
    string data;
};

class RequestCodec :
    public Codec
{
public:
	// �ն���
	RequestCodec();
	// ������Ķ������� ���� �ĳ���
	RequestCodec(string encstr);
	// ������Ķ������� ���� ����
	RequestCodec(RequestInfo* info);
	// init�������չ���׼�� ��
	// ����ʹ��
	void initMessage(string encstr);
	// ����ʱ��ʹ��
	void initMessage(RequestInfo* info);
	// ��д�ĸ��ຯ�� -> ���л�����, �������л����ַ���
	string encodeMsg();
	// ��д�ĸ��ຯ�� -> �����л�����, ���ؽṹ��/�����
	void* decodeMsg();

	~RequestCodec();

private:
	string m_encStr;
	RequestMsg m_msg;
};

