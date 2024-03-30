#include "Response.h"

RespondCodec::RespondCodec()
{
}

RespondCodec::RespondCodec(std::string encstr)
{
}

RespondCodec::RespondCodec(RespondInfo* info)
{
	this->initMessage(info);
}

void RespondCodec::initMessage(std::string encstr)
{
	this->initMessage(encstr);
}

void RespondCodec::initMessage(RespondInfo* info)
{
	this->m_msg.set_status(info->status);
	this->m_msg.set_seckeyid(info->seckeyID);
	this->m_msg.set_clientid(info->clientID);
	this->m_msg.set_serverid(info->serverID);
	this->m_msg.set_data(info->data);
}

std::string RespondCodec::encodeMsg()
{
	std::string output;
	m_msg.SerializeToString(&output);
	return output;
}

void* RespondCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

RespondCodec::~RespondCodec()
{
}
