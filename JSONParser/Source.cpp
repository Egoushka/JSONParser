#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <json-develop/single_include/nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
	std::ifstream ist("mails.json");
	json j;

	std::string str;
	int index = 0;
	int size;
	ist.seekg(0, std::ios::end);
	size = ist.tellg();
	ist.seekg(0, std::ios::beg);
	char* buf = new char[size];
	ist.getline(buf, size);

	buf[size] = '\0';
	//for (int i = 0; i < size - 1; ++i) {
	//	if (buf[i] == '\r' || buf[i + 1] == '\n' || buf[i] == '\"' || buf[i] == '\t' || buf[i] == '\r\n' || buf[i] == '\r\n\t') {
	//		buf[i] = ' ';
	//	}
	//}

	std::string s = buf;
	std::cout << s;
	j += json::parse(buf);
	for (int i = 0, length = j.size(); i < length; ++i) {
		for (json::iterator it = j[i].begin(); it != j[i].end(); ++it) {
			if (it.key() == "_id")
				std::cout << *it << '\n';
		}
	}
	/*int  ir = 0;
	json s = j["_id"];
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		std::cout << s[ir]["$oid"] << '\n';
		++ir;
	}
	std::string responseString = R"({"response":[{"id":210700286,"first_name":"Lindsey","last_name":"Stirling"}]})";
	json responseJson = json::parse(responseString);
	json object = responseJson["response"];
	std::string first_name = object[0]["first_name"];
	std::string last_name = object[0]["last_name"];
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;*/
	return 0;
}