#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void main()
{


	int readfile(int,int);
	int counter,small,n,anum,bnum,i,j,k,first,second;
	char fname1[100],fname2[100],ftemp1[3],currword[20],newword[20],origword[20];
	FILE *fp1;

    strcpy(ftemp1,"aaa");
		strcpy(fname1,"c:\\tc\\bin\\enigma\\");
		itoa(10,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");

	printf("\nFname1 is %s",fname1);
	getch();

		fp1=fopen(fname1,"r");

		if(fp1==NULL) { printf("\n Boo1\n"); getch(); exit(1); }

		i=0;
		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
			if(currword[0]=='a' || currword[0]=='e' || currword[0]=='i' || currword[0]=='o' || currword[0]=='u'  )
			{
			strcpy(origword,currword);


		    for(i=0;i<26;i++)
				{
					counter=0;
					for(j=0;j<10;j++)
					{
						if (currword[j]=='a'+i)
						{
							counter++;
							if ( counter == 1 )
								first=j;
							else if ( counter == 2 )
							{
								second=j;
								currword[first]='1';
								currword[second]='1';
							}
						}

					}
				}

			j=0;
		    for(i=0;i<strlen(currword);i++)
			{
				if(currword[i]!='1')
					newword[j++]=currword[i];
			}
	    newword[j]='\0';

		if(strlen(newword)<4)
				{
//					getch();
					if ( strcmp(newword,"an")==0 )
					{
						printf("\n currword = %s ",origword);
						printf("final-%s-",newword);
						printf("Yes - %s" ,newword);
					}
                } 
			}
		}

 printf("\n\n\nDone. Press any key to continue \n\n\n");

	getch();
}






