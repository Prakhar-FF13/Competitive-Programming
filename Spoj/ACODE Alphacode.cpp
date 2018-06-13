#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int64;
string str;
int64 dp[6001];
int64 Ans(int64 index)
{
	if(index==0)
	{
		if(str[index]=='0')
			return 0;
		else
			return 1;
	}
	if(index==1)
	{
		if(str[index]=='0' && str[index-1]!='0')
		{
			if(str[index-1]=='1' || str[index-1]=='2')
			{
				return 1;
			}
			else
				return 0;
		}
		else if(str[index-1]=='0')
			return 0;
		else
		{
			if(str[index-1]<='2' && str[index]<='6')
				return 2;
			else
				return 1;
		}
	}
	else if(dp[index]!=-1)
		return dp[index];
	else
	{
		if(str[index]=='0' && str[index-1]=='0')
			return 0;
		else if(str[index]=='0' && str[index-1]>'2')
			return 0;
		else if(str[index]=='0' && str[index-1]<='2')
		{
			int64 temp=Ans(index-2);
			dp[index]=temp;
			return temp;
		}
		else if(str[index-1]=='0' && str[index]!='0')
		{
			int64 a=Ans(index-1);
			dp[index]=a;
			return a;
		}
		else if(str[index]<='6' && str[index-1] =='2')
		{
			int64 b=Ans(index-1)+Ans(index-2);
			dp[index]=b;
			return b;
		}
		else if(str[index] >'0' && str[index-1]=='1')
		{
			int64 q=Ans(index-1)+Ans(index-2);
			dp[index]=q;
			return q;
		}
		else
		{
			int64 c=Ans(index-1);
			dp[index]=c;
			return c;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	while(1)
	{
		for(int i=0;i<6001;i++)
		dp[i]=-1;
		cin>>str;
		if(str[0]=='0' || str.length()==0)
			break;
		else
		{
			cout<<Ans((int64)str.length()-1);
			cout<<endl;
		}
	}
	return 0;
}
