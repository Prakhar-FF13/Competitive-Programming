#include <bits/stdc++.h>
using namespace std;

typedef struct AVLNode
{
	int data;
	int balance;
	struct AVLNode *left;
	struct AVLNode *right;
}AVN;

class AVLTree
{
	private:
		AVN *root;
	public:
		AVLTree()
		{
			root=NULL;
		}
		AVN *LLRotation(AVN *ptr)
		{
			int lh,rh;
			AVN *aptr;
			aptr=ptr->left;
			ptr->left=aptr->right;
			aptr->right=ptr;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			ptr=aptr;
			return (ptr);
		}
		AVN *RRRotation(AVN *ptr)
		{
			int lh,rh;
			AVN *aptr;
			aptr=ptr->right;
			ptr->right=aptr->left;
			aptr->left=ptr;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			ptr=aptr;
			return (ptr);
		}
		AVN *LRRotation(AVN *ptr)
		{
			AVN *aptr,*bptr;
			aptr=ptr->left;
			bptr=aptr->right;
			aptr->right=bptr->left;
			bptr->left=aptr;
			ptr->left=bptr->right;
			bptr->right=ptr;
			int lh,rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			lh=height(bptr->left);
			rh=height(bptr->right);
			bptr->balance=lh-rh;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			ptr=bptr;
			return (ptr);
		}
		AVN *RLRotation(AVN *ptr)
		{
			AVN *aptr,*bptr;
			aptr=ptr->right;
			bptr=aptr->left;
			aptr->left=bptr->right;
			bptr->right=aptr;
			ptr->right=bptr->left;
			bptr->left=ptr;
			int lh,rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			lh=height(bptr->left);
			rh=height(bptr->right);
			bptr->balance=lh-rh;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			ptr=bptr;
			return (ptr);
		}
		int height(AVN *ptr)
		{
			int h=0;
			if(ptr)
			{
				int lh=height(ptr->left)+1;
				int rh=height(ptr->right)+1;
				h=max(lh,rh);
			}
			return h;
		}
		AVN *balance(AVN *ptr,bool *check)
		{
			if(ptr->balance==1 || ptr->balance==0 || ptr->balance==-1)
				return (ptr);
			if(ptr->balance>1)
			{
				if(ptr->balance>1 && ptr->left->balance==1)
					ptr=LLRotation(ptr);
				else
					ptr=LRRotation(ptr);
			}
			else
			{
				if(ptr->balance<-1 && ptr->right->balance==-1)
					ptr=RRRotation(ptr);
				else
					ptr=RLRotation(ptr);
			}
			*check=false;
			return (ptr);
		}
		AVN *Insert(AVN *ptr,int data,bool *check)
		{
			if(ptr==NULL)
			{
				ptr=new AVN;
				ptr->data=data;
				ptr->left=NULL;
				ptr->right=NULL;
				ptr->balance=0;
				return (ptr);
			}
			if(ptr->data < data)
			{
				ptr->right=Insert(ptr->right,data,check);
				int lh=height(ptr->left);
				int rh=height(ptr->right);
				ptr->balance=lh-rh;
				if(check)
					ptr=balance(ptr,check);
			}
			else
			{
				ptr->left=Insert(ptr->left,data,check);
				int lh=height(ptr->left);
				int rh=height(ptr->right);
				ptr->balance=lh-rh;
				if(check)
					ptr=balance(ptr,check);
			}
			return (ptr);
		}
		void Display(AVN *ptr)
		{
			if(ptr)
			{
				cout<<"{"<<ptr->balance<<","<<ptr->data<<"}";
				Display(ptr->left);
				Display(ptr->right);
			}
		}
		int Count(AVN *ptr,int a,int b)
		{
			if(ptr==NULL)
				return 0;
			if(ptr->data>b)
				Count(ptr->left,a,b);
			else if(ptr->data<a)
				Count(ptr->right,a,b);
			else if(ptr->data>=a && ptr->data<=b)
				return (Count(ptr->left,a,b)+Count(ptr->right,a,b)+1);
		}
		void Menu()
		{
			int choice,data,c;
			bool check;
			do
			{
				cout<<"\n************Main Menu***************\n";
				cout<<"\n1.Enter / Create AVL Tree ";
				cout<<"\n2.Display AVL Tree ";
				cout<<"\n3.Count all elements between a and b ";
				cout<<"\n4.Exit ";
				cout<<"\n  Enter your choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1: cout<<"\n  Enter data to be inserted : ";
							cin>>data;
							root=Insert(root,data,&check);
							cout<<"\n";
							break;
					case 2: cout<<"\n  Displaying elements : ";
							AVN *ptr2;
							ptr2=root;
							Display(ptr2);
							cout<<"\n";
							break;
					case 3: cout<<"\n  Enter two numbers between which you want to count the elements : ";
							int a,b;
							cin>>a>>b;
							AVN *ptr3;
							ptr3=root;
							c=0;
							c=Count(ptr3,a,b);
							cout<<"\n  Count of elements between given numbers : ";
							cout<<c;
							cout<<"\n";
							break;
					case 4: cout<<"\n  Exiting ...!!! ";
							break;
					default: cout<<"\n  Wrong choice, Try again : \n";
						     break;
				}
			}
			while(choice!=4);
		}
};

int main()
{
	AVLTree A;
	A.Menu();
	return 0;
}
