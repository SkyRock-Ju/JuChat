#include "Chat.h"

void Chat::init(RegLog regLog)
{
	read.open("D:\\chat\\publicChat\\public.txt", std::ios::in);
	
	while (std::getline(read, messages))
	{
		std::cout << messages << std::endl;
	}
	read.close();
	while (true)
	{
		filePublicChat.open("D:\\chat\\publicChat\\public.txt", std::ios::app);
		std::getline(std::cin, newMessage);


		if (newMessage[0] == '@')
		{
			privateMessage(regLog);
		}
		/*
		if else (newMessage)
		{

		}*/
		else
		{
			filePublicChat << regLog.getUsers()[regLog.currentUser].getUsername() << " says: " << newMessage << std::endl;
			std::cout << regLog.getUsers()[regLog.currentUser].getUsername() << " says: " << newMessage << std::endl;
		}
	}
	filePublicChat.close();
}


void Chat::privateMessage(RegLog regLog)
{
	bool userExist = false;
	for (int i = 0; i < regLog.getUsers().size(); i++)
	{
		if (newMessage.substr(1) == regLog.getUsers()[i].getUsername())
		{
			userExist = true;
			std::string nickname = newMessage.substr(1);
			std::cout << "Private message to " << regLog.getUsers()[i].getUsername() << std::endl;
			filePrivateMessage.open("D:\\chat\\privateMessages\\privateMessages.txt", std::ios::app);
			std::getline(std::cin, newMessage);
			filePrivateMessage << "from[" << regLog.getUsers()[regLog.currentUser].getUsername() << "]to[" << nickname << "]";
			filePrivateMessage << "message=[" << newMessage << "]" << std::endl;
			filePrivateMessage.close();
		}

	}
	if (!userExist)
	{
		std::cout << "user not found" << std::endl;
	}
}
