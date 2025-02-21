#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
char c;
	while((c=getch())!='x')
	{
		if(c==0) c=getch();
		printf("You pressed : %d,  %c\n",c,c);
	}
}