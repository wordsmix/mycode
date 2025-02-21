	#include <dos.h>
	#include <conio.h>
	#include <stdio.h>
	#include <process.h>
	#include <graphics.h>
	   #include <alloc.h>
	   #include <dos.h>

	   union REGS i,o;
	   char far *p;

void show_mouse()
   	{
	   i.x.ax=1;
	   int86(0x33,&i,&o);
   	}

 void  	hide_mouse()
  	{
 	   i.x.ax=2;
    	   int86(0x33,&i,&o);
  	}

 void  	get_mouse_pos(int *x,int *y,int *button)
  	{
    	  i.x.ax=3;
    	  int86(0x33,&i,&o);

    	  *x=o.x.cx;
    	  *y=o.x.dx;
    	  *button=o.x.bx&1;
        }

  void	save(int x1,int y1,int x2,int y2)
  	{
    	  unsigned area;

    	  area=imagesize(x1,y1,x2,y2);
	  p=(char far*)farmalloc(area);

    	  if(p==NULL)
    	  {
     	    restorecrtmode();
     	    printf("No Memory...");
	    exit(0);
          }

         getimage(x1,y1,x2,y2,p);
       }

 void      restore(int x1,int y1)
       {
	  putimage(x1,y1,p,OR_PUT);
	  farfree(p);
       }


    void	   main()
	   {

	     int gd=DETECT,gm,button,x1,y1,x2,y2,prevx2,prevy2,x,y;

	     initgraph(&gd,&gm,"");

	     i.x.ax=0;
	     int86(0x33,&i,&o);

	     if(o.x.ax==0)
  	     {
	       printf("No Mouse is available..");
	       exit(0);
	       restorecrtmode();
	     }

	    while(!kbhit())
	    {
	      show_mouse();
	      get_mouse_pos(&x1,&y1,&button);

	      if(button==1)
	      {
	        hide_mouse();

	        x2=x1;
	        y2=y1;

	       save(x1,y1,x2,y2);
	       line(x1,y1,x2,y2);

	       prevx2=x2;
	       prevy2=y2;

	      get_mouse_pos(&x2,&y2,&button);

	      while(button==1)
     	      {
			  if(x2!=prevx2 || y2!=prevy2)
				  {
					setcolor(BLACK);
					line(x1,y1,prevx2,prevy2);
					x=x1<prevx2?x1:prevx2;
					y=y1<prevy2?y1:prevy2;
					restore(x,y);
					setcolor(WHITE);
					save(x1,y1,x2,y2);
					line(x1,y1,x2,y2);
					prevx2=x2;
					prevy2=y2;
				  }
				  get_mouse_pos(&x2,&y2,&button);
			  }
	     farfree(p);
	   }
  	 }
   	 restorecrtmode();
       }

  	