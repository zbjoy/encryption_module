#include "RequestFacory.h"

RequestFactory::RequestFactory(std::string enc)
{
	this->m_flag = false;
	this->m_encStr = enc;
}

RequestFactory::RequestFactory(RequestInfo* info)
{
	this->m_flag = true;
	this->m_info = info;
}

Codec* RequestFactory::createCodec()
{
	Codec* codec = NULL;
	if (this->m_flag)
	{
		codec = new RequestCodec(this->m_info);
	}
	else
	{
		codec = new RequestCodec(this->m_encStr);
	}
	return codec;
}

RequestFactory::~RequestFactory()
{
}
