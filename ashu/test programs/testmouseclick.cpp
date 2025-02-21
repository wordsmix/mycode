#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "mouse.h"

int main()
{
	int a,b;
	printf("Hello, world\n");

	get_left_click_pos(&a,&b);
	printf("a=%d and b=%d\n");

		get_left_click_pos(&a,&b);
	printf("a=%d and b=%d\n");
		
		get_left_click_pos(&a,&b);
	printf("a=%d and b=%d\n");
		
		get_left_click_pos(&a,&b);
	printf("a=%d and b=%d\n");
		
		get_left_click_pos(&a,&b);
	printf("a=%d and b=%d\n");
	return 0;
}
