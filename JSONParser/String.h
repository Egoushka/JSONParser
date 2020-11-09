#pragma once
#include <iostream>
#include <stdexcept>
class String
{
	int length;
	int size;
public:
	char* string;
	
	String() {
		string = new char[0];
		length = 0;
		size = 0;
	}
	String(char string[]) {
		length = 0;
		for (int index = 0; true; ++index) {
			if (string[index] == '\0')
				break;
			++length;
		}
		size = length;
		string = new char[size];
		for (int index = 0; index <= length; ++index) {
			this->string[index] = string[index];
		}
	}
	String(String& string) {
		length = string.length;
		size = string.size;
		for (int index = 0; index <= length; ++index) {
			this->string[index] = string.string[index];
		}
	}
	int Length() {
		return length;
	}
	char operator[](int index) {
		if (index > length)
			throw std::out_of_range("blah");
		return string[index];
	}
	void operator+(char sym) {
		if (size < length + 1) {
			size *= 2;
			char* tmp = new char[length];

			for (int index = 0; index < length; ++index) {
				tmp[index] = this->string[index];
			}
			this->string = new char[size];
			for (int index = 0; index < length; ++index) {
				this->string[index] = tmp[index];
			}
		}
		string[length] = sym;
		++length;
		string[length] = '\0';
		++length;
	}

	void operator=(String str) {
		if (this->size < str.length) {
			this->size *= 2;
			this->string = new char[this->size];
		}
		this->length = str.length;
		for (int index = 0; index < length; ++index) {
			this->string[index] = str.string[index];
		}
	}
};
