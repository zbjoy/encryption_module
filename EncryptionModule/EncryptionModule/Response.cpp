#include "Response.h"

Response::Response()
{
}

Response::Response(std::string encstr)
{
}

Response::Response(int status, int seckeyID, std::string clientID, std::string serverID, std::string data)
{
}

void Response::initMessage(std::string encstr)
{
}

void Response::initMessage(int status, int seckeyID, std::string clientID, std::string serverID, std::string data)
{
}

std::string Response::encodeMsg()
{
	return std::string();
}

void* Response::decodeMsg()
{
	return NULL;
}

Response::~Response()
{
}
