#pragma once
#include <iostream>
using namespace std;


/* ����ͨ�ŵ��׽����� */
// ��ʱ��ʱ��
static const int TIMEOUT = 10000;
class TcpSocket
{
public:
	enum ErrorType { ParamError = 3001, TimeoutError, PeerCloseError, MallocError };
	TcpSocket();
	// ʹ��һ����������ͨ�ŵ��׽���ʵ�����׽��ֶ���
	TcpSocket(int connfd);
	~TcpSocket();

	// ���ӷ�����
	int connectToHost(string ip, unsigned short port, int timeout = TIMEOUT);
	// ��������
	int sendMsg(string sendData, int timeout = TIMEOUT);
	// ��������
	string recvMsg(int timeout = TIMEOUT);
	// �Ͽ�����
	void disConnect();

private:
	// ����I/OΪ������ģʽ
	int setNonBlock(int fd);
	// ����I/OΪ����ģʽ
	int setBlock(int fd);
	// ����ʱ��⺯��������������
	int readTimeout(unsigned int wait_seconds);
	// д��ʱ��⺯��, ������д����
	int writeTimeout(unsigned int wait_seconds);
	// �����ӳ�ʱ��connect����
	int connectTimeout(struct sockaddr_in* addr, unsigned int wait_seconds);
	// ÿ�δӻ������ж�ȡn���ַ�
	int readn(void* buf, int count);
	// ÿ����������д��n���ַ�
	int writen(const void* buf, int count);

private:
	int m_socket;		// ����ͨ�ŵ��׽���
};

