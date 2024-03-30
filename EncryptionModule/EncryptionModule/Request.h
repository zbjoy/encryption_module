#pragma once
#include "Codec.h"

struct RequestInfo
{
    int cmd;
    std::string clientID;
    std::string serverID;
    std::string sign;
    std::string data;
};

class RequestCodec :
    public Codec
{
public:
    RequestCodec();
    RequestCodec(std::string encstr);
    RequestCodec(RequestInfo* info);
    void initMessage(std::string encstr);
    void initMessage(RequestInfo* info);
    std::string encodeMsg();
    void* decodeMsg();
    ~RequestCodec();

private:
    std::string m_encStr;
    RequestMsg m_msg;
};

