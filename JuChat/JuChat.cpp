#include <iostream>
#include "Registration.h"
#include "Chat.h"

std::vector<std::string> chat;

int main()
{
	Registration registration;
	registration.init();
	Chat chat;
	chat.init(registration);
	return 0;

}
