#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
	char name[30];
	int age;
	int rollno;
	struct node *next;
}Node;
Node *start=NULL;
struct node *Create(struct node *);
struct node *Display(struct node *);
struct node *Insert_beg(struct node *);
struct node *Insert_end(struct node *);
struct node *Insert_before(struct node *);
struct node *Insert_after(struct node *);
struct node *Del_beg(struct node *);
struct node *Del_node(struct node *);
struct node *Del_after(struct node *);
struct node *Del_lists(struct node *);

int main()
{
	int option;
	do
	{
		printf("\n****************MAIN MENU*****************");
		printf("\n 1:  Create a Lists");
		printf("\n 2:  Display Lists");
		printf("\n 3:  Insert a node at the beginning");
		printf("\n 4:  Insert a node at the end");
		printf("\n 5:  Insert a node before the given node");
		printf("\n 6:  Insert a node after the given node");
		printf("\n 7:  Delete a node from the begining");
		printf("\n 8:  Delete a specific node");
		printf("\n 9:  Delete a node after a specific node");
		printf("\n 10: Delete Lists ");
		printf("\n 11: Enter 11 to quit ");
		
		printf("\n     Enter your choice : ");
		scanf("%d",&option);

		switch(option)
		{
			case 1:start=Create(start);
				printf("\nLinked Lists created\n");
				break;
			case 2:start=Display(start);
				break;
			case 3:start=Insert_beg(start);
				printf("\nNode inserted at the beginning\n");	
				break;
			case 4:start=Insert_end(start);
				printf("\nNode inserted at the end\n");
				break;
			case 5:start=Insert_before(start);
			        printf("\nNode inserted before a given node (before a given rollno)\n");	
				break;
			case 6:start=Insert_after(start);
				printf("\nNode inserted after a given node(before a given rollno)\n");
				break;
			case 7:start=Del_beg(start);
				break;
			case 8:start=Del_node(start);
				break;
			case 9:start=Del_after(start);
				break;
			case 10:start=Del_lists(start);
				break;
		}
	}
	while(option!=11);
	
	return 0;
}


struct node *Create(Node *start)
{
	Node *new_node,*ptr;
	char namen[30];
	int agen,rollnon;
	printf("Enter your name : ");
	scanf("%s",namen);
	printf("Enter age : ");
	scanf("%d",&agen);
	printf("Enter rollno : ");
	scanf("%d",&rollnon);
	
	new_node=(struct node*)malloc(sizeof(Node));
	if(start==NULL)
	{
		new_node->next=NULL;
		strcpy(new_node->name,namen);
		new_node->age=agen;
		new_node->rollno=rollnon;
		start=new_node;
		return start;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new_node;
		new_node->next=NULL;
		strcpy(new_node->name,namen);
		new_node->age=agen;
		new_node->rollno=rollnon;
		
		return start;
	}
}

struct node *Display(Node *start)
{
	int i=1;
	Node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\nLinked Lists is empty ");
	}
	else
	{
		while(ptr->next!=NULL)
		{
		
			printf("\nName of %d person in Linked Lists is : %s",i,ptr->name);
			printf("\nAge of %d person in Linked Lists is : %d",i,ptr->age);
			printf("\nRolllno of %d person in Linked Lists is : %d",i,ptr->rollno);
		
			ptr=ptr->next;
			i++;
		}
		if(ptr->next==NULL)
		{
			printf("\nName of %d person in Linked Lists is : %s",i,ptr->name);
			printf("\nAge of %d person in Linked Lists is : %d",i,ptr->age);
			printf("\nRolllno of %d person in Linked Lists is : %d",i,ptr->rollno);
		}
	}	
	return start;
}
		
struct node *Insert_beg(Node *start)
{
	Node *new_node;
	new_node=(struct node *)malloc(sizeof(Node));
	printf("Enter the name of the person whom you want in your Linked Lists : ");
	scanf("%s",new_node->name);
	printf("Enter the age of that person : ");
	scanf("%d",&new_node->age);
	printf("Enter the rollno of that person : ");
	scanf("%d",&new_node->rollno);
	new_node->next=start;
	start=new_node;
	
	return start;
}

struct node *Insert_end(Node *start)
{
	Node *new_node,*ptr;
	ptr=start;
	new_node=(struct node *)malloc(sizeof(Node));
	printf("Enter the name of the person whom you want to add in your linked lists : ");
	scanf("%s",new_node->name);
	printf("Enter the age of that person : ");
	scanf("%d",&new_node->age);
	printf("Enter the rolno of that person : ");
	scanf("%d",&new_node->rollno);
	new_node->next=NULL;
	while(ptr->next!=NULL)
		ptr=ptr->next;

	ptr->next=new_node;
	return start;
}

struct node *Insert_before(Node *start)
{
	Node *new_node,*ptr,*before;
	int count=0,num;
	printf("Enter a roll number before you want to insert a new node : ");
	scanf("%d",&num);
	new_node=(Node *)malloc(sizeof(Node));
	ptr=start;
	before=start;
	printf("Enter the name of the person whom you want to add in your linked lists : ");
	scanf("%s",new_node->name);
	printf("Enter the age of that person : ");
	scanf("%d",&new_node->age);
	printf("Enter the rolno of that person : ");
	scanf("%d",&new_node->rollno);
	while(ptr->rollno!=num)
	{
		ptr=ptr->next;
		count++;
	}
	new_node->next=ptr;
	while((count-1)>0)
	{
		before=before->next;
		count--;
	}
	before->next=new_node;	
	return start;
}

struct node *Insert_after(Node *start)
{
	int num;
	Node *ptr,*new_node;
	new_node=(Node *)malloc(sizeof(Node));
	ptr=start;
	printf("Enter the roll no after which u want to enter another node : ");
	scanf("%d",&num);
	printf("Enter name of the person : ");
	scanf("%s",new_node->name);
	printf("Enter age of the person : ");
	scanf("%d",&new_node->age);
	printf("Enter roll no of that person : ");
	scanf("%d",&new_node->rollno);
		
	if((ptr->next==NULL) && (ptr->rollno==num))
		ptr->next=new_node;
	else
	{
		while(ptr->rollno!=num)
			ptr=ptr->next;
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
		
	return start;
}

struct node *Del_beg(Node *start)
{
	if(start==NULL)
		printf("Linked Lists is empty canot delete from empty lists :( ");
	else
	{

		Node *ptr;
		printf("Deleting the node from the begining !!!!!!!!  ");
		ptr=start;
		if(start->next==NULL)
			start=NULL;
		else
			start=start->next;
		free(ptr);
		printf("Node deleted ");
	}
	return start;
}

struct node *Del_node(Node *start)
{
	if(start==NULL)
		printf("Linked Lists is empty canot delete from empty lists :( ");
	else
	{
		int count=0,num;
		Node *ptr,*join;
		ptr=start;
		join=start;
		printf("Enter the roll number of the person you want to remove from the lists : ");
		scanf("%d",&num);
		while(ptr->rollno!=num)
		{
			ptr=ptr->next;
			count++;
		}
		while((count-1)>0)
			join=join->next;
		join->next=ptr->next;
		free(ptr);
	}

	return start;
}

struct node *Del_after(Node *start)
{
	if(start->next==NULL)
		printf("Cannot delete after the only element call another function to remove the only element present in string : ");
	else
	{
		Node *ptr,*after;
		int num;
		printf("Enter the rollno after which you want to delete a node : ");
		scanf("%d",&num);
		ptr=start;
		while(ptr->rollno!=num)
			ptr=ptr->next;
		after=ptr->next;
		ptr->next=after->next;
		free(after);
	}
	printf("Node deleted : ");
	return start;
}

struct node *Del_lists(Node *start)
{
	if(start==NULL)
		printf("Linked Lists already empty : ");
	else if(start->next==NULL)
	{
		Node *ptr;
		ptr=start;
		start=NULL;
		free(ptr);
	}
	else
	{
		Node *ptr;
		ptr=start;
		while(ptr->next!=NULL )
		{
			start=start->next;
			free(ptr);
			ptr=start;
		}
	}	
	return start;
}

		

	
	
      









