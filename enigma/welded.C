#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void main()
{


//	int readfile(int,int);
	int check_anagram(char [], char []);
	int big,small,n,anum,bnum,i,j,k,wordlen,flag;
	char fname1[100],fname2[100],fname3[100],ftemp1[3],currword1[30],currword2[30],mixword[30],mixword1[30],mixword2[30];
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;

    strcpy(ftemp1,"aaa");
    printf("\nEnter the first  number : ");
	scanf("%d",&big);
	
    printf("\nEnter the second number : ");
	scanf("%d", &small);
	printf("\n Big = %d, small = %d", big, small );

	wordlen = ( big + small ) / 2;

	printf("\n wordlen = %d", wordlen );
    getch();
		strcpy(fname1,"c:\\tc\\bin\\enigma\\");
		itoa(big,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");

		strcpy(fname2,"c:\\tc\\bin\\enigma\\");
		itoa(small,ftemp1,10);
		strcat(fname2,ftemp1);
		strcat(fname2,".txt");

		strcpy(fname3,"c:\\tc\\bin\\enigma\\wld_out.txt");

    	printf("\nFname1 is %s",fname1);
		printf("\nFname2 is %s",fname2);
		printf("\nFname3 is %s",fname3);

		fp1=fopen(fname1,"r");
		fp2=fopen(fname2,"r");
		fp3=fopen(fname3,"w");

		if(fp1==NULL) { printf("\n Boo1\n"); getch(); exit(1); }
		if(fp2==NULL) { printf("\n Boo2\n"); getch(); exit(1); }
		if(fp3==NULL) { printf("\n Boo2\n"); getch(); exit(1); }

		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword1);
  			printf("\ncurrword is %s ",currword1);

			while(!feof(fp2))
			{
				strcpy(mixword,currword1);
				fscanf(fp2,"%s",currword2);
				strcat(mixword,currword2);

				strncpy(mixword1,mixword,wordlen);
				mixword1[wordlen]='\0';

				strncpy(mixword2,mixword+wordlen,wordlen);
				mixword2[wordlen]='\0';

			printf("\ncurrword is %s %s ",currword1,currword2);
			//getchar();

				flag = check_anagram(mixword1, mixword2);
				if (flag == 1)
				{
					fprintf(fp3,"%s\n",mixword);
					printf("\nHi %s",mixword);
					fflush(fp3);
				}

			}
	    rewind(fp2);

		}
 printf("\n\n\nDone. Press any key to continue \n\n\n");
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);

getch();
}



int check_anagram(char a[], char b[])
{
   int first[26] = {0}, second[26] = {0}, c = 0;
 
   while (a[c] != '\0')
   {
      first[a[c]-'a']++;
      c++;
   }
 
   c = 0;
 
   while (b[c] != '\0')
   {
      second[b[c]-'a']++;
      c++;
   }
 
   for (c = 0; c < 26; c++)
   {
      if (first[c] != second[c])
         return 0;
   }
 
   return 1;
}


