#include <iostream>
#include <cstring>
using namespace std;

int EditDistance(char *str1,char *str2)
{
	if(str1==NULL || *str1=='\0')
		return strlen(str2);
	if(str2==NULL || *str2=='\0')
		return strlen(str1);
		
	if(*str1==*str2)
		return EditDistance(str1+1,str2+1);
		
	int d,r,i;
	d=EditDistance(str1+1,str2);
	r=EditDistance(str1+1,str2+1);
	i=EditDistance(str1+1,str2+1);
	
	return (min(d,min(r,i))+1);
}

int main()
{
	char str1[10000],str2[10000];
	cout<<"\n  Enter string 1 : ";
	cin>>str1;
	cout<<"  Enter string 2 : ";
	cin>>str2;
	cout<<"  String can be made same in "<<EditDistance(str1,str2)<<" moves ";
	return 0;
	
}
