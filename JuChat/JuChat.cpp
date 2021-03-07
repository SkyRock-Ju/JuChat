#include <iostream>
#include "Chat.h"

RegLog regLog;
Chat chat;

int main()
{
	regLog.init();
	chat.init(regLog);
	return 0;
}
