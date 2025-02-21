
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void main()
{


	int readfile(int,int);
	int big,small,n,anum,bnum,i,j,k;
	char fname1[100],fname2[100],ftemp1[3],currword[20],newword[20],origword[20];
	FILE *fp1;
	FILE *fp2;

    strcpy(ftemp1,"aaa");
    printf("\nEnter the larger  number : ");
	scanf("%d",&big);
	
    printf("\nEnter the smaller number : ");
	scanf("%d", &small);
    printf("%d %d",big,small);
	printf("\n 0 small = %d", small );
    getch();
		strcpy(fname1,"c:\\TURBOC3\\Projects\\enigma\\");
		itoa(big,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");
		strcpy(fname2,"c:\\TURBOC3\\Projects\\enigma\\lb_out.txt");

	

    	printf("\nFname1 is %s",fname1);
		printf("\nFdname2 is %s",fname2);

		fp1=fopen(fname1,"r");
		fp2=fopen(fname2,"w");

		if(fp1==NULL) { printf("\n Boo1\n"); getch(); exit(1); }
		if(fp2==NULL) { printf("\n Boo2\n"); getch(); exit(1); }

		i=0;
		while(!feof(fp1))
		{
			fscanf(fp1,"%s",currword);
			strcpy(origword,currword);
			printf("\n currword = %s ",currword);

		    for(i=0;i<strlen(currword)-1;i++)
				{
					for(j=i+1;j<strlen(currword);j++)
					{
						//printf("curri=%c,currj=%c\n",currword[i],currword[j]);
						//getch();
						if (currword[i]==currword[j])
						{
							currword[i]='1';
						    j=strlen(currword);
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

	    if(strlen(newword)==small)
		fprintf(fp2,"%s %s\n"	,origword,newword);
		}
																																																																																																	fclose(fp1);
		fclose(fp2);

 printf("\n\n\nDone. Press any key to continue \n\n\n");

	getch();
}






