	#include <dos.h>
	#include <conio.h>
	#include <stdio.h>
	#include <process.h>
	#include <graphics.h>
	void main()
	{
		int gd=DETECT,gm;

	  union REGS i,o;
	  int button;
	  clrscr();
initgraph(&gd,&gm,"");
	  i.x.ax=0;
  	  int86(0x33,&i,&o);

	 if(o.x.ax==0)
	    printf("No Mouse Available.....");
  	 else
	    printf("Mouse Available......");
	    getch();

		i.x.ax=1;
	  int86(0x33,&i,&o);

	  outtextxy(100,400,"Mouse Pointer in graphics mode!!Press any key to exit");
	  getch();

	  i.x.ax=2;
	  int86(0x33,&i,&o);

	//  restorecrtmode();

// Program to restrict the mouse pointer within a boundary

rectangle(99,49,501,151);

	  i.x.ax=1;
	  int86(0x33,&i,&o);

	  i.x.ax=7;
	  i.x.cx=100;
	  i.x.dx=500;
	  int86(0x33,&i,&o);

	  i.x.ax=8;
	  i.x.cx=50;
	  i.x.dx=150;
	  int86(0x33,&i,&o);

	  while(!kbhit())
	  ;

	  i.x.ax=2;
	  int86(0x33,&i,&o);

	  restorecrtmode();


// Show mouse pointer

  clrscr();

	 i.x.ax=0;
  	 int86(0x33,&i,&o);

  	 if(o.x.ax==0)
         {
	    printf("No Mouse Available.....");
    	    exit(0);
         }

  	 i.x.ax=1;
	 int86(0x33,&i,&o);

getch();

// Program to hide the mouse pointer

i.x.ax=1;
 	   int86(0x33,&i,&o);

	   gotoxy(24,23);
  	   printf("Press any key to hide mouse cursor...");
 	   getch();

	   i.x.ax=2;
 	   int86(0x33,&i,&o);

	   gotoxy(10,23);
	   printf("Mouse cursor is hidden !! Press any key to terminate the program ...");

getch();

//Program to show the position of the mouse pointer

//while(!kbhit())
	  {
	   i.x.ax=3;
	   int86(0x33,&i,&o);
	   gotoxy(2,2);
	   printf("x->co-ordinate=%d     \n y->co-ordinate=%d      ",o.x.cx,o.x.dx);
	  }

	  i.x.ax=2;
	  int86(0x33,&i,&o);
	  printf("\nmouse pos ends here\n");
getch();

//Program to print which mouse button is pressed


	  i.x.ax=1;
	  int86(0x33,&i,&o);

	  gotoxy(24,23);
	  printf("Press any key to exit....");

	  while(!kbhit())
	  {
	    i.x.ax=3;
	    int86(0x33,&i,&o);

	    button=o.x.bx&7;

	    gotoxy(23,11);
	    switch(button)
	    {
	      case 1:
		printf("Left button pressed                                  ");
	      break;

	      case 2:
		printf("Right button pressed                                  ");
	      break;

	      case 4:
		printf("Middle button pressed                                  ");
	      break;

	      case 3:
		printf("Left and Right buttons pressed                          ");
	      break;

	      case 5:
		printf("Left and Middle buttons pressed                          ");
	      break;

	      case 6:
		printf("Right and Middle buttons pressed                          ");
	      break;

	      case 7:
		printf("All the three buttons pressed                          ");
	      break;

	      default:
		printf("No button pressed....");
	    }
	  }

	   i.x.ax=2;
	   int86(0x33,&i,&o);


// Program to set the position of the mouse pointer on the screen
 clrscr();
i.x.ax=3;
	    int86(0x33,&i,&o);

   	    gotoxy(1,1);
	    printf("Current Position:x=%d    y=%d    ",o.x.cx,o.x.dx);

	    gotoxy(15,23);
	    printf("Press any key to set the mouse pointer to (150,100)...");
	    getch();
	    getch();

	    i.x.ax=4;
	    i.x.cx=150;
	    i.x.dx=100;
	    int86(0x33,&i,&o);

 	   gotoxy(15,23);
	   printf("Cursor is set ... press a key to exit                    ");
	   getch();



       }
