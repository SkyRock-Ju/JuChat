#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


class Registration
{
public:
	Registration();

	void init();
	std::vector<User>  getUsers();
	int currentUser = 0;

private:
	bool registrationCheck(std::string username, std::string password);
	std::string name;
	std::string userName;
	std::string pass;
	std::vector <User> users;
};