#include "Chat.h"

void Chat::init(Registration registration)
{
	read.open("D:\\chat\\public chat\\public.txt", std::ios::in);
	while (std::getline(read, messages))
	{
		std::cout << messages << std::endl;
	}
	while (true)
	{
		std::getline(std::cin, newMessage);
		file.open("D:\\chat\\public chat\\public.txt", std::ios::app);
		file << registration.getUsers()[registration.currentUser].getUsername() << " says: " << newMessage << std::endl;
		std::cout << registration.getUsers()[registration.currentUser].getUsername() << " says: " << newMessage << std::endl;
	}
}
