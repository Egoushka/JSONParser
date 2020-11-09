#include "JSONParser.h"
#include<fstream>
#include <list>
Message JSONParser::JSONToMessage(std::string jo) {
	std::string id;
	std::string xFrom;
	std::string to;
	std::string xTo;
	std::string subject;
	std::string date;

	std::string leftLine;
	std::string rightLine;

	int leftIndex = 0;
	bool isLeft = true;
	bool isQuote = false;
	for (int index = 0, lenth = jo.length(); index < lenth; ++index) {
		while (isLeft) {
			if (jo[index] == '\"') {
				isQuote = !isQuote;
				if (!isQuote)
					++index;
			}
			else if (!isQuote && jo[index] == ':') {
				++index;
				isLeft = false;
			}
			else 
				leftLine += jo[index];
			++index;
		}
		if (jo[index] == '{') {

		}
		//when the programme takes the right side
		if (jo[index] == '\"') {
			isQuote = !isQuote;
			continue;
		}
		if (!isQuote && jo[index] == ' ') {
			continue;
		}
		if (!isQuote && jo[index] == ',') {
			isLeft = true;
			if (leftLine == "_id" || leftLine == "") {
				++count;

				switch (count)
				{
				case 1: {
					id = rightLine;
					break;
				}
				case 2: {
					xFrom = rightLine;
					break;
				}
				case 3: {
					to = rightLine;
					break;
				}
				case 4: {
					xTo = rightLine;
					break;
				}
				case 5: {
					subject = rightLine;
					break;
				}
				case 6: {
					date = rightLine;
					break;
				}
				default:
					break;
				}
			}
			continue;
		}
		rightLine += jo[index];
	}
}