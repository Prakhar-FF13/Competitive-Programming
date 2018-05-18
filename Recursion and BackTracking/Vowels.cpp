#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int k=0;
int vowels(char str[])
{
	if(*str)
	{
		if(*str=='a' || *str=='e' || *str=='i' || *str=='o' || *str=='u' || *str=='A' || *str=='E' || *str=='I' || *str=='O' || *str=='U')
		k++;
		vowels(str+1);
	}
}

int main()
{
	char *str;
	int n;
	cout<<"Enter length of the string : ";
	cin>>n;
	str=new char[n];
	cout<<"Enter the string : ";
	scanf("%[^\n]s",str);
	vowels(str);
	cout<<"Number of vowels in string are : "<<k;
	return 0;
}
