#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
	char set[100];
	int subset,temp,i;
	printf("\nEnter a set : ");
	gets(set);
	subset=pow(2,strlen(set));
	subset--;
	while(subset) 
	{ 
		printf("{"); 
		temp = subset; 
		for(i = 0; i<strlen(set); i++) 
		{ 
			if (temp & 1) 
				printf("%c", set[i]);
			temp>>=1; 
		} 
		printf("}\n"); 
		subset--; 
	} 
	return 0;
}
