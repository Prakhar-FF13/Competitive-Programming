#include <stdio.h>
#include <string.h>
void Revstr(char *str)
{
	if(*str)
	{
		Revstr(str+1);
		printf("%c",*str);
	}
}
int main()
{
	char str[100];
	printf("\nEnter a string : ");
	gets(str);
	printf("Reveresed string is : \n");
	Revstr(str);
	printf("\n");
	return 0;
}

