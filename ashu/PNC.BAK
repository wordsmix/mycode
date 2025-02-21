#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

#define FILEDIR "E:\\progs\\pnc\\map.txt"

typedef struct map *nodeptr;
struct map
	{
		char name[50], object[50],left, right, up ,down;
		nodeptr next;
	};
nodeptr head;
void printlist(nodeptr);

FILE* searchitem(FILE *fp)
{
  char file_char='a';
  while(!feof(fp))
  {
  file_char=fgetc(fp);
  if ( file_char == '*' )
		return fp;
  }
  return 0;
}

nodeptr makeroom(FILE *fp,char str[50],nodeptr headx)
{
    char c[50];
    nodeptr tmp;
    nodeptr temp= (nodeptr)malloc(sizeof(struct map));
    tmp=headx;
    while(tmp->next != NULL )
	tmp=tmp->next;

    fscanf(fp,"%s",c);    temp->left=c[0];
    fscanf(fp,"%s",c);    temp->right=c[0];
    fscanf(fp,"%s",c);    temp->down=c[0];
    fscanf(fp,"%s",c);    temp->up=c[0];
    strcpy(temp->name,str);
    tmp->next=temp;
    temp->next=NULL;

    return headx;
}

void readmap(nodeptr head)
{

    FILE *fp;
    char c,str[100];
    fp=fopen(FILEDIR,"r");
    clrscr();
    if (fp==NULL)
    {
	printf("File not found\n");
	    exit(0);
    }
    else
    {
	    printf("File Found\n");
	    while(!feof(fp))
	    {
		    printlist(head);

		    fp=searchitem(fp);
		    if (fp==NULL) break;
		    fscanf(fp,"%s",str);
		    printf("\n\n\n\nIn room %s",str);

		    head=makeroom(fp,str,head);
		    getch();
		    }

	    fclose(fp);
    }
}

void main()
{
nosound();
     head =(nodeptr)malloc(sizeof(struct map));
     head->next=NULL;
     head->left=head->right=head->up=head->down='X';
     strcpy(head->name,"HEAD");
     readmap(head);
}
void printlist(nodeptr head)
{
    for(nodeptr tmp = head; tmp->next!=NULL;tmp=tmp->next)
     {
	    if(tmp!=NULL)
	    {
		printf("\n\n        %c",tmp->up);
		printf("\n%c  <--- %s  ---> %c",tmp->left,tmp->name,tmp->right);
		printf("\n        %c",tmp->down);
	    }
     }
}