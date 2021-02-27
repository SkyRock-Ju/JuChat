#pragma once
#include "RegLog.h"
class Chat
{
public:
	
	void init(RegLog regLog);
private:
	void readFileMessages();
	void openFileMessages();

	std::fstream read;
	std::string messages = "";
	std::string newMessage = "";
	std::ofstream file;
};