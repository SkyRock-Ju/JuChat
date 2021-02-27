#include "Chat.h"

void Chat::init(RegLog regLog)
{
	readFileMessages();
	while (std::getline(read, messages))
	{
		std::cout << messages << std::endl;
	}
	while (true)
	{
		openFileMessages();
		std::getline(std::cin, newMessage);
		file << regLog.getUsers()[regLog.currentUser].getUsername() << " says: " << newMessage << std::endl;
		std::cout << regLog.getUsers()[regLog.currentUser].getUsername() << " says: " << newMessage << std::endl;
	}
}

void Chat::readFileMessages()
{
	read.open("D:\\chat\\public chat\\public.txt", std::ios::in);
}

void Chat::openFileMessages()
{
	file.open("D:\\chat\\public chat\\public.txt", std::ios::app);
}
