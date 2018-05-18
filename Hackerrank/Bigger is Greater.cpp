#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

void Sort(char *arr,int p,int q)
{
	for(int i=p;i<=q-p;i++)
	{
		for(int j=i+1;j<=q-p;j++)
		{
			if(arr[i]>arr[j])
				swap(arr[i],arr[j]);
		}
	}
}
int main()
{
	char str[100];
    int t;
    cin>>t;
    while(t)
        {
        
	cin>>str;
	int posi,posj=-1;
	for(int i=0;str[i+1];i++)
		if(str[i]<str[i+1])
			posi=i;
	
	for(int i=posi+1;str[i];i++)
		if(str[posi]<str[i])
			posj=i;
	if(posj==-1)
	{
		cout<<"no answer"<<endl;
	}
	else
	{
		swap(str[posi],str[posj]);
		Sort(str,posi+1,posj);
		cout<<str<<endl;
	}
	t--;
    }
	return 0;
}
