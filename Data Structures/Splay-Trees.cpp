#include <iostream>
#include <stddef.h>
#include <conio.h>
using namespace std;

typedef struct SPNode
{
	int val;
	struct SPNode *left;
	struct SPNode *right;
	struct SPNode *parent;
}SPN;

class SplayTree
{
	private:
		SPN *root;
	public:
		SplayTree()
		{
			root=NULL;
		}
		void RRotation(SPN *ptr)
		{
			SPN *aptr;
			aptr=ptr->left;
			ptr->left=aptr->right;
			aptr->right=ptr;
			if(ptr->left!=NULL)
				ptr->left->parent=ptr;
			aptr->parent=ptr->parent;
			if(ptr->parent==NULL)
				root=aptr;
			else if(ptr==ptr->parent->left)
				ptr->parent->left=aptr;
			else
				ptr->parent->right=aptr;
			ptr->parent=aptr;	
		}
		void LRotation(SPN *ptr)
		{
			SPN *aptr;
			aptr=ptr->right;
			ptr->right=aptr->left;
			aptr->left=ptr;
			if(ptr->right!=NULL)
				ptr->right->parent=ptr;
			aptr->parent=ptr->parent;
			if(ptr->parent==NULL)
				root=aptr;
			else if(ptr==ptr->parent->left)
				ptr->parent->left=aptr;
			else
				ptr->parent->right=aptr;
			ptr->parent=aptr;
		}
		void *splaying(SPN *ptr)						//Making the last accessed node root of the tree...
		{	
			while(ptr!=root && ptr->parent->parent!=NULL)
			{
				if(ptr->parent==ptr->parent->parent->left && ptr==ptr->parent->left)
				{
					RRotation(ptr->parent);
					RRotation(ptr->parent);
				}
				else if(ptr->parent==ptr->parent->parent->right && ptr==ptr->parent->right)
				{
					LRotation(ptr->parent);
					LRotation(ptr->parent);
				}
				else if(ptr->parent==ptr->parent->parent->left && ptr==ptr->parent->right)
				{
					LRotation(ptr->parent);
					RRotation(ptr->parent);
				}
				else if(ptr->parent==ptr->parent->parent->right && ptr==ptr->parent->left)
				{
					RRotation(ptr->parent);
					LRotation(ptr->parent);
				}
			}
			if(root->left==ptr)
				RRotation(root);
			else if(root->right==ptr)
				LRotation(root);
		}
		void Insertion(int data)
		{
			SPN *node;
			node=new SPN;
			node->left=NULL;
			node->right=NULL;
			node->val=data;
			if(root==NULL)
			{
				node->parent=NULL;
				root=node;
				return;
			}
			else
			{
				SPN *p,*x;
				x=root;
				while(x!=NULL)
				{
					p=x;
					if(data < x->val)
						x=x->left;
					else
						x=x->right;
				}
				node->parent=p;
				if(data < p->val)
					p->left=node;
				else
					p->right=node;
				if(node->parent->parent==NULL && node==node->parent->left)
					RRotation(node->parent);
				else if(node->parent->parent==NULL && node==node->parent->right)
					LRotation(node->parent);
				else
					splaying(node);
				root=node;
			}
		}
		void Display(SPN *x)
		{
			if(x)
			{
				cout<<"{"<<x->val<<",";
				if(x->parent==NULL)
					cout<<" no parent} ";
				else
					cout<<" parent present} ";
				Display(x->left);
				Display(x->right);
			}
		}
		void Menu()
		{
			int choice,n;
			do
			{
				cout<<"\n************* Main Menu ****************\n";
				cout<<"\n1.Enter elements . ";
				cout<<"\n2.Display elements . ";
				cout<<"\n3.Exit . ";
				cout<<"\n  Enter your choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1: cout<<"\n  Enter data to be entered : ";
							cin>>n;
							Insertion(n);
							cout<<"  Node Inserted ";
							break;
					case 2: cout<<"\n Displaying elements--> ";
							cout<<" ";
							SPN *x;
							x=root;
							Display(x);
							break;
					case 3: cout<<"\n  Exiting ";
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
	SplayTree S;
	S.Menu();
	return 0;
}
