#pragma once
#include "TcpSocket.h"
// ��ʱ��ʱ��

class TcpServer
{
public:
	TcpServer();
	~TcpServer();

	// ���������ü���
	int setListen(unsigned short port);
	// �ȴ������ܿͻ�����������, Ĭ�����ӳ�ʱʱ��Ϊ10000s
	TcpSocket* acceptConn(int timeout = 10000);
	void closefd();

private:
	int m_lfd;	// ���ڼ������ļ�������
};

