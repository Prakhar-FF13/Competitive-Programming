#include <iostream>
#include <algorithm>
using namespace std;

typedef struct AVLnode
{
	int val;
	int balance;
	struct AVLnode *left;
	struct AVLnode *right;
}AVL;
AVL *root=NULL;
class AVLTree
{
	public:
		AVL *LLRotation(AVL *ptr)															//Left to Left rotation.
		{
			AVL *aptr;
			aptr=ptr->left;
			ptr->left=aptr->right;
			aptr->right=ptr;
			int lh,rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			ptr=aptr;
			return (ptr);
		}
		AVL *RRRotation(AVL *ptr)															//Right to Right rotation.
		{
			AVL *aptr;
			aptr=ptr->right;
			ptr->right=aptr->left;
			aptr->left=ptr;
			int lh,rh;
			lh=height(aptr->left);
			rh=height(aptr->right);
			aptr->balance=lh-rh;
			lh=height(ptr->left);
			rh=height(ptr->right);
			ptr->balance=lh-rh;
			ptr=aptr;
			return (ptr);
		}
		AVL *LRRotation(AVL *ptr)															//Left to Right rotation.				
		{
			AVL *aptr,*bptr;
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
		AVL *RLRotation(AVL *ptr)															//Right to left rotation.
		{
			AVL *aptr,*bptr;
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
		AVL *balance(AVL *ptr,bool *check)													//For Keeping the AVL Tree property.
		{
			
			if((ptr->balance==1) || (ptr->balance==0) || (ptr->balance==-1))
				return ptr;
			if(ptr->balance > 1)
			{
				if((ptr->balance > 1) && (ptr->left->balance==1))								//Left heavy..
					ptr=LLRotation(ptr);
				else 
					ptr=LRRotation(ptr);
			}
			else
			{	
				if((ptr->balance <-1) && (ptr->right->balance==-1))								//Right heavy..
					ptr=RRRotation(ptr);
				else
					ptr=RLRotation(ptr);
			}
			
			*check=false;
			return ptr;
		}
		int height(AVL *ptr)																//Calculating height of tree.
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
		AVL *insert(AVL *ptr,int data,bool *check)											//Insertion..
		{
			if(ptr==NULL)
			{
				ptr=new AVL;
				ptr->balance=0;
				ptr->val=data;
				ptr->left=NULL;
				ptr->right=NULL;
				return (ptr);
			}
			if((ptr->val) > data)
			{
				ptr->left=insert(ptr->left,data,check);
				int lh=height(ptr->left);
				int rh=height(ptr->right);
				ptr->balance=lh-rh;													//Updating the height of the tree after inserting a new node.
				if(check)
					ptr=balance(ptr,check);
			}
			else
			{
				ptr->right=insert(ptr->right,data,check);
				int lh=height(ptr->left);
				int rh=height(ptr->right);
				ptr->balance=lh-rh;													//Updating the height of the tree after inserting a new node.
				if(check)
					ptr=balance(ptr,check);
			}
			return (ptr);
		}
		void Display(AVL *ptr)
		{
			if(ptr)
			{
				cout<<"{"<<ptr->balance<<","<<ptr->val<<"}"<<" ";
				Display(ptr->left);
				Display(ptr->right);
			}
		}
		void Menu()
		{
			bool check;
			int choice,data;
			do
			{
				cout<<"\n*************Main Menu**************\n";
				cout<<"\n1.Insert an element ";
				cout<<"\n2.Display elements ";
				cout<<"\n3.Exit ";
				cout<<"\n\n  Enter your choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1: cout<<"\n  Enter the data to be inserted : ";
							cin>>data;
							root=insert(root,data,&check);
							break;
					case 2: cout<<"\n  Displaying elements in tree : ";
							AVL *ptr;
							ptr=root;
							cout<<"\n  First number specifies balance factor other number specifies the value the node is holding : \n";
							cout<<"  ";
							Display(ptr);
							break;
					case 3: cout<<"\n  Exiting ....... ";
							break;
					default : cout<<"\n  Wrong choice, Try again ";
							  break;
				}
			}
			while(choice!=3);
		}
};

int main()
{
	AVLTree A;
	A.Menu();
	return 0;
}
