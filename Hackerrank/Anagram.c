#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int checkalpha(char *str1,char *str2)
{
	int i,q=0,j;
	for(i=0;i<strlen(str1);i++)
	{
		for(j=0;j<strlen(str2);j++)
		{
			if(str1[i]==str2[j])
			{
				q++;
				break;
			}
		}
	}
	if(q==strlen(str1))
	{
		printf("\nStrings are anagram of each other " );
		exit(0);
	}
	else
		return;
}
void makeanagram(char *str1,char *str2)
{
	int i,j,q=0;
	for(i=0;i<strlen(str1);i++)
		for(j=0;j<strlen(str1);j++)
			if(str1[i]==str2[j])
			{
				q++;
				break;
			}
		
	printf("Characters to be removed to make strings in anagram are %d \n",strlen(str1)-q);	
	exit(0);
}

int main()
{
	char str1[10000],str2[10000];	
	printf("\nEnter string 1 : ");
	gets(str1);
	printf("Enter string 2 : ");
	gets(str2);
	
	if(strlen(str1)!=strlen(str2))
		printf("Anagram cannot be produced ");
	else
	{		
		checkalpha(str1,str2);
		makeanagram(str1,str2);
	}
	return 0;
}
		
