#pragma once
#include "Codec.h"
class Response :
    public Codec
{
public:
    Response();
    Response(std::string encstr);
    Response(int status, int seckeyID, std::string clientID, std::string serverID, std::string data);
    void initMessage(std::string encstr);
    void initMessage(int status, int seckeyID, std::string clientID, std::string serverID, std::string data);
    std::string encodeMsg();
    void* decodeMsg();
    ~Response();
};

