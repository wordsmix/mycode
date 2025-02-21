#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include <graphics.h>
#include<math.h>
#include<string.h>

#define filename "c:\\kakuro.txt"

int arr[100];

struct node
  {
	int value;
	int left;
	int right;
	int top;
	int bottom;
  };

void main()
{

   int i,j,size,r,n,k,midx,midy,counter=0;
   int **graph=(int**)malloc(100*sizeof(int*));
   int** solution;
   int readfile();
   void calculate(int**,int);
   void drawloop(int**,int);
   void printgraph(int**, int);

   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "e:\\progs\\tc\\bgi\\Egavga.bgi");


   size=readfile();

   for(i=0;i<size;i++)
      graph[i]=(int*)malloc(100*sizeof(int));

   for(i=0;i<size;i++)
    for(j=0;j<size;j++)
      graph[i][j]=arr[counter++];

   printgraph(graph,size);
   calculate(graph,size);
//   printgraph(solution,size);
//   drawloop(solution,size+1);

   getch();
 }
void printgraph(int** gr, int size)
{
int i,j;

   for(i=0;i<size;i++)
   {
	 for(j=0;j<size;j++)
	 {
		printf("g(%d,%d) = %d\t",i,j,gr[i][j]);
	 }
	  printf("\n");
   }
   printf("\n***************************\n");
}

int readfile()
{
	int i=0,size;
	FILE* fp=fopen("c:\\kakuro.txt","r");

	if(fp==NULL) { printf("\n Boo\n"); getch(); exit(1); }
	while(!feof(fp))
		fscanf(fp,"%d",&arr[i++]);
	size=sqrt(i);

   return size;
}

void drawloop(int** gr,int size)
{
  int i,j;
  printgraph(gr,size-1);
}

void calculate(int** gr, int size)
{
  int i,j;
  struct node solution[10][10];

  printgraph(gr,size);
  for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	{
		solution[i][j].value=gr[i][j];
		if(solution[i][j].value==0)
			solution[i][j].left=solution[i][j].right=solution[i][j].top=solution[i][j].bottom=0;
	}

  //LOGICS






}