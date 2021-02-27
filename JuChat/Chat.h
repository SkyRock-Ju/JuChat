#pragma once
#include "Registration.h"
class Chat
{
public:
	
	void init(Registration registration);
private:
	std::fstream read;
	std::string messages = "";
	std::string newMessage = "";
	std::ofstream file;
};