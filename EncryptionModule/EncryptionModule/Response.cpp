#include "Response.h"

ResponseCodec::ResponseCodec()
{
}

ResponseCodec::ResponseCodec(std::string encstr)
{
}

ResponseCodec::ResponseCodec(RespondInfo* info)
{
	this->initMessage(info);
}

void ResponseCodec::initMessage(std::string encstr)
{
	this->initMessage(encstr);
}

void ResponseCodec::initMessage(RespondInfo* info)
{
	this->m_msg.set_status(info->status);
	this->m_msg.set_seckeyid(info->seckeyID);
	this->m_msg.set_clientid(info->clientID);
	this->m_msg.set_serverid(info->serverID);
	this->m_msg.set_data(info->data);
}

std::string ResponseCodec::encodeMsg()
{
	std::string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* ResponseCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

ResponseCodec::~ResponseCodec()
{
}
