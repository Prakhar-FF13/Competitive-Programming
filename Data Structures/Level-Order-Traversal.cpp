#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BTN;

class Queue
{
	private:
		BTN *arr;
		int n;
		int rear;
		int front;
	public:
		Queue()
		{
			n=10;
			rear=front=-1;
			arr=new BTN[100];
		}
		
		void EnQueue(BTN *ptr)
		{
			if(rear==-1 && front==-1)
			{
				rear=front=0;
				arr[rear] = *ptr;
			}
			else
			{
				arr[++rear] = *ptr;
			}
		}
		BTN *Deque()
		{
			if(front==-1)
				return NULL;
			else if(front==rear)
			{
				int k=rear;
				front=rear=-1;
				return &arr[k];
			}
			else
			{
				int k;
				k=front;
				front=front+1;
				return &arr[k];
			}
		}
		bool IsEmpty()
		{
			if(front==-1)
				return true;
			return false;
		}
		
		void Display()
		{
			for(int i=0;arr[i].data;i++)
			{
				cout<<" "<<arr[i].data;
			}
		}
		
};



class BinaryTree
{
	private:
		Queue Q;
		BTN *root;
	public:
		BinaryTree()
		{
			root=NULL;
		}
		void Insert()
		{
			int data;
			cout<<"\n  Enter the data to be inserted : ";
			cin>>data;
			if(root==NULL)
			{
				root=new BTN;
				root->data=data;
				root->left=NULL;
				root->right=NULL;	
			}
			else
			{
				BTN *ptr,*tptr,*node;
				ptr=root;
				tptr=root;
				node=new BTN;
				node->data=data;
				node->left=NULL;
				node->right=NULL;
				while(ptr!=NULL)
				{
					tptr=ptr;
					if(data > ptr->data)
						ptr=ptr->right;
					else
						ptr=ptr->left;
				}
				if(data > tptr->data)
					tptr->right=node;
				else
					tptr->left=node;
			}
		}
		void LevelOrderTraversal()
		{
			BTN *ptr,*temp;
			ptr=root;
			Q.EnQueue(ptr);
			while(!Q.IsEmpty())
			{
				temp=Q.Deque();
				cout<<" "<<temp->data<<"\n";
				if(temp->right)
					Q.EnQueue(temp->right);
				if(temp->left)
					Q.EnQueue(temp->left);
			}
		}
		
		void PreorderTraversal(BTN *ptr)
		{
			if(ptr)
			{
				cout<<" "<<ptr->data;
				PreorderTraversal(ptr->left);
				PreorderTraversal(ptr->right);
			}
		}
		
		void Menu()
		{
			int choice;
			do
			{
				cout<<"\n  ********Main Menu*********";
				cout<<"\n1.Insert into Binary Tree ";
				cout<<"\n2.Level Order Traversal ";
				cout<<"\n3.Pre Order Traversal ";
				cout<<"\n4.Exit ";
				cout<<"\n  Enter your choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1: Insert();
							break;
					case 2: LevelOrderTraversal();
							break;
					case 3: BTN *ptr;
							ptr=root;
							PreorderTraversal(ptr);
							break;
					case 4: cout<<"\n  Exiting ";
							break;
					default : cout<<"\n  Wrong choice Try again !!!! ";
								break;
				}
			}
			while(choice!=4);
		}
};

int main()
{
	BinaryTree B;
	B.Menu();
	return 0;
}

