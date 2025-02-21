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
	int a,b,n,anum,bnum;
	long int i,j,k;
	char fname1[100],fname2[100],ftemp1[2],ftemp2[2],currword[20];
	FILE *fp1;
	FILE *fp2;

    for(i=0;i<1000;i++)
	{
		file1[i]=(char*)malloc(sizeof(char*));
		file2[i]=(char*)malloc(sizeof(char*));
		file1orig[i]=(char*)malloc(sizeof(char*));
		file2orig[i]=(char*)malloc(sizeof(char*));

	}


    printf("\nEnter the first number : ");
	scanf("%d", &a);
    printf("\nEnter the second number : ");
	scanf("%d", &b);

//    printf("word is %s", novowel("ashutoshsodhaniisyearlysuper"));

		strcpy(fname1,"c:\\tc\\bin\\enigma\\");
		itoa(a,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");

		//snprintf(fname1,sizeof(fname1),"c:\\tc\\bin\\enigma\\",%s,".txt",ftemp1);

		strcpy(fname2,"c:\\tc\\bin\\enigma\\");
		itoa(b,ftemp2,10);
		strcat(fname2,ftemp2);
		strcat(fname2,".txt");

		//snprintf(fname2,sizeof(fname2),"c:\\tc\\bin\\enigma\\",%s,".txt",ftemp2);

		printf("\nFname1 is %s",fname1);
		printf("\nFname2 is %s",fname2);

		getch();

		fp1=fopen(fname1,"r");
		fp2=fopen(fname2,"r");

		if(fp1==NULL) { printf("\n Boo\n"); getch(); exit(1); }
		if(fp2==NULL) { printf("\n Boo\n"); getch(); exit(1); }

		printf("\nTest1");
		getch();

		i=0;
/*		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
			printf("\n currword = %s ",currword);
		}
*/
		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
//			printf("\ncurrword = %s" ,currword);

				strcpy(file1orig[i],currword);
				strcpy(file1[i],novowel(currword));
			i++;
			anum=i;
			if(i%100==0) { printf("\n%li", i ) ; getch(); }
			else printf("\nstuck%li-%s",i,currword);

		}
		fclose(fp1);

		printf("\nTest2");
		getch();

		i=0;
		while(!feof(fp2))
		{
			fscanf(fp2,"%s",currword);
  //			printf("\ni=%d, currword = %s new word = %s",i,currword,novowel(currword));

				strcpy(file2orig[i],currword);
				strcpy(file2[i],novowel(currword));
			i++;
			bnum=i;
		}
		fclose(fp2);
      //	printf("\nanum=%d, bnum=%d",anum,bnum);

	printf("\nTest2");
	getch();

	for(i=0;i<anum;i++)
	{
		for(j=0;j<bnum;j++)
		{
		   if(strcmp(file1[i],file2[j])==0)
			printf("\nGot : %s %s ",file1orig[i],file2orig[j]);
		}
	}


//	getch();
}




   char* novowel(char* word)
   {
	   char* newword;
	   int i=0,j=0;
	   newword=(char*)malloc(sizeof(char*));

	   for(i=0;word[i]!='\0';i++)

	   {
		   if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='y' )
		   {
			   i=i;
		   }
		   else
		   {
			   newword[j++]=word[i];
		   }
	   }
       newword[j]='\0';
	   return newword;
   }

