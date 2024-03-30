#include "Request.h"

RequestCodec::RequestCodec()
{
}

RequestCodec::RequestCodec(std::string encstr)
{
	this->initMessage(encstr);
}

RequestCodec::RequestCodec(RequestInfo* info)
{
	this->initMessage(info);
}

void RequestCodec::initMessage(std::string encstr)
{
	this->m_encStr = encstr;
}

void RequestCodec::initMessage(RequestInfo* info)
{
	this->m_msg.set_cmdtype(info->cmd);
	this->m_msg.set_clientid(info->clientID);
	this->m_msg.set_serverid(info->serverID);
	this->m_msg.set_sign(info->sign);
	this->m_msg.set_data(info->data);
}

std::string RequestCodec::encodeMsg()
{
	std::string output;
	this->m_msg.SerializeToString(&output);
	return output;
}

void* RequestCodec::decodeMsg()
{
	this->m_msg.ParseFromString(this->m_encStr);
	return &this->m_encStr;
}

RequestCodec::~RequestCodec()
{
}
