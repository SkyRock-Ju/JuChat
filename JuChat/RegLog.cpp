#include "RegLog.h"

RegLog::RegLog()
{
};

bool RegLog::registrationCheck(std::string username, std::string password)
{
	for (int i = 0; i < username.length(); i++)
	{
		if (username.at(i) < 'A' && username.at(i) > 'Z' || username.at(i) < 'a' && username.at(i) > 'z')
		{
			return false;
		}
	}

	for (int j = 0; j < password.length(); j++)
	{
		std::cout << password.length();
		if (password.at(j) < 'A' && password.at(j) > 'Z' || password.at(j) < 'a' && password.at(j) > 'z' ||
			password.at(j) < '0' && password.at(j) > '9')
		{
			return false;
		}
	}
	return true;
}

void RegLog::init()
{
	std::string usersAndPass;
	std::fstream read;
	read.open("D:\\chat\\accounts\\accounts.txt", std::ios::in);
	while (std::getline(read, usersAndPass))
	{
		std::cout << usersAndPass << std::endl;
		for (int i = 0; i < usersAndPass.size(); i++)
		{
			if (usersAndPass[i] == ':')
			{
				users.push_back(User(usersAndPass.substr(0, i), usersAndPass.substr(i + 1)));
			}
		}
	}
	char choose;
	bool check = true;
	while (check)
	{
		std::cout << "Type L to Login or R for registration" << std::endl;
		std::cin >> choose;
		if (choose == 'R')
		{
			//check = false;

			std::cout << "ENTER Username:";
			std::string username;
			std::cin >> username;

			std::cout << "Enter password:";
			std::string password;
			std::cin >> password;

			if (registrationCheck(username, password))
			{
				std::ofstream file;
				file.open("D:\\chat\\accounts\\accounts.txt", std::ios::app);
				file << username << ":" << password << std::endl;
				std::cout << "Successfull registration" << std::endl;
				continue;
			}
		}
		if (choose == 'L')
		{
			if (users.empty())
			{
				std::cout << "User not found";
				continue;
			}

			std::cout << "ENTER Username:";
			std::string username;
			std::cin >> username;

			std::cout << "Enter password:";
			std::string password;
			std::cin >> password;

			for (int i = 0; i < users.size(); i++)
			{
				if (users[i].getUsername() == username && users[i].getPassword() == password) // check if error
				{
					std::cout << users[i].getUsername() << std::endl;
					std::cout << "Successful login" << std::endl;
					currentUser = i;
					check = false;
					return;
				}
			}
		}
		std::cout << "Error, try again." << std::endl;
		continue;
	}
}

std::vector<User> RegLog::getUsers()
{
	return users;
}