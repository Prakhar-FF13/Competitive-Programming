#include<stdio.h>

int main()
{
	int n,i,ans=0;
	int c[100],count[100];
	printf("\nEnter total number of socks (max 100) \n");
	scanf("%d",&n);

	printf("\nEnter socks type one by one \n");
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	
	for(i=0;i<n;i++)
		count[i]=0;

	for(i=0;i<n;i++)
		count[c[i]]++;

	for(i=0;i<n;i++)
		ans+=(count[i]/2);


	printf("\nTotal pair of socks he can sell is = %d",ans);

	return 0;
}
	


