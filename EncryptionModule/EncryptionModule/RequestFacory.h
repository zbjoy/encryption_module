#pragma once
#include "Codec.h"
#include "Request.h"
#include "CodecFactory.h"
class RequestFactory :
    public CodecFactory
{
public:
    RequestFactory(std::string enc);

    RequestFactory(RequestInfo* info);

    Codec* createCodec();

    ~RequestFactory();

private:
    bool m_flag;
    std::string m_encStr;
    RequestInfo* m_info;
};

