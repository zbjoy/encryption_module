#include "Request.h"

Request::Request()
{
}

Request::Request(std::string encstr)
{
}

Request::Request(int cmd, std::string clientID, std::string sign, std::string data)
{
}

void Request::initMessage(std::string encstr)
{
}

void Request::initMessage(int cmd, std::string clientID, std::string serverID, std::string sign, std::string data)
{
}

std::string Request::encodeMsg()
{
	return std::string();
}

void* Request::decodeMsg()
{
	return NULL;
}

Request::~Request()
{
}
