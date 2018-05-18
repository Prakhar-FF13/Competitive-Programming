#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *a;
	int top=-1,i;
	a=(char *)calloc(100,sizeof(char));
	printf("\nEnter a string : ");
	scanf("%s",a);
	top=strlen(a)-1;
	while(top>=0)
	{
		if(a[top]==a[top-1])
		{
			for(i=top+1;i<=strlen(a);i++)
				a[i-2]=a[i];
			top=strlen(a)-1;
			if(top==-1)
			{
				printf("Empty String ");
				exit(0);
			}
		}
		else
			top--;
	}
	printf("%s",a);
		
		
	return 0;
}

