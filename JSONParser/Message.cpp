#include "Message.h"


Message::Message(std::string id, std::string xFrom, std::string to, std::string xTo, std::string subject, std::string date) {
	this->id = id;
	this->xFrom = xFrom;
	this->to = to;
	this->xTo = xTo;
	this->subject = subject;
	this->date = date;
}