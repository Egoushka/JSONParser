#pragma once
#include <string>
class Message
{
	std::string id;
	std::string xFrom;
	std::string to;
	std::string xTo;
	std::string subject;
	std::string date;
public:
	Message(std::string id, std::string xFrom, std::string to, std::string xTo, std::string subject, std::string date);
};

