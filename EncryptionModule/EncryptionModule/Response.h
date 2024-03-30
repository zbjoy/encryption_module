#pragma once
#include "Codec.h"

struct RespondInfo
{
    int status;
    int seckeyID;
    std::string clientID;
    std::string serverID;
    std::string data;
};

class ResponseCodec :
    public Codec
{
public:
    ResponseCodec();
    ResponseCodec(std::string encstr);
    ResponseCodec(RespondInfo* info);
    void initMessage(std::string encstr);
    void initMessage(RespondInfo* info);
    std::string encodeMsg();
    void* decodeMsg();
    ~ResponseCodec();

private:
    std::string m_encStr;
    RespondMsg m_msg;
};

