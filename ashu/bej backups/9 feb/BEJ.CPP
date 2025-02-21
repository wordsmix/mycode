// use xor_put to code animations
// code for pieces falling
// code to check valid move on if three in a row are found.: There is already a check function for that

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include<dos.h>
#include "mouse.h"


int xint,yint,minix,miniy;
float margin = 79/2;
int a[9][9];
int object_color;
int jewel[4] = { 1,2,3,4 };
FILE* fp;
int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int i,j;
   char msg[100];
   void drawboard();
   void move(int,int,int,int);
   void initialize();
   void move_piece();

   initgraph(&gdriver, &gmode, "e:\\progs\\tc\\bgi\\Egavga.bgi");

   fp=fopen("e:\\progs\\tc\\bin\\ashu\\test.txt","w+");
   xint = ( getmaxx() - 2 * margin ) / 8;
   yint = ( getmaxy() - 2 * margin ) / 8;

   minix = xint / 10;
   miniy = yint / 10;

   init_mouse();	
   show_mouse();
   initialize();

   for(i=1;i<=10;i++)
	{
	   drawboard();
	   move_piece();
	   drawboard();
	}
	gotoxy(1,1);
	printf("Press any key to exit ....                                        \n");
	getchar();
	hide_mouse();
	restorecrtmode();
	closegraph();
	return 0;
}

void draw_object(int x,int y,int object)
{
	if(object==1)
		object_color=EGA_GREEN;
	else if (object==2)
		object_color=EGA_BLUE;
	else if (object==3)
		object_color=EGA_RED;
	else if (object==4)
		object_color=EGA_YELLOW;

	setcolor(object_color);
	setfillstyle(9, object_color);
	x--;
	y = margin + y * yint;
	x = margin + x * xint;

    circle(x+minix*5,y-miniy*5,miniy*2);
	floodfill(x+minix*5,y-miniy*5,object_color);
}

void drawboard()
{
	int i,j;
	cleardevice();

	setcolor(EGA_WHITE);
	rectangle(margin-3,margin-3,getmaxx()-margin+3,getmaxy()-margin+3);

	for (i=0;i<=7;i++)
	for (j=0;j<=7;j++)
	{
		rectangle(margin+i*xint,margin+j*yint,margin+(i+1)*xint,margin+(j+1)*yint);
	}

	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
		draw_object(i,j,a[i][j]);
}

int valid_move(int oldx, int oldy , int newx , int newy)
{
     if (abs(oldx-newx)+abs(oldy-newy)==1)
		 return 1;
	 else
		 return 0;
}
void animation_move(int oldx, int oldy , int newx , int newy) 
{
	unsigned size;
	void far *buffer;
	int smallx,smally,bigx,bigy;
	gotoxy(2,2);
    printf("old = (%d,%d ) new = (%d,%d) ",oldx,oldy,newx,newy);
	
//	line(margin+(oldx-1)*xint,margin+(oldy-1)*yint,0,0);
//	line(margin+(oldx)*xint,margin+(oldy)*yint,0,0);

	smallx = oldx >= newx ? newx : oldx;
	bigx = oldx >= newx ? oldx : newx;
	smally = oldy >= newy ? newy : oldy;
	bigy = oldy >= newy ? oldy : newy;

	if(newx==oldx)
	{
		size=imagesize(margin+(oldx-1)*xint,margin+(smally-1)*yint,margin+(oldx)*xint,margin+(smally)*yint);
		buffer=farmalloc(size);
		getimage(margin+(oldx-1)*xint,margin+(smally-1)*yint,margin+(oldx)*xint,margin+(smally)*yint,buffer);
		line(margin+(oldx-1)*xint,margin+(smally-1)*yint,0,0);
		line(margin+(oldx)*xint,margin+(smally)*yint,0,0);
		for(float i=margin+(smally-1)*yint;i<=margin+(bigy-1)*yint;i+=1)
		{
			putimage(margin+(oldx-1)*xint,i,buffer,XOR_PUT);
			putimage(margin+(oldx-1)*xint,i+1,buffer,COPY_PUT);
			sleep(0.5);
			gotoxy(1,1);
//			printf("in loop %f. smally = %d, bigy = %d , yint = %d . old = (%d,%d ) new = (%d,%d) ",i,smally,bigy,yint,oldx,oldy,newx,newy);
//			printf("press any key");
//			getch();
		}
		farfree(buffer);
	}
	if(newy==oldy)
	{
		size=imagesize(margin+(smallx-1)*xint,margin+(oldy-1)*yint,margin+(smallx)*xint,margin+(oldy)*yint);
		buffer=farmalloc(size);
		getimage(margin+(smallx-1)*xint,margin+(oldy-1)*yint,margin+(smallx)*xint,margin+(oldy)*yint,buffer);
		for(float i=margin+(smallx-1)*xint;i<=margin+(bigx-1)*xint;i+=1)
		{
			putimage(i,margin+(newy-1)*yint,buffer,XOR_PUT);
			putimage(i+1,margin+(newy-1)*yint,buffer,COPY_PUT);
			sleep(0.5);
			gotoxy(1,1);
//			printf("in loop %f. smally = %d, bigy = %d , yint = %d . old = (%d,%d ) new = (%d,%d) ",i,smally,bigy,yint,oldx,oldy,newx,newy);
//			printf("press any key");
		}
		farfree(buffer);
	}
	putimage(margin+newx*xint,margin+newy*yint, buffer, COPY_PUT);
}
void move(int oldx, int oldy , int newx , int newy)
{
     if (valid_move(oldx,oldy,newx,newy))
     {
		int temp;
		animation_move(oldx, oldy , newx , newy);
		temp=a[oldx][oldy];
		a[oldx][oldy]=a[newx][newy];
		a[newx][newy]=temp;
		drawboard();
     }
}

int check3()
{
	int i,j;
	for (i=1;i<=8;i++) // Vertical
	for (j=1;j<=6;j++)
	{
		if((a[i][j]==a[i][j+1])&&(a[i][j]==a[i][j+2]))  return 0;
//		printf("\nChecking %d , %d and %d",a[i][j],a[i][j+1],a[i][j+2]);
//		getch();
	}
	for (i=1;i<=6;i++) // Horizontal
	for (j=1;j<=8;j++)
	{
		if((a[i][j]==a[i+1][j])&&(a[i+2][j]==a[i][j]))  return 0;
//		printf("\nChecking %d , %d and %d",a[i][j],a[i+1][j],a[i+2][j]);
//		getch();
	}
	for (i=1;i<=6;i++) // Bottom Left --> Top Right
	for (j=1;j<=6;j++)
	{
		if((a[i][j]==a[i+1][j+1])&&(a[i][j]==a[i+2][j+2]))  return 0;
//		printf("\nChecking %d , %d and %d",a[i][j],a[i+1][j+1],a[i+2][j+2]);
//		getch();
	}
	for (i=3;i<=8;i++) // Top Left to Bottom Right
	for (j=1;j<=6;j++)
	{
		if((a[i][j]==a[i-1][j+1])&&(a[i][j]==a[i-2][j+2]))  return 0;
//		printf("\nChecking %d , %d and %d",a[i][j],a[i-1][j+1],a[i-2][j+2]);
//		getch();
	}
	return 1;
}

void initialize()
 {
  int i,j,counter=0;

    for (i=0;i<=7;i++)
	for (j=0;j<=7;j++)
	{
		a[i+1][j+1] = 100+10*(i+1)+(j+1);
	}

randomize();

	{
		for (i=0;i<=7;i++)
		for (j=0;j<=7;j++)
		{
			a[i+1][j+1] = jewel[rand()%4];
			while(check3()!=1)
			a[i+1][j+1] = jewel[rand()%4];
		}
		counter++;
	 }
	 ;

   for (i=0;i<=7;i++)
	 {
	   for (j=0;j<=7;j++)
	   {
		fprintf(fp,"a[%d][%d] = %d  ",i+1,j+1, a[i+1][j+1]);
	   }
	   fprintf(fp,"\n");
	 }
fprintf(fp,"counter = %d  ",counter);
   fclose(fp);
   drawboard();
   drawboard();
}

void move_piece()
{
	int i,x_src,y_src,x_dst,y_dst,oldx,oldy,newx,newy;

    gotoxy(1,1);
//	printf("Select a piece ....                                        \n");

	get_left_click_pos(&x_src,&y_src);

	for(i=1;i<=8,(margin + i * xint)<=x_src;i++);
	oldx=i;

	for(i=1;i<=8,(margin + i * yint)<=y_src;i++);
	oldy=i;

//    gotoxy(1,1);
//    printf("Selected oldx is %d and oldy is %d                          \n",oldx,oldy);
//    getch();

	get_left_click_pos(&x_dst,&y_dst);

	for(i=1;i<=8,(margin + i * xint)<=x_dst;i++);
	newx=i;

	for(i=1;i<=8,(margin + i * yint)<=y_dst;i++);
	newy=i;

//	gotoxy(1,1);
//	printf("Played to newx is %d and newy is %d                           \n",newx,newy);
// 	getch();

    move(oldx,oldy,newx,newy);

}