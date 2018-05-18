#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int main()
{
	int sent=5,i,days,floor,likes;
	printf("\nEnter number of days during which you want to see how many people liked your advertisement");
	scanf("%d",&days);
	floor=sent/2;
	likes=floor;
	for(i=1;i<days;i++)
	{
		sent=floor*3;
		floor=sent/2;
		likes+=floor;
	}
	printf("\nTotal number of likes upto day %d are %d ",days,likes);
	return 0;

}
