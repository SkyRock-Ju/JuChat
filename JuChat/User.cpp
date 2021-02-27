#include "User.h"

User::User(std::string username, std::string password)
{
	this->username = username;
	this->password = password;
}

std::string User::getUsername()
{
	return username;
}


std::string User::getPassword()
{
	return password;
}


std::vector<std::string> User::getMessages()
{
	return messages;
}

void User::addMessages(std::string message)
{
	messages.push_back(message);
}