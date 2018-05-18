#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
#define LF 4             //Load Factor;

typedef struct ListNode
{
	ull data;
	ListNode *next;
}LS;

typedef struct HashTable
{
	ull tc_ele;
	ull tsize;
	LS **HT;
}H;

class Hash
{
	private:
		H *h;
	public:
		Hash()
		{
			h=(H *)malloc(sizeof(H));
			h->tc_ele=0;
			h->tsize=7;
			h->HT=(LS **)malloc(sizeof(LS *)*h->tsize);
			for(ull i=0;i<h->tsize;i++)
			{
				h->HT[i]=(LS *)malloc(sizeof(LS));
				h->HT[i]->next=NULL;
				h->HT[i]->data=i;
			}
		}
		LS *Allocate(LS *node,ull data)
		{
			node=(LS *)malloc(sizeof(LS));
			node->data=data;
			return node;
		}
		
		H *Insert(H *h,ull data)
		{
			LS *newnode;
			newnode=Allocate(newnode,data);
			newnode->next=h->HT[data%h->tsize]->next;
			h->HT[data%h->tsize]->next=newnode;
			if(h->tc_ele/h->tsize >= LF)
				h=Rehash();
			h->tc_ele++;
			return h;
		}
		H *Rehash()
		{
			H *nh;
			nh->tsize=2*h->tsize;
			nh->HT=(LS **)malloc(sizeof(LS *)*nh->tsize);
			nh->tc_ele=h->tc_ele;
			for(ull i=0;i<h->tsize;i++)
			{
				h->HT[i]=(LS *)malloc(sizeof(LS));
				h->HT[i]->next=NULL;
				h->HT[i]->data=i;
			}
			for(ull i=0;i<h->tsize;i++)
			{
				if(h->HT[i]->next!=NULL)
				{
					LS *temp;
					temp=h->HT[i]->next;
					while(temp)
					{
						nh=Insert(nh,temp->data);
						temp=temp->next;
					}
				}
			}
			return nh;
		}
		
		void Search(ull data)
		{
			if(h->HT[data%h->tsize]->next==NULL)
				cout<<"\n  Element does not exist . ";
			else
			{
				LS *temp;
				temp=h->HT[data%h->tsize]->next;
				while(temp->data!=data)
					temp=temp->next;
				if(temp==NULL)
					cout<<"\n  Element does not exist . ";
				else
					cout<<"\n  Element exists . "; 
			}
		}
		
		void menu()
		{
			ull c;
			ull ele;
			do
			{
				cout<<"\n  --- Main Menu --- ";
				cout<<"\n  1. Insert Elements ";
				cout<<"\n  2. Search for an element ";
				cout<<"\n  0. Quit. ";
				cout<<"\n  Enter your choice : ";
				cin>>c;
				switch(c)
				{
					case 1: cout<<"\n  Enter the element to be inserted : ";
							cin>>ele;
							h=Insert(h,ele);
							break;
					case 2: cout<<"\n  Enter the element to be searched : ";
							cin>>ele;
							Search(ele);
							break;
					case 0: cout<<"\n  Quitting !!! ";
							 break;
					default: cout<<"\n  Wrong choice !! ";
							 break;
				}
			}
			while(c!=0);
		}
};

int main()
{
	Hash obj;
	obj.menu();
	return 0;
}





