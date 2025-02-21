// check for 4 or 5 balls
// background flood fill and status bar flood fill


#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <alloc.h>
#include<dos.h>
#include "mouse.h"


int xint,yint,minix,miniy,circle_radius,jump_interval,score=0,number_of_moves;
float margin = 79/2;
int a[9][9];
int object_color;
int jewel[4] = { 1,2,3,4 };
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

   xint = ( getmaxy() - 2 * margin ) / 8;
   yint = ( getmaxy() - 2 * margin ) / 8;

   minix = xint / 10;
   miniy = yint / 10;

   circle_radius = miniy*2.25;
   jump_interval=2;
   number_of_moves=10;

   init_mouse();	
   show_mouse();
   initialize();

   for(i=1;i<=number_of_moves;i++)
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

void draw_object(int x,int y,int option)
{
	int object=a[x][y],j;
	if(object==1)
		object_color=EGA_GREEN;
	else if (object==2)
		object_color=EGA_BLUE;
	else if (object==3)
		object_color=EGA_RED;
	else if (object==4)
		object_color=EGA_YELLOW;
	else
		object_color=EGA_BLACK;

	setcolor(object_color);
	setfillstyle(9, object_color);
	x--;
	y = margin + y * yint;
	x = margin + x * xint;

    circle(x+minix*5,y-miniy*5,circle_radius);
	floodfill(x+minix*5,y-miniy*5,object_color);
	if(option==1)
	{
		for (int i=circle_radius;i>=0;i-- )
		{
			circle(x+minix*5,y-miniy*5,i);
			floodfill(x+minix*5,y-miniy*5,object_color);
			setcolor(EGA_BLACK);
			circle(x+minix*5,y-miniy*5,i);
			setcolor(object_color);
/*			for (j=1000;j>=0;j-=50)
			{
				delay(1);
				sound(j);
			}
			for (j=50;j<=1000;j+=50)
			{
				delay(1);
				sound(j);
			}
*/
			delay(20);
		}
//		nosound();
	}
}

void drawboard()
{
	int i,j;
	cleardevice();

	setcolor(EGA_WHITE);
	rectangle(margin-3,margin-3,getmaxy()-margin+3,getmaxy()-margin+3);

	// SCORE AREA 

	rectangle(getmaxy()-margin+3+3,margin-3,getmaxx()-margin+3,getmaxy()-margin+3);
	gotoxy(63,5);
	printf("SONA'S\n");
	gotoxy(59,6);
	printf("BEJEWELED DELUXE");
	gotoxy(63,8);
	printf("SCORE");
	gotoxy(63,9);
	printf("%d",score);

	// STATUS BAR

	line(margin-3,getmaxy()-margin+3+6,getmaxx()-margin+3,getmaxy()-margin+3+6);
	line(margin-3,getmaxy()-margin+3+20,getmaxx()-margin+3,getmaxy()-margin+3+20);
	arc(margin-3,getmaxy()-margin+3+13,90,270,7);
	arc(getmaxx()-margin+3,getmaxy()-margin+3+13,270,90,7);

	line((getmaxx()-2*(margin-3))*score/100,getmaxy()-margin+3+6,(getmaxx()-2*(margin-3))*score/100,getmaxy()-margin+3+20);
	setcolor(EGA_BLUE);
	floodfill((getmaxx()-2*(margin-3))*score/100-1,getmaxy()-margin+3+13,EGA_WHITE);

	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
		draw_object(i,j,0);
   
    setcolor(EGA_BLUE);
	floodfill(1,1,EGA_WHITE);
}

int valid_move(int oldx, int oldy , int newx , int newy)
{
     if (abs(oldx-newx)+abs(oldy-newy)==1)
		 return 1;
	 else
		 return 0;
}
void animate_move(int oldx, int oldy , int newx , int newy) 
{
	unsigned size1,size2;
	void far *buffer1;
	void far *buffer2;
	int smlx,smly,bigx,bigy;

	smlx = oldx >= newx ? newx : oldx;
	bigx = oldx >= newx ? oldx : newx;
	smly = oldy >= newy ? newy : oldy;
	bigy = oldy >= newy ? oldy : newy;

	if(newx==oldx)
	{
		size1=imagesize(margin+(oldx-1)*xint+1,margin+(smly-1)*yint+1,margin+(oldx)*xint-1,margin+(smly)*yint-1);
		size2=imagesize(margin+(oldx-1)*xint+1,margin+(bigy-1)*yint+1,margin+(oldx)*xint-1,margin+(bigy)*yint-1);
		buffer1=farmalloc(size1);
		buffer2=farmalloc(size2);
		getimage(margin+(oldx-1)*xint+1,margin+(smly-1)*yint+1,margin+(oldx)*xint-1,margin+(smly)*yint-1,buffer1);
		getimage(margin+(oldx-1)*xint+1,margin+(bigy-1)*yint+1,margin+(oldx)*xint-1,margin+(bigy)*yint-1,buffer2);
		for(float i=margin+(smly-1)*yint+1,j=margin+(bigy-1)*yint+1;i<=margin+(bigy-1)*yint;i+=jump_interval,j-=jump_interval)
		{
			putimage(margin+(oldx-1)*xint+1,i+1,buffer1,XOR_PUT);
			putimage(margin+(oldx-1)*xint+1,i+1+1,buffer1,COPY_PUT);
			putimage(margin+(oldx-1)*xint+1,j+1,buffer2,XOR_PUT);
			putimage(margin+(oldx-1)*xint+1,j-1+1,buffer2,COPY_PUT);
		}
		farfree(buffer1);
		farfree(buffer2);
	}
	if(newy==oldy)
	{
		size1=imagesize(margin+(smlx-1)*xint+1,margin+(oldy-1)*yint+1,margin+(smlx)*xint-1,margin+(oldy)*yint-1);
		size2=imagesize(margin+(bigx-1)*xint+1,margin+(oldy-1)*yint+1,margin+(bigx)*xint-1,margin+(oldy)*yint-1);
		buffer1=farmalloc(size1);
		buffer2=farmalloc(size2);
		getimage(margin+(smlx-1)*xint+1,margin+(oldy-1)*yint+1,margin+(smlx)*xint-1,margin+(oldy)*yint-1,buffer1);
		getimage(margin+(bigx-1)*xint+1,margin+(oldy-1)*yint+1,margin+(bigx)*xint-1,margin+(oldy)*yint-1,buffer2);
		for(float i=margin+(smlx-1)*xint,j=margin+(bigx-1)*xint;i<=margin+(bigx-1)*xint;i+=jump_interval,j-=jump_interval)
		{
			putimage(i+1,margin+(newy-1)*yint+1,buffer1,XOR_PUT);
			putimage(i+1+1,margin+(newy-1)*yint+1,buffer1,COPY_PUT);
			putimage(j+1,margin+(newy-1)*yint+1,buffer2,XOR_PUT);
			putimage(j-1+1,margin+(newy-1)*yint+1,buffer2,COPY_PUT);
		}
		farfree(buffer1);
		farfree(buffer2);
	}
	putimage(margin+newx*xint,margin+newy*yint, buffer1, COPY_PUT);
}
void move(int oldx, int oldy , int newx , int newy)
{
	 void collapse_and_fall();
	 int check3();
     if (valid_move(oldx,oldy,newx,newy))
     {
		int temp;
		animate_move(oldx, oldy , newx , newy);
		temp=a[oldx][oldy];
		a[oldx][oldy]=a[newx][newy];
		a[newx][newy]=temp;
		drawboard();
		if(check3()==1) animate_move(newx , newy,oldx, oldy );
		while(check3()!=1)
		 {
			collapse_and_fall();
			drawboard();
			sleep(0.5);
		 }
     }
}

int check3()
{
	int i,j;
	for (i=1;i<=8;i++) // Vertical
	for (j=1;j<=6;j++)
	{
		if((a[i][j]==a[i][j+1])&&(a[i][j]==a[i][j+2]))  return 0;
	}
	for (i=1;i<=6;i++) // Horizontal
	for (j=1;j<=8;j++)
	{
		if((a[i][j]==a[i+1][j])&&(a[i+2][j]==a[i][j]))  return 0;
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

    move(oldx,oldy,newx,newy);

}
void collapse_and_fall()
{
	void collapse(int,int);
	unsigned long size1;
	void *buffer1;
	int i,j,k;
	for (i=1;i<=8;i++) // Vertical
	for (j=1;j<=6;j++)
	{
		if((a[i][j]==a[i][j+1])&&(a[i][j]==a[i][j+2]))  
		{
			collapse(i,j);collapse(i,j+1);collapse(i,j+2);
			score+=10;
			
			size1=imagesize(margin+(i-1)*xint+1,margin+1,margin+(i)*xint-1,margin+(j-1)*yint-1);
			buffer1=malloc(size1);
			getimage(margin+(i-1)*xint+1,margin+1,margin+(i)*xint-1,margin+(j-1)*yint-1,buffer1);
				for(float ii=margin+1;ii<=margin+(3)*yint;ii+=jump_interval)
				{
					putimage(margin+(i-1)*xint+1,ii+1,buffer1,XOR_PUT);
					putimage(margin+(i-1)*xint+1,ii+1+1,buffer1,COPY_PUT);
				}
			free(buffer1);

			for(k=j+2;k>3;k--)
			{
				a[i][k]=a[i][k-3];
			}
			a[i][1]=jewel[rand()%4];
			a[i][2]=jewel[rand()%4];
			a[i][3]=jewel[rand()%4];
			drawboard();

		}
	}
	for (i=1;i<=6;i++) // Horizontal
	for (j=1;j<=8;j++)
	{
		if((a[i][j]==a[i+1][j])&&(a[i+2][j]==a[i][j]))
		{
			collapse(i,j);collapse(i+1,j);collapse(i+2,j);
			score+=10;

			size1=imagesize(margin+(i-1)*xint+1,margin+1,margin+(i+2)*xint-1,margin+(j-1)*yint-1);
			buffer1=malloc(size1);
			getimage(margin+(i-1)*xint+1,margin+1,margin+(i+2)*xint-1,margin+(j-1)*yint-1,buffer1);
			for(float ii=margin+1;ii<=margin+(1)*yint;ii+=jump_interval)
			{
				putimage(margin+(i-1)*xint+1,ii+1,buffer1,XOR_PUT);
				putimage(margin+(i-1)*xint+1,ii+1+1,buffer1,COPY_PUT);
			}
			free(buffer1);

			for(k=j;k>=1;k--)
			{
				a[i][k]=a[i][k-1];
				a[i+1][k]=a[i+1][k-1];
				a[i+2][k]=a[i+2][k-1];
			}
			a[i][1]=jewel[rand()%4];
			a[i+1][1]=jewel[rand()%4];
			a[i+2][1]=jewel[rand()%4];
			drawboard();
		}
	}
	drawboard();
}
void collapse(int i,int j)
{
	draw_object(i,j,1);
	a[i][j] = 100+10*(i+1)+(j+1);
}
