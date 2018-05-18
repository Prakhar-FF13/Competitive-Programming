#include<stdio.h>

int GCD(int a,int b)				
{
	if(b==0)
		return a;
	else if(a>=b && b>0)
		return(a,(a%b));
		
}

int main()
{
	int a,b,gcd;
	printf("\nEnter two positive numbers numbers : ");
	scanf("%d%d",&a,&b);
	if(a>b)
		gcd=GCD(a,b);
	else if(b>a)
		gcd=GCD(b,a);
	else
		gcd=a;

	printf("\nGreatest comon divisor of the numbers %d and %d is :",a,b);
	printf("%d\n",gcd);
	return 0;
}
