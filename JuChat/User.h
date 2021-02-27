#pragma once
#include <string>
#include <vector>

class User
{
public:
	User(std::string username, std::string password);

	std::string getUsername();
	std::string getPassword();
	std::vector<std::string> getMessages();
	void addMessages(std::string message);

private:
	std::string username;
	std::string password;
	std::vector<std::string> messages;
};
