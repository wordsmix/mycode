
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

 main()
{


	int readfile(int,int);
	int big,small,n,anum,bnum,i,k,sum;
	char fname1[100],fname2[100],ftemp1[3],currword[20],origword[20];
	FILE *fp1;
	FILE *fp2;

    strcpy(ftemp1,"aaa");
    printf("\nEnter the larger  number : ");
	scanf("%d",&big);

    printf("%d ",big);
	getch();
		strcpy(fname1,"c:\\TURBOC3\\Projects\\enigma\\");
		itoa(big,ftemp1,10);
		strcat(fname1,ftemp1);
		strcat(fname1,".txt");
		strcpy(fname2,"c:\\TURBOC3\\Projects\\enigma\\puzz_out.txt");



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
			//printf("\n currword = %s ",currword);
	    	sum = 0;
			k=0;
		    for(i=0;i<strlen(currword);i++)
				{
					k = currword[i] -'a' + 1;
					sum = sum + k;

					//printf("\t   curlett is %c value is %d", currword[i], k);
					//getch();
					
				}
				//printf("\ncurword is %s value is %d", currword, sum);
					//getch();

			
			if(sum == 63)
				{
					sum = 0;
					for(i=0;i<strlen(currword);i++)
						{
							k = currword[i] -'a' + 1;
							k = 27 - k;
							sum = sum + k;
						//printf("\t   curlett is %c value is %d", currword[i], k);
					//getch();	
							
                            
						}
						//printf("\ncurword is %s value is %d", currword, sum);
					//getch();
					
					printf("\ncurrword is %s value is %d", currword, sum);
					
					if(sum == 126)
						{
							fprintf(fp2,"%s \n" ,currword);
						}
				}
			
	    }
																																																																																																	fclose(fp1);
		fclose(fp2);

 printf("\n\n\nDone. Press any key to continue \n\n\n");

	getch();
}






