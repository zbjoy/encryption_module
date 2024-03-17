#pragma once
#include "Codec.h"
class Request :
    public Codec
{
public:
    Request();
    Request(std::string encstr);
    Request(int cmd, std::string clientID, std::string sign, std::string data);
    void initMessage(std::string encstr);
    void initMessage(int cmd, std::string clientID, std::string serverID, std::string sign, std::string data);
    std::string encodeMsg();
    void* decodeMsg();
    ~Request();

private:
    std::string m_encStr;
    RequestMsg m_msg;
};

