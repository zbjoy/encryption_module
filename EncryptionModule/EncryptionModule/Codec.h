#pragma once
#include <iostream>
#include <string>
#include "msg.pb.h"

class Codec
{
public:
	Codec();
	~Codec();
	virtual std::string encodeMsg(); //�麯��
	virtual void* decodeMsg(); //�麯��
};

