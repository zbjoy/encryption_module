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

class RespondCodec :
    public Codec
{
public:
    RespondCodec();
    RespondCodec(std::string encstr);
    RespondCodec(RespondInfo* info);
    void initMessage(std::string encstr);
    void initMessage(RespondInfo* info);
    std::string encodeMsg();
    void* decodeMsg();
    ~RespondCodec();

private:
    std::string m_encStr;
    RespondMsg m_msg;
};

