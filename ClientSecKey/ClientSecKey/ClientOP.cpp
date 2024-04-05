#include "ClientOP.h"
#include <json/json.h>
#include <fstream>
#include <sstream>
#include "RsaCrypto.h"
#include "RequestCodec.h"
#include "Hash.h"
#include "RequestFactory.h"
#include "TcpSocket.h"
#include "RespondFactory.h"

using namespace std;
using namespace Json;

ClientOP::ClientOP(string jsonFile)
{
	cout << "hello ClientOP" << endl;
	// ����json�ļ�, ���ļ� -> Value
	ifstream ifs(jsonFile);
	Reader r;
	Value root;
	r.parse(ifs, root);
	// ��root�еļ�ֵ��valueȡ��
	m_info.serverID = root["serverID"].asString();
	m_info.clientID = root["ClientID"].asString();
	m_info.ip = root["ServerIP"].asString();
	m_info.port = root["Port"].asInt();
	cout << m_info.ip << ", �˿�:" << m_info.port << endl;
}

ClientOP::~ClientOP()
{
}

bool ClientOP::seckeyAgree()
{
	// 0. ������Կ��, ����Կ�ַ���ȡ��
	RsaCrypto rsa;
	// ������Կ��
	rsa.generateRsakey(1024);
	// ����Կ�ļ�
	ifstream ifs("public.pem");
	stringstream str;
	str << ifs.rdbuf();
	// 1. ��ʼ�����л�����
	// ���л�������� -> �����ഴ��
	RequestInfo reqInfo;
	reqInfo.clientID = m_info.clientID;
	reqInfo.serverID = m_info.serverID;
	reqInfo.cmd = 1;	// ��ԿЭ��
	reqInfo.data = str.str();	// �ǶԳƼ��ܵĹ�Կ
	Hash a(T_SHA1);
	a.addData(str.str());
	reqInfo.sign = rsa.rsaSign(a.result());	// ��Կ��ǩ��
	CodecFactory* factory = new RequestFactory(&reqInfo);
	Codec* c = factory->createCodec();
	// �õ����л�֮�������, ���Խ��䷢�͸���������
	string encstr = c->encodeMsg();
	// �ͷ���Դ
	delete factory;
	delete c;
	
	// �׽���ͨ��, ��ǰ�ǿͻ���, ���ӷ�����
	TcpSocket* tcp = new TcpSocket;
	// ���ӷ�����
	cout << m_info.ip << ", �˿�:" << m_info.port << endl;
	int ret = tcp->connectToHost(m_info.ip, m_info.port);
	if (ret != 0)
	{
		cout << "���ӷ�����ʧ��..." << endl;
		return false;
	}
	cout << "���ӷ������ɹ�..." << endl;
	// �������л�������
	tcp->sendMsg(encstr);
	// �ȴ��������ظ�
	string msg = tcp->recvMsg();
	// �������������� -> ����(�����л�)
		// ���ݻ�ԭ�� RespondMsg
	factory = new RespondFactory(msg);
	c = factory->createCodec();
	RespondMsg* resData = (RespondMsg*)c->decodeMsg();
	// �ж�״̬
	if (!resData->status())
	{
		cout << "��ԿЭ��ʧ��" << endl;
		return false;
	}
	// ���õ������Ľ���
	string key = rsa.rsaPriKeyDecrypt(resData->data());
	cout << "�ԳƼ��ܵ���Կ: " << key << endl;

	delete factory;
	delete c;
	delete tcp;

	return true;
}

void ClientOP::seckeyCheck()
{
}

void ClientOP::seckeyVerification()
{
}
