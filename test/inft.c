#include "gsinfo.h"

int main(void)
{
	GSInfoBox hello_a;
	hello_a.info = "Hello World!";
		//hello_a.font = "Tomaly";
		//hello_a.fontsize = 15;
		//hello_a.fontcolor = "FFFFFF";
	hello_a.size = "160x190";
		//hello_a.style = "star";
		//hello_a.bgcolor = "EEFF80"; 
	GSInfoBox_show(&hello_a);

	return 0;
}
