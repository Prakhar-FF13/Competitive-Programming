#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void pangram(char *str,int cstr[])
{
	int i,sum=0;
	for(i=0;i<strlen(str);i++)
		str[i]=tolower(str[i]);
	for(i=0;i<strlen(str);i++)
		if(str[i]>='a' && str[i]<='z')
			cstr[(int)(str[i]-97)]++;
	for(i=0;i<26;i++)
		if(cstr[i]>0)
			sum+=1;

	if(sum==26)
		printf("\nString is pangram \n");
	else
		printf("\nString is not pangram \n");
}
	
int main()
{
	char str[100];
	int cstr[26]={0,0,0};
	printf("\nEnter a string : ");
	gets(str);
	pangram(str,cstr);
	return 0;
}
