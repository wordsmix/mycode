#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include <graphics.h>
#include<math.h>
#include<string.h>

static double pi = 22/7;

void main()
{

   int i,j,r,n,k,midx,midy;
   double x[100],y[100];
   int visited[100];
   double theta;
   char str[100];
   int allvisited(int*,int);

   int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver, &gmode, "e:\\progs\\tc\\bgi\\Egavga.bgi");

   r=200; // Radius of the circle


   printf("Enter the number of vertices: ");
   scanf("%d",&n);
   printf("Enter the value of k as in P(n,k): ");
   scanf("%d",&k);

   midx=getmaxx()/2;
   midy=getmaxy()/2;

   line(0,0,1,1);

   for(i=1;i<=n;i++)
   {
	theta = (i-1)*2*pi/n;
	x[i]=r*cos(theta)+midx;
	y[i]=r*sin(theta)+midy;
	visited[i]=0;
   }
   x[0]=x[k];
   y[0]=y[k];

   for(i=1,j=1;allvisited(visited,n)!=1;i=j)
   {
	j=(j+k)%n; if(j==0) j=n;
	if(visited[j]==1)
		j=j+1;
	else
	{
		line(x[i],y[i],x[j],y[j]);
		visited[j]=1;
	}
	delay(10);
   }
   getch();
 }

int allvisited(int* x,int n)
{
	int i,flag = 1;
	for(i=1;i<=n;i++)
	{
		if(x[i]==0)
			flag = 0;
	}
	return flag;
}