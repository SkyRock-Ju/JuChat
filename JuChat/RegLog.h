#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <direct.h>

class RegLog
{
public:
	void init();
	std::vector<User>  getUsers();
	int currentUser = 0;

private:
	bool registrationLettersCheck(std::string username, std::string password);
	std::string name;
	std::string userName;
	std::string pass;
	std::vector <User> users;
	std::string usersAndPass;
	char choose = ' ';

};