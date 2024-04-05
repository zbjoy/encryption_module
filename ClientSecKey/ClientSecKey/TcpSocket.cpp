#include "TcpSocket.h"
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

TcpSocket::TcpSocket()
{
}

TcpSocket::TcpSocket(int connfd)
{
	m_socket = connfd;
}

TcpSocket::~TcpSocket()
{
}

int TcpSocket::connectToHost(string ip, unsigned short port, int timeout)
{
	int ret = 0;
	if (port <= 0 || port > 65535 || timeout < 0)
	{
		ret = ParamError;
		return ret;
	}

	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket < 0)
	{
		ret = errno;
		printf("func socket() err:  %d\n", ret);
		return ret;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(ip.data());

	ret = connectTimeout((struct sockaddr_in*)(&servaddr), (unsigned int)timeout);
	if (ret < 0)
	{
		// ��ʱ
		if (ret == -1 && errno == ETIMEDOUT)
		{
			ret = TimeoutError;
			return ret;
		}
		else
		{
			printf("connectTimeout �����쳣, �����: %d\n", errno);
			return errno;
		}
	}

	return ret;
}

int TcpSocket::sendMsg(string sendData, int timeout)
{
	// ����0->û��ʱ, ����-1->��ʱ
	int ret = writeTimeout(timeout);
	if (ret == 0)
	{
		int writed = 0;
		int dataLen = sendData.size() + 4;
		// ��ӵ�4�ֽ���Ϊ����ͷ, �洢���ݿ鳤��
		unsigned char* netdata = (unsigned char*)malloc(dataLen);
		if (netdata == NULL)
		{
			ret = MallocError;
			printf("func sckClient_send() mlloc Err:%d\n ", ret);
			return ret;
		}
		// ת��Ϊ�����ֽ���
		int netlen = htonl(sendData.size());
		memcpy(netdata, &netlen, 4);
		memcpy(netdata + 4, sendData.data(), sendData.size());

		// û���ⷵ�ط��͵�ʵ���ֽ���, Ӧ�� == �ڶ�������: dataLen
		// ʧ�ܷ���: -1
		writed = writen(netdata, dataLen);
		if (writed < dataLen)	// ����ʧ��
		{
			if (netdata != NULL)
			{
				free(netdata);
				netdata = NULL;
			}
			return writed;
		}
		// �ͷ��ڴ�
		if (netdata != NULL)
		{
			free(netdata);
			netdata = NULL;
		}
	}
	else
	{
		//ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
		if (ret == -1 && errno == ETIMEDOUT)
		{
			ret = TimeoutError;
			printf("func sckClient_send() mlloc Err:%d\n ", ret);
		}
	}

	return ret;
}

string TcpSocket::recvMsg(int timeout)
{
	// ����0 -> û��ʱ�ͽ��յ�������, -1, ��ʱ�����쳣
	int ret = readTimeout(timeout);
	if (ret != 0)
	{
		if (ret == -1 || errno == ETIMEDOUT)
		{
			printf("readTimeout(timeout) err: TimeoutError \n");
			return string();
		}
		else
		{
			printf("readTimeout(timeout) err: %d \n", ret);
			return string();
		}
	}

	int netdatalen = 0;
	ret = readn(&netdatalen, 4); //����ͷ 4���ֽ�
	if (ret == -1)
	{
		printf("func readn() err:%d \n", ret);
		return string();
	}
	else if (ret < 4)
	{
		printf("func readn() err peer closed:%d \n", ret);
		return string();
	}

	int n = ntohl(netdatalen);
	// ���ݰ�ͷ�м�¼�����ݴ�С�����ڴ�, ��������
	char* tmpBuf = (char*)malloc(n + 1);
	if (tmpBuf == NULL)
	{
		ret = MallocError;
		printf("malloc() err \n");
		return NULL;
	}

	ret = readn(tmpBuf, n); //���ݳ��ȶ�����
	if (ret == -1)
	{
		printf("func readn() err:%d \n", ret);
		return string();
	}
	else if (ret < n)
	{
		printf("func readn() err peer closed:%d \n", ret);
		return string();
	}

	tmpBuf[n] = '\0'; //�����һ���ֽ����ݣ����ݿɼ��ַ��� �ַ�������ʵ������ȻΪn
	string data = string(tmpBuf);
	// �ͷ��ڴ�
	free(tmpBuf);

	return data;
}

void TcpSocket::disConnect()
{
	if (m_socket >= 0)
	{
		close(m_socket);
	}
}

/////////////////////////////////////////////////
//////             �Ӻ���                   //////
/////////////////////////////////////////////////
/*
* setNonBlock - ����I/OΪ������ģʽ
* @fd: �ļ������
*/
int TcpSocket::setNonBlock(int fd)
{
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)
	{
		return flags;
	}

	flags |= O_NONBLOCK;
	int ret = fcntl(fd, F_SETFL, flags);
	return ret;
}

/*
* setBlock - ����I/OΪ����ģʽ
* @fd: �ļ������
*/
int TcpSocket::setBlock(int fd)
{
	int ret = 0;
	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)
	{
		return flags;
	}

	flags &= ~O_NONBLOCK;
	ret = fcntl(fd, F_SETFL, flags);
	return ret;
}

/*
* readTimeout - ����ʱ��⺯��������������
* @wait_seconds: �ȴ���ʱ���������Ϊ0��ʾ����ⳬʱ
* �ɹ���δ��ʱ������0��ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
*/
int TcpSocket::readTimeout(unsigned int wait_seconds)
{
	int ret = 0;
	if (wait_seconds > 0)
	{
		fd_set read_fdset;
		struct timeval timeout;

		FD_ZERO(&read_fdset);
		FD_SET(m_socket, &read_fdset);

		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;

		//select����ֵ��̬
		//1 ��timeoutʱ�䵽����ʱ����û�м�⵽���¼� ret����=0
		//2 ��ret����<0 &&  errno == EINTR ˵��select�Ĺ����б�����ź��жϣ����ж�˯��ԭ��
		//2-1 ������-1��select����
		//3 ��ret����ֵ>0 ��ʾ��read�¼������������¼������ĸ���

		do
		{
			ret = select(m_socket + 1, &read_fdset, NULL, NULL, &timeout);

		} while (ret < 0 && errno == EINTR);

		if (ret == 0)
		{
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret == 1)
		{
			ret = 0;
		}
	}

	return ret;
}

/*
* writeTimeout - д��ʱ��⺯��������д����
* @wait_seconds: �ȴ���ʱ���������Ϊ0��ʾ����ⳬʱ
* �ɹ���δ��ʱ������0��ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
*/
int TcpSocket::writeTimeout(unsigned int wait_seconds)
{
	int ret = 0;
	if (wait_seconds > 0)
	{
		fd_set write_fdset;
		struct timeval timeout;

		FD_ZERO(&write_fdset);
		FD_SET(m_socket, &write_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			ret = select(m_socket + 1, NULL, &write_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);

		// ��ʱ
		if (ret == 0)
		{
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret == 1)
		{
			ret = 0;	// û��ʱ
		}
	}

	return ret;
}

/*
* connectTimeout - connect
* @addr: Ҫ���ӵĶԷ���ַ
* @wait_seconds: �ȴ���ʱ���������Ϊ0��ʾ����ģʽ
* �ɹ���δ��ʱ������0��ʧ�ܷ���-1����ʱ����-1����errno = ETIMEDOUT
*/
int TcpSocket::connectTimeout(sockaddr_in* addr, unsigned int wait_seconds)
{
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	if (wait_seconds > 0)
	{
		setNonBlock(m_socket);	// ���÷�����IO
	}

	ret = connect(m_socket, (struct sockaddr*)addr, addrlen);
	// ������ģʽ����, ����-1, ����errnoΪEINPROGRESS, ��ʾ�������ڽ�����
	if (ret < 0 && errno == EINPROGRESS)
	{
		fd_set connect_fdset;
		struct timeval timeout;
		FD_ZERO(&connect_fdset);
		FD_SET(m_socket, &connect_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			// һ�����ӽ��������׽��־Ϳ�д ����connect_fdset������д������
			ret = select(m_socket + 1, NULL, &connect_fdset, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);

		if (ret == 0)
		{
			// ��ʱ
			ret = -1;
			errno = ETIMEDOUT;
		}
		else if (ret < 0)
		{
			return -1;
		}
		else if (ret == 1)
		{
			/* ret����Ϊ1����ʾ�׽��ֿ�д�������������������һ�������ӽ����ɹ���һ�����׽��ֲ�������*/
			/* ��ʱ������Ϣ���ᱣ����errno�����У���ˣ���Ҫ����getsockopt����ȡ�� */
			int err;
			socklen_t sockLen = sizeof(err);
			int sockoptret = getsockopt(m_socket, SOL_SOCKET, SO_ERROR, &err, &sockLen);
			if (sockoptret == -1)
			{
				return -1;
			}
			if (err == 0)
			{
				ret = 0;	// �ɹ���������
			}
			else
			{
				// ����ʧ��
				errno = err;
				ret = -1;
			}
		}
	}
	if (wait_seconds > 0)
	{
		setBlock(m_socket);	// �׽������û�����ģʽ
	}
	return ret;
}

/*
* readn - ��ȡ�̶��ֽ���
* @fd: �ļ�������
* @buf: ���ջ�����
* @count: Ҫ��ȡ���ֽ���
* �ɹ�����count��ʧ�ܷ���-1������EOF����<count
*/
int TcpSocket::readn(void* buf, int count)
{
	size_t nleft = count;
	ssize_t nread;
	char* bufp = (char*)buf;

	while (nleft > 0)
	{
		if ((nread = read(m_socket, bufp, nleft)) < 0)
		{
			if (errno == EINTR)
			{
				continue;
			}
			return -1;
		}
		else if (nread == 0)
		{
			return count - nleft;
		}

		bufp += nread;
		nleft -= nread;
	}

	return count;
}

/*
* writen - ���͹̶��ֽ���
* @buf: ���ͻ�����
* @count: Ҫ��ȡ���ֽ���
* �ɹ�����count��ʧ�ܷ���-1
*/
int TcpSocket::writen(const void* buf, int count)
{
	size_t nleft = count;
	ssize_t nwritten;
	char* bufp = (char*)buf;

	while (nleft > 0)
	{
		if ((nwritten = write(m_socket, bufp, nleft)) < 0)
		{
			if (errno == EINTR)	// ���źŴ��
			{
				continue;
			}
			return -1;
		}
		else if (nwritten == 0)
		{
			continue;
		}

		bufp += nwritten;
		nleft -= nwritten;
	}

	return count;
}
