#pragma once
#include <string>
#include "Message.h"
class JSONParser
{
public:
	static  Message JSONToMessage(std::string jo);
};

