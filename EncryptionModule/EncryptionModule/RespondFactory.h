#pragma once
#include "Codec.h"
#include "CodecFactory.h"
#include "Response.h"
#include <iostream>
#include <string>
#include <memory>

class RespondFactory :
    public CodecFactory
{
public:
    RespondFactory(std::string enc);
    RespondFactory(RespondInfo* info);
    Codec* createCodec();

    ~RespondFactory();

private:

    bool m_flag;
    std::string m_encStr;
    RespondInfo* m_info;
    std::shared_ptr<RespondCodec> m_ptr;
};

