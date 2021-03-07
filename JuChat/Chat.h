#pragma once
#include "RegLog.h"
class Chat
{
public:
	void init(RegLog regLog);

private:
	void privateMessage(RegLog regLog);

	std::fstream read;
	std::string messages = "";
	std::string newMessage = "";
	std::ofstream filePublicChat;
	std::ofstream filePrivateMessage;
};