#include <iostream>
using namespace std;

bool Palindrome(char str[],int index,int length)
{
	if(index==(length/2))
		return true;
	else if(str[index]==str[length])
		Palindrome(str,index+1,length-1);
	else
		return false;
}

int main()
{
	char *str;
	int n;
	bool ans;
	cout<<"Enter the size of string : ";
	cin>>n;
	str=new char[n];
	cout<<"Enter the string : ";
	cin>>str;
	ans=Palindrome(str,0,n-1);
	if(ans==1)
		cout<<"TRUE";
	else
		cout<<"FALSE";
	
	return 0;
}
