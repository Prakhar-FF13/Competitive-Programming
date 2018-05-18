#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <cstring>
using namespace std;

long long int strlenght(string str)
{
	int count=0;
	for(int i=0;str[i];i++)
	{
		count++;
	}
	return count;
}

int main()
{
	string number,numbersq;
	long long int p,q,num,l=0,r=0,count=0;
	cin>>p>>q;
	for(int i=p;i<=q;i++)
	{
		char ch;
		l=0;
		r=0;
		stringstream stm2;
		num=i;
		stm2<<num*num;
		int j=0,k;
		numbersq=stm2.str();
		int len=strlenght(numbersq);
		for(j=0;j<len/2;j++)
		{
			ch=numbersq[j];
			l=l*10;
			l+=atoi(&ch);
		}
		for(k=j;k<len;k++)
		{
			ch=numbersq[k];
			r=r*10;
			r+=atoi(&ch);
		}
		if(l+r==num)
            {
			cout<<num<<" ";
            count++;
        }
		
	}
    if(count==0)
        cout<<"INVALID RANGE";
	return 0;
}
