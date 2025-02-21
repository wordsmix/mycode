#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
const N = 1000;

	char *file1[1000],*file2[1000],*file1orig[1000],*file2orig[1000];
	char* novowel(char*);


void main()
{

	int readfile(int,int);
	int a,b,n,anum,bnum,i,j,k;
	char fname1[100],fname[100][20],ftemp[2],ftemp2[2],currword[100];
	char *p;
	FILE *fp1;
	FILE *fp[20];

    for(i=0;i<1000;i++)
	{
		file1[i]=(char*)malloc(sizeof(char*));
		file2[i]=(char*)malloc(sizeof(char*));
		file1orig[i]=(char*)malloc(sizeof(char*));
		file2orig[i]=(char*)malloc(sizeof(char*));

	}


		//snprintf(fname1,sizeof(fname1),"c:\\tc\\bin\\enigma\\",%s,".txt",ftemp1);
		
		strcpy(fname1,"c:\\tc\\bin\\enigma\\allwords.txt");
		printf("\nFname1 is %s",fname1);


		fp1=fopen(fname1,"r");

		if(fp1==NULL) { printf("\n Boo\n"); getch(); exit(1); }

		for (i=0;i<=20;i++)
		{
			strcpy(fname[i],"c:\\tc\\bin\\enigma\\");
			itoa(i,ftemp,10);
			strcat(fname[i],ftemp);
			strcat(fname[i],".txt");
			printf("\n%d : Filename is %s",i,fname[i]);
			fp[i]=fopen(fname[i],"w");
		}


		i=0;
		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
			anum=strlen(currword);
	  	    for (p = currword; *p != '\0'; ++p)
			{
				*p = tolower(*p);
			}
			fprintf(fp[anum],"%s\n",currword);

		}
		fclose(fp1);


		for (i=0;i<=20;i++)
		{
			fclose(fp[i]);
		}

	getch();

}



