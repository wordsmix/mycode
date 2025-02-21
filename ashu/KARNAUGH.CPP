#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

int n;
char symbol[5];

void validate()
{
	getch();
}

int calculatesymbols
(char* s)
{
	int i,c=0,var,j;
	c=0;
	for(i=0;i<=strlen(s);i++)
	{
		var=0;
		for(j=0;j<=c;j++)
		{
			if(s[i]==symbol[j] || s[i]=='\'' || s[i]=='+')
			var=1;
		}
		if (var==0)
		symbol[c++]=s[i];
	}
	symbol[c]='\0';
	return strlen(symbol);
}
void bin(int num, int b,char* rev)
{ // Calc the binary representation of int "num" in array "rev" using "b" bits
	int i,c=0;
	for(i=num;i!=0 ;i=(int)(i/2))
		rev[c++]=i%2+'0';

	for(i=1;i<=b;i++)
		rev[c++]='0';

	rev[n]='\0';
}
void replacebits(char* exp, char* eval ,char* v_bits)
{
     strcpy(eval,exp);
     for(int i=0;i<=strlen(eval)-1;i++)
     {
       for(int j=0;j<n;j++)
       {
		if(eval[i]==symbol[j])
			eval[i]=v_bits[j];
       }
     }
     printf("\nf(%s) = %s",v_bits,eval);
}
int evaluate(char* eval)
{
	int i,c=0,j=0,val,fval=0;
	char literal[100][100];
	for(i=0;i<strlen(eval);i++)
	{
		if(eval[i]=='+') // Separating all prod terms
		{
			literal[c++][j]='\0';j=0;
		}
		else
			literal[c][j++]=eval[i];
	}
	literal[c][j]='\0';
	for(i=0;i<=c;i++)
	{
		for(j=0;j<strlen(literal[i]);j++)
		{
			if(literal[i][j]=='\'')    // Applying the NOT a'
			{
				literal[i][j-1]='0'+'1'-literal[i][j-1];
				literal[i][j]=' ';
			}
		}
	}

	for(i=0;i<=c;i++) //If any of the prod term= 0 then 0
	{
		val =1;
		for(j=0;j<strlen(literal[i]);j++)
			if(literal[i][j]=='0')
				val=0;
		fval=fval || val; // If any of the sum terms is 1 then 1
	}

	return fval;
}
void drawmap(int n,int* f)
{
int i,j,row=2,col=4,ind=0;
char ch[5][5],rh[5][5];


if(n==2) { strcpy(ch[0],"0 ");strcpy(ch[1],"1 ");strcpy(rh[0],"0 ");strcpy(rh[1],"1 "); }
if(n==3) { strcpy(rh[0],"0 ");strcpy(rh[1],"1 ");strcpy(ch[0],"00");strcpy(ch[1],"01");strcpy(ch[2],"11");strcpy(ch[3],"10\0"); }
if(n==4) { strcpy(rh[0],"00");strcpy(ch[0],"00");strcpy(rh[1],"01");strcpy(ch[1],"01");strcpy(rh[2],"10");strcpy(ch[2],"11");strcpy(rh[3],"11");strcpy(ch[3],"11"); }


	if(n!=3) row=col=n;

	printf("\n\n       ");for(j=0;j<col;j++) printf("%s  ",ch[j]);
	printf("\n     ษอออ");for(j=1;j<col;j++) printf("หอออ");printf("ป");

	for(i=1;i<row;i++)
	{
		printf("\n     "); for(j=1;j<=col+1;j++) printf("บ   ");
		printf("\n %s  บ",rh[i-1]);
		for(j=1;j<=col;j++) printf(" %d บ",f[ind++]);
		printf("\n     "); for(j=1;j<=col+1;j++) printf("บ   ");
		printf("\n     ฬอออ");for(j=1;j<col;j++)printf("ฮอออ");printf("น");
	}
// Finally the last row
	printf("\n     "); for(j=1;j<=col+1;j++) printf("บ   ");
	printf("\n %s  บ",rh[i-1]);
	for(j=1;j<=col;j++) printf(" %d บ",f[ind++]);
	printf("\n     "); for(j=1;j<=col+1;j++) printf("บ   ");
	printf("\n     ศอออ");for(j=1;j<col;j++)printf("สอออ");printf("ผ");

}
int checkgroup(int twopow, int* f, char grouping[10][5])
{
int i,flag=1,count=0;
   if(twopow==16)
   {
	for(i=1;i<twopow;i++)
		if(f[i]==0)
			flag=0;
	if(flag==1)
		strcpy(grouping[count++],"1");
   }
   return count;
}
void findgroups(int n,int* f)
{
   char grouping[10][5];
   int i,count;

   for(int twopow=pow(2,n);twopow>0;twopow/=2)
   {
	printf("\ntwopow = %d",twopow);
	count = checkgroup(twopow,f,grouping);
	for(i=0;i<count;i++)
		printf("\nGroup %d is %s",i,grouping[i]);
   }
}

void main()
{
	int i,f[100],numgrps;
	char bits[100],exp[100],eval[100];
	clrscr();

	printf("\nEnter expression: ");
	//scanf("%s",exp);
	strcpy(exp,"ab+bc+bca+b\'a\'+b\'c\'+a+b+c+d");
//	strcpy(exp,"ab+ab\'");
	n=calculatesymbols(exp);
	printf("\nf(x) = %s\n",exp);

	for(i=0;i<=pow(2,n)-1;i++)
	{
		strcpy(bits,"");
		bin(i,n,bits);
		replacebits(exp,eval,bits);
		f[i]=evaluate(eval);
		printf(" = %d ",f[i]);
	}

	drawmap(n,f);
	findgroups(n,f);
	validate();
}