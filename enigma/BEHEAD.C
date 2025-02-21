#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

char file1[10000][20],file2[10000][20],file1orig[10000][20],file2orig[10000][20];


void main()
{


	int readfile(int,int);
	int a,b,n,anum,bnum,i,j,k;
	char fname1[100],fname2[100],fname3[100],ftemp1[2],ftemp2[2],currword[100];
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;

/*    for(i=0;i<1000;i++)
	{
		file1[i]=(char*)malloc(sizeof(char*));
		file2[i]=(char*)malloc(sizeof(char*));
		file1orig[i]=(char*)malloc(sizeof(char*));
		file2orig[i]=(char*)malloc(sizeof(char*));

	}
*/

    printf("\nEnter the larger  number : ");
	scanf("%d", &a);


		strcpy(fname1,"c:\\tc\\bin\\enigma\\");
		itoa(a,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");

		//snprintf(fname1,sizeof(fname1),"c:\\tc\\bin\\enigma\\",%s,".txt",ftemp1);

		strcpy(fname2,"c:\\tc\\bin\\enigma\\");
		itoa(a-1,ftemp2,10);
		strcat(fname2,ftemp2);
		strcat(fname2,".txt");

		strcpy(fname3,"c:\\tc\\bin\\enigma\\Bhd_out.txt");

		//snprintf(fname2,sizeof(fname2),"c:\\tc\\bin\\enigma\\",%s,".txt",ftemp2);

		printf("\nFname1 is %s",fname1);
		printf("\nFname2 is %s",fname2);

		fp1=fopen(fname1,"r");
		fp2=fopen(fname2,"r");
		fp3=fopen(fname3,"w");

		if(fp1==NULL) { printf("\n Boo1\n"); getch(); exit(1); }
		if(fp2==NULL) { printf("\n Boo2\n"); getch(); exit(1); }
		if(fp3==NULL) { printf("\n Boo3\n"); getch(); exit(1); }

		i=0;
		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
//			printf("\ni=%d, currword = %s new word = %s",i,currword,novowel(currword));

		    for(j=0;j<strlen(currword);j++)
				{
					file1[i][j]=currword[j+1];
				}
				strcpy(file1orig[i],currword);
//				printf("\ngot %s %s" , currword, file1[i]);
//				getch();
			i++;
			anum=i;

		}
		fclose(fp1);

 printf("\n\n\n\n\n reached here \n\n\n");

		i=0;
		while(!feof(fp2))
		{
			fscanf(fp2,"%s",currword);
  //			printf("\ni=%d, currword = %s new word = %s",i,currword,novowel(currword));

				strcpy(file2orig[i],currword);
				strcpy(file2[i],currword);
			i++;
			bnum=i;
		}
		fclose(fp2);
	printf("\nanum=%d, bnum=%d",anum,bnum);
 printf("\n\n\n\n\n reached here \n\n\n");

	for(i=0;i<anum;i++)
	{
		for(j=0;j<bnum;j++)
		{
		   if(strcmp(file1[i],file2[j])==0)
			{
			   printf("\nGot : %s %s ",file1orig[i],file2orig[j]);
			   fprintf(fp3,"\n%s %s",file1orig[i],file2orig[j]);
			}
			
		}
	}


	getch();
}






