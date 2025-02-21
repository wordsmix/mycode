#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

double innerarray[100],outerarray[100];
void main()
{
	// Pi is the circumference of the circle with diameter 1
	// Pi would lie between the 2 regular polygons with incircular and circumcircular diameters of 1 respectively
	// As n (Number of sides of the regular polygon) would tend to infinity, Pi would be more and more accurate
	double inner(int);
	double outer(int);
	int n,iterations;
	iterations=30;
	clrscr();
	for (n=2;n<iterations;n++)
	{
		innerarray[n]=0;
		outerarray[n]=0;
	}
	for (n=2;n<iterations;n++)
	{
		printf("\nn=%d\t%.15f\t%.15f",n,inner(n),outer(n));
	}
	getch();
}

double inner(int n)
{
	double perimeter;
	double outer(int);
	if(n==2)
		perimeter=2*sqrt(2);
	else
	{
		if(innerarray[n]!=0)
			perimeter=innerarray[n];
		else
			perimeter=sqrt(inner(n-1)*outer(n));
	}
	innerarray[n]=perimeter;
	return perimeter;
}

double outer(int n)
{
	double perimeter;
	if(n==2)
		perimeter=4;
	else
	{
		if(outerarray[n]!=0)
			perimeter=outerarray[n];
		else
		perimeter=2*inner(n-1)*outer(n-1)/(inner(n-1)+outer(n-1));
	}
	return perimeter;
}