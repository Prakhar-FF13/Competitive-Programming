#include<stdio.h>
#include<string.h>								
#include<stdlib.h>
void check(char *str)
{
	int i,count=0;
	for(i=0;i<strlen(str)-2;i++)
		if(str[i]==str[i+2])
			count++;
		
	if(count==strlen(str)-2)
	{
		puts(str);
		exit(0);
	}	
}		 
void createnewstr(char *str,char a,char b)
{
	int i,n=0;
	char newstr[100];
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==a || str[i]==b) 
		{
			newstr[n]=str[i];
			n++;
		}
	}
	newstr[n]='\0';
	if(strlen(newstr)>1)
		check(newstr);
}

int main()
{
	int i,j,n;
	char str[100];
	printf("Enter a string : ");
	gets(str);
	for(i=0;i<strlen(str);i++)
		for(j=i+1;j<strlen(str);j++)
			if(str[i]!=str[j])
				createnewstr(str,str[i],str[j]);

	return 0;
}

		






