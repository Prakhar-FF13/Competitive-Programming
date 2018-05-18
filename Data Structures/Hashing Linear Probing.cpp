#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef unsigned long long int ull;
#define f(i,n) for(int i=0;i<n;i++)

class HashL
{
	private:
		ull size;
		ull data;
		char *arr;
	public:
		HashL()
		{
			size=40;
			arr=(char *)malloc(sizeof(char)*size);
			f(i,40)
				arr[i]='$';
		}
		void Insert()
		{
			cout<<"\n  Enter the element to be inserted : ";
			cin>>data;
			ull pos=findpos(data);
			arr[pos]=data;
		}
		ull findpos(ull num)
		{
			if(arr[num%size]=='$')
			{
				return (num%size);
			}
			else
			{
				ull i=1;
				while(arr[(num+i)%size]=='$')
					i++;
					
				return (num+i)%size;
			}
		}
		void del()
		{
			ull data;
			cout<<"\n  Enter the data to be deleted : ";
			cin>>data;
			if(arr[data%size]==data)
			{
				arr[data%size]='$';
				return;
			}
			else
			{
				ull i=1,pos=data%size;
				while(arr[(data+i)%size]!=data && (data+i)%size!=pos)
					i++;
					
				if((data+i)%size==pos && arr[(data+i)%size]!=data)
					cout<<"\n  Element not found !";
				else
				{
					arr[(data+i)%size]='$';
					cout<<"\n  Element deleted ";
				}
			}
		}
		void Search()
		{
			ull num;
			cout<<"\n  Enter element to be searched : ";
			cin>>num;
			ull i=0,pos=num%size;
			while(arr[(num+i)%size]!=num && (num+i)%size!=pos && i!=0)
				i++;
			if(arr[(num+i)%size]!=num)
				cout<<"\n  Element not found ";
			else
				cout<<"\n  Element found ";
		}
		void Menu()
		{
			int choice;
			do
			{
				cout<<"\n  ---- Main Menu ---- ";
				cout<<"\n  1.Insert an element into the table ";
				cout<<"\n  2.Delete an element from the table ";
				cout<<"\n  3.Search for an element ";
				cout<<"\n  4.Exit ";
				cout<<"\n  Enter your choice ";
				cin>>choice;
				switch(choice)
				{
					case 1:Insert();
							break;
					case 2:del();
							break;
					case 3:Search();
							break;
					case 4:cout<<"\n  Exiting !!! ";
							break;
					default: cout<<"\n  Wrong choice ";
							break;
				}
			}
			while(choice!=4);
		}
};

int main()
{
	HashL H;
	H.Menu();
	return 0;
}
