#include <iostream>
#include <algorithm>
using namespace std;

void generate(char str[],int index,int length)
{
	if(index==length)
		cout<<str<<" "<<endl;
	else
	{
		int j;
		for(j=index;j<=length;j++)
		{
			swap(str[j],str[index]);
			generate(str,index+1,length);
			swap(str[j],str[index]);
		}
	}
}

int main()
{
	char *str;
	int n;
	cout<<"Enter the length of the string :";
	cin>>n;
	str=new char[n];
	cout<<"Enter string :\n";
	cin>>str;
	generate(str,0,n-1);
}
