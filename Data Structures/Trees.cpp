#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

struct Trees
{
	int data;
	struct Trees *left;
	struct Trees *right;
};
struct Trees* root=NULL;

struct Trees *insert(int data,struct Trees *root)
{
	struct Trees *ptr;
	ptr=new (struct Trees);
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;

	if( root== NULL)
		root=ptr;
	else
	{
		struct Trees *temp;
		struct Trees *ptemp;
		temp=root;
		ptemp=root;
		while(temp!=NULL)
		{
			ptemp=temp;
			if(data < temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(data < ptemp->data)
			ptemp->left=ptr;
		else
			ptemp->right=ptr;
	}

	return root;

}

struct Trees *deleteelement(int data,struct Trees *root)
{
	if(root==NULL)
	{
		cout<<"Trees is empty cannot delete the element requested ";
		return root;
	}
	else
	{
		struct Trees *temp,*ptemp;
		temp=root;
		ptemp=temp;
		while((temp!=NULL) && (temp->data!=data))
		{
			ptemp=temp;
			if(data < temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(temp==NULL)
			cout<<"Element to be deleted is not present in the tree ";
		else if((temp->left==NULL) && (temp->right==NULL))
		{
			if(ptemp->left==temp)
				ptemp->left=NULL;
			else
				ptemp->right=NULL;
			delete temp;
		}
		else if(temp->left==NULL)
		{
			if(ptemp->left==temp)
				ptemp->left=temp->right;
			else
				ptemp->right=temp->right;
		}
		else if(temp->right==NULL)
		{
			if(ptemp->left==temp)
				ptemp->left=temp->left;
			else
				ptemp->right=temp->left;
		}
		else
		{
			struct Trees *successor,*joiner,*ptr;
			ptr=temp;
			successor=ptr;
			while(ptr->right!=NULL)
			{
				successor=ptr;
				ptr=ptr->right;	
			}
			ptr=temp->right;
			while(ptr!=NULL)
			{
				joiner=ptr;
				if(temp->left->data < ptr->data)
					ptr=ptr->left;
				else
					ptr=ptr->right;
			}
			if(temp->left->data < joiner->data)
				joiner->left=temp->left;
			else
				joiner->right=temp->left;
		
			if(ptemp->left==temp)
				ptemp->left=successor;
			else
				ptemp->right=successor;
		}
		return root;
	}
}


void Preorder(struct Trees *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		cout<<" "<<ptr->data;
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
}

void Inorder(struct Trees *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		Inorder(ptr->left);
		cout<<" "<<ptr->data;
		Inorder(ptr->right);
	}
}

void Postorder(struct Trees *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		Postorder(ptr->left);
		Postorder(ptr->right);
		cout<<" "<<ptr->data;
	}
}

void Rotate(struct Trees *ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		struct Trees *temp;
		Rotate(ptr->left);
		Rotate(ptr->right);
		temp=ptr->left;
		ptr->left=ptr->right;
		ptr->right=temp;
	}
}

int main()
{

	int choice;
	int data;
	do
	{
		cout<<"\n";
		cout<<"\n***********MENU**************";
		cout<<"\n1. Create or enter element in tree ";
		cout<<"\n2. Delete an element from tree ";
		cout<<"\n3. Traverse the tree in preorder form ";
		cout<<"\n4. Traverse the tree in inorder form ";
		cout<<"\n5. Traverse the tree in postorder form ";
		cout<<"\n6. Rotate the tree ";
		cout<<"\n7. Exit ";
		
		cout<<"\n   Enter your choice ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: cout<<"\nEnter the value to inserted ";
				cin>>data;
				root=insert(data,root);
				break;
			case 2: cout<<"\nEnter the value to be deleted ";
				cin>>data;
				root=deleteelement(data,root);
				break;
			case 3: struct Trees *ptr;
				ptr=root;
				Preorder(ptr);
				break;
			case 4: struct Trees *ptr1;
				ptr1=root;
				Inorder(ptr1);
				break;
			case 5: struct Trees *ptr2;
				ptr2=root;
				Postorder(ptr2);
				break;
			case 6: Rotate(root);
				break;
			case 7: cout<<"   exiting ";
				break;
			default: cout<<"   wrong choice";
				 break;
		}
	}
	while(choice!=7);
	return 0;
}       

