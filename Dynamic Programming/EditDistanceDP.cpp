#include <iostream>
using namespace std;

int EditDDP(string s1,string s2)
{
	int m,n;
	m=s1.length()+1;
	n=s2.length()+1;
	int mem[m][n];
	mem[0][0]=0;
	for(int j=1;j<m;j++)
		mem[0][j]=j;
	for(int i=1;i<n;i++)
		mem[i][0]=i;
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(s1[i-1] == s2[j-1])
				mem[i][j]=mem[i-1][j-1];
			else
			{
				mem[i][j]=1+min(mem[i-1][j-1],min(mem[i-1][j],mem[i][j-1]));
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mem[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	return mem[m-1][n-1];
}

int main()
{
	string s1,s2;
	cout<<"\n  Enter string 1 : ";
	cin>>s1;
	cout<<"  Enter string 2 : ";
	cin>>s2;
	cout<<"\n  Minimum number of moves need to convert one string to another is : "<<EditDDP(s1,s2);
	return 0;
}
