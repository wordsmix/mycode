// ashu: complete the empty{} function :
// not completed only for pawns

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "mouse.h"

#define BLACK 0
#define WHITE 1

#define BKING 4
#define BQUEEN 5
#define BKNIGHT 2
#define BBISHOP 3
#define BROOK 1
#define BPAWN 6
#define WKING 44
#define WQUEEN 55
#define WKNIGHT 22
#define WBISHOP 33
#define WROOK 11
#define WPAWN 66

int xint,yint,minix,miniy;
float margin = 79/2;
int a[9][9];
int object_color;

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int i,j;
   char msg[100];
   void drawboard();
   void move(int,int,int,int);
   void initialize();

   initgraph(&gdriver, &gmode, "e:\\progs\\tc\\bgi\\Egavga.bgi");

   xint = ( getmaxx() - 2 * margin ) / 8;
   yint = ( getmaxy() - 2 * margin ) / 8;

   minix = xint / 10;
   miniy = yint / 10;

   outtextxy(10,10,"Sona is a very good girl");
   initialize();
   getch();
//   a[4][7]=0;a[5][6]=0;
   move(2,8,3,6);
   getch();
   move(7,1,6,3);
   getch();
   a[5][7]=0;
   move(6,8,3,5);
   getch();
   a[6][2]=0;
   move(5,1,8,4);
   getch();
   a[8][7]=0;
   move(8,8,8,6);
   getch();
   for(i=1;i<=6;i++)
	{
	   move_piece();
	}
   closegraph();
   return 0;
}
void myline(int x,int y,int xdev1,int ydev1,int xdev2,int ydev2)
{
    line(x+minix*xdev1,y-miniy*ydev1,x+minix*xdev2,y-miniy*ydev2);
}
void myrect(int x,int y,int xdev1,int ydev1,int xdev2,int ydev2)
{
    rectangle(x+minix*xdev1,y-miniy*ydev1,x+minix*xdev2,y-miniy*ydev2);
}
void draw_pawn(int x, int y)
{
    myrect(x,y,2,2,8,4);
    myrect(x,y,4,4,6,6);
    circle(x+minix*5,y-miniy*7,miniy);
    floodfill(x+minix*2+1,y-miniy*2-1,object_color);
    floodfill(x+minix*4+1,y-miniy*4-1,object_color);
    floodfill(x+minix*5,y-miniy*7,object_color);
}
void draw_rook(int x,int y)
{
    int poly[20];
    myrect(x,y,2,1,8,3);
    myrect(x,y,4,3,6,7);
    poly[0]=4;poly[1]=6;
    poly[2]=2;poly[3]=7;
    poly[4]=2;poly[5]=9;
    poly[6]=4;poly[7]=7;
    poly[8]=5;poly[9]=9;
    poly[10]=6;poly[11]=7;
    poly[12]=8;poly[13]=9;
    poly[14]=8;poly[15]=7;
    poly[16]=6;poly[17]=6;
    poly[18]=4;poly[19]=6;

    for(int i=0;i<=19;i++)
    {
	if((i%2)==0)
		poly[i] = x + poly[i]*minix;
	else
		poly[i] = y - poly[i]*miniy;
    }

    fillpoly(10,poly);
    floodfill(x+minix*2+1,y-miniy-1,object_color);
    floodfill(x+minix*4+1,y-miniy*3-1,object_color);
}
void draw_knight(int x,int y)
{
      myrect(x,y,2,1,8,3);
      myline(x,y,3,3,3,3);
      myline(x,y,3,3,6,5);
      myline(x,y,4,5,6,5);
      myline(x,y,4,5,4,6);
      myline(x,y,7,3,7,8);
      myline(x,y,7,8,6,8);
      myline(x,y,6,8,4,6);
      floodfill(x+minix*5+1,y-miniy*2-1,object_color);
      floodfill(x+minix*5+1,y-miniy*1-1,object_color);
      floodfill(x+minix*5+1,y-miniy*6-1,object_color);
}
void draw_bishop(int x,int y)
{
    myline(x,y,3,1,7,1);
    circle(x+minix*5,y-miniy*8,miniy);
    myline(x,y,3,6,5,7);
    myline(x,y,5,7,7,6);
    ellipse(x+minix*3,y-miniy*3.5,270,90,minix,miniy*2.5);
    ellipse(x+minix*7,y-miniy*3.5,90,270,minix,miniy*2.5);
    floodfill(x+minix*5,y-miniy*4,object_color);
    floodfill(x+minix*5,y-miniy*9+2,object_color);
}

void draw_queen(int x,int y)
{
    myrect(x,y,2,1,8,3);
    myrect(x,y,4,3,6,6);
    myrect(x,y,3,7,7,6);
    myline(x,y,3,7,5,9);
    myline(x,y,5,9,7,7);
    floodfill(x+minix*2+1,y-miniy-1,object_color);
    floodfill(x+minix*4+1,y-miniy*6+1,object_color);
    floodfill(x+minix*3+1,y-miniy*7+2,object_color);
    floodfill(x+minix*5,y-miniy*9+2,object_color);
}
void draw_king(int x,int y)
{
   myline(x,y,1,1,2,9);
   myline(x,y,2,9,4,6);
   myline(x,y,4,6,5,7);
   myline(x,y,5,7,6,6);
   myline(x,y,6,6,8,9);
   myline(x,y,8,9,9,1);
   myline(x,y,9,1,1,1);
   circle(x+minix*5,y-miniy*8,miniy);
   floodfill(x+minix*5,y-miniy*5,object_color);
   floodfill(x+minix*5,y-miniy*8,object_color);
}
void draw_object(int x,int y,int object)
{
	if(object>9)
		object_color=EGA_GREEN;
	else
		object_color=EGA_RED;

	setcolor(object_color);
	setfillstyle(9, object_color);
	x--;
	y = margin + y * yint;
	x = margin + x * xint;

	if(object>9)   object = object / 11;
	if(object==1)  draw_rook(x,y);
	if(object==2)  draw_knight(x,y);
	if(object==3)  draw_bishop(x,y);
	if(object==4)  draw_king(x,y);
	if(object==5)  draw_queen(x,y);
	if(object==6)  draw_pawn(x,y);
}

void drawboard()
{
	int i,j;

	cleardevice();

	setcolor(EGA_WHITE);
	rectangle(margin-3,margin-3,getmaxx()-margin+3,getmaxy()-margin+3);
	restrict_mouse(margin-3,margin-3,getmaxx()-margin+3,getmaxy()-margin+3);
	show_mouse();

	for (i=0;i<=7;i++)
	for (j=0;j<=7;j++)
	{
		rectangle(margin+i*xint,margin+j*yint,margin+(i+1)*xint,margin+(j+1)*yint);
		if((i+j)%2==0)
		{
			setfillstyle(SOLID_FILL,EGA_WHITE);
			floodfill(margin+i*xint+1,margin+j*yint+1,EGA_WHITE);
		}
	}

	for(i=1;i<=8;i++)
	for(j=1;j<=8;j++)
	{
		draw_object(i,j,a[i][j]);
//		if(a[i][j] != 0 ) { printf("Sona %d",a[i][j]);
//		getch();            }
	}
}
int opponent(int oldx ,int oldy, int newx , int newy)
{
	 return
	      a[newx][newy]==0 ||
	      (
		    ( a[oldx][oldy] < 10 && a[newx][newy] > 10 )
		 || ( a[oldx][oldy] > 10 && a[newx][newy] < 10 )
	      )
	   ;
}
int empty(int oldx, int oldy , int newx , int newy, int piece)
{
    int i,j,sum=0,xincr=1,yincr=1;
 //   int lowy=oldy, highy=newy;
 //   int lowx=oldx, highx=newx;

    if(oldy>newy) { /*lowy=newy; highy=oldy; */ yincr=-1;}
    if(oldx>newx) { /*lowx=newx; highx=oldx; */ xincr=-1;}

    if ( piece == BROOK )
	{
	  if ( oldx==newx )
	     for(i=oldy+yincr;i!=newy;i+=yincr)
		sum+=a[oldx][i];
	  if ( oldy==newy )
	     for(i=oldx+xincr;i!=newx;i+=xincr)
		sum+=a[i][oldy];
	  return (sum==0);
	}
    if ( piece == BBISHOP )
	{
	  for(i=oldx+xincr,j=oldy+yincr;i!=newx;i+=xincr,j+=yincr)
		       sum+=a[i][j];
	  return (sum==0);
	}

   return 0;
}
int valid_move(int oldx, int oldy , int newx , int newy)
{
    int piece;
    piece = a[oldx][oldy];
    printf("%d",piece);

    if (opponent(oldx,oldy,newx,newy))
    {
	    if ( piece == BROOK || piece == WROOK )
		  return  ( oldx==newx || oldy ==newy )
		       && empty(oldx,oldy,newx,newy,BROOK);

	    if ( piece == BBISHOP || piece == WBISHOP )
		  return  ( abs(oldx-newx) - abs(oldy-newy) == 0)
		       && empty(oldx,oldy,newx,newy,BBISHOP);

	    if ( piece == BKING || piece == WKING )
		  return ( abs(oldx-newx) < 2 && abs(oldy-newy) < 2 );

	    if ( piece == BQUEEN || piece == WQUEEN )
		  return
		   (
			((oldx==newx) || (oldy==newy))
			&& empty(oldx,oldy,newx,newy,BROOK)
		   )
	     ||
		   (
			(abs(oldx-newx) - abs(oldy-newy) == 0)
			&& empty(oldx,oldy,newx,newy,BBISHOP)
		   );
	    if ( piece == BKNIGHT || piece == WKNIGHT )
		return
		   (abs(oldx-newx) + abs(oldy-newy) == 3);
    }
    return 0;
}
void move(int oldx, int oldy , int newx , int newy)
{
     int piece;
     if (valid_move(oldx,oldy,newx,newy))
     {
	piece = a[oldx][oldy];
	a[oldx][oldy] = 0;
	a[newx][newy] = piece;

	drawboard();
     }
     else
	outtextxy(0,0,"Sona ... invalid move");
}

void initialize()
 {
  int i,j;

	for (i=0;i<=7;i++)
	for (j=0;j<=7;j++)
	{
		a[i+1][j+1] = 0;
		a[i+1][2] = 6;          // Black Pawns
		a[i+1][7] = 66;         // White Pawns
	}
	a[1][1] = 1;  a[8][1] = 1;   // Black Rooks
	a[1][8] = 11; a[8][8] = 11;  // White Rooks
	a[2][1] = 2;  a[7][1] = 2;   // Black Knight
	a[2][8] = 22; a[7][8] = 22;  // White Knight
	a[3][1] = 3;  a[6][1] = 3;   // Black Bishop
	a[3][8] = 33; a[6][8] = 33;  // White Bishop
	a[4][1] = 4;    // Black King
	a[4][8] = 44;   // White King
	a[5][1] = 5;    // Black Queen
	a[5][8] = 55;   // White Queen

   drawboard();
}

void move_piece()
{
	int x_src,y_src,x_dst,y_dst,oldx,oldy,newx,newy;
	
	get_left_click_pos(&x_src,&y_src);
    
	oldx=x_src; //Change this
	oldy=y_src; //Change this
	
	get_left_click_pos(&x_dst,&y_dst);
	
	newx=x_dst; //Change this
	newy=y_dst; //Change this

    move(oldx,oldy,newx,newy);

}