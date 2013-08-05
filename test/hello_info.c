#include "gsinfo.h"

int main(void)
{
	GSInfoBox hello;
	hello.size = "200x320";
	hello.info = "Hello World";
	GSInfoBox_Show(&hello);
	return 0;
}
