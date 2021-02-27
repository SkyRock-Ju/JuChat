#include <iostream>
#include "RegLog.h"
#include "Chat.h"


int main()
{
	RegLog regLog;
	regLog.init();
	Chat chat;
	chat.init(regLog);
	return 0;
}
