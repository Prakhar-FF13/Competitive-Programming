#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int value;
    struct node *next;
}Node;

Node* create_node(int elem){
    Node *x = new Node(); // or Node *)malloc(sizeof(Node));
    x->value = elem;
    x->next = NULL;
    return x;
}

void display_list(Node **head){
    Node *temp=*head;
    printf("\n");
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<"\n\n";
}

int list_length(Node **head){
    if((*head) == NULL)
        return 0;
    Node * temp = *head;
    int cnt=0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insert_in_front(Node **head, Node **tail){
    cout<<"\nEnter the element to be inserted: ";
    int x;
    cin>>x;
    Node *newNode = create_node(x);
    if(newNode == NULL){
        cout<<"\nNot able to create node\n";
        return;
    }
    if((*head) == NULL){
        *head = newNode;
        *tail = *head;
        return;
    }
    newNode->next = (*head);
    *head = newNode;
}

void insert_at_end(Node **head, Node **tail){
    cout<<"\nEnter the element to be inserted: ";
    int x;
    cin>>x;
    Node *newNode = create_node(x);
    if(newNode == NULL){
        cout<<"\nNot able to create node\n";
        return;
    }
    if((*head) == NULL){
        *head = newNode;
        *tail = *head;
        return;
    }
    (*tail)->next = newNode;
    *tail = newNode;
}

void insert_at_pos_p(Node **head, Node **tail){
    int len = list_length(head);
    if(len == 0){
        cout<<"\nList not created, enter an elemt to create list\n";
        insert_in_front(head, tail);
        return;
    }
    cout<<"\nEnter a position between [1,"<<len<<"]: ";
    int p,x;
    cin>>p;
    if(p==0 || p>len){
        cout<<"\nLength not in range.. !!\n";
        return;
    }
    cout<<"\nEnter element to be inserted: ";
    cin>>x;
    Node *newNode = create_node(x);
    if(newNode == NULL){
        cout<<"\nCannot create node\n";
        return;
    }
    if((*head)==NULL){
        *head = newNode;
        *tail = *head;
        return;
    }
    if(p==1){
        newNode->next = (*head);
        *head = newNode;
        return;
    }
    if(p==len){
        (*tail)->next = newNode;
        (*tail) = newNode;
        return;
    }
    Node *temp=(*head), *insPtr=(*head);
    int cmp=1;
    while(cmp<p){
        insPtr = temp;
        temp=temp->next;
        cmp++;
    }
    insPtr->next = newNode;
    newNode->next = temp;
}

void delete_from_front(Node **head, Node **tail){
    if((*head) == NULL){
        cout<<"\nList is Empty\n";
        return;
    }
    if((*head)->next == NULL){
        free((*head));
        *head = NULL;
        *tail = NULL;
        return;
    }
    Node *temp=(*head);
    (*head) = (*head)->next;
    free(temp);
}

void delete_from_back(Node **head, Node **tail){
    if((*head) == NULL){
        cout<<"\nList is Empty\n";
        return;
    }
    if((*head)->next == NULL){
        free((*head));
        *head = NULL;
        *tail = NULL;
        return;
    }
    Node *temp=(*head);
    while(temp->next != (*tail)){
        temp = temp->next;
    }
    *tail = temp;
    temp = temp->next;
    (*tail)->next = NULL;
    free(temp);
}

int main(){
    Node *head=nullptr, *tail=nullptr;
    int ch,x,y,z;
    while(1){
        cout<<"1.   Insert at the end.\n";
        cout<<"2.   Insert in the front\n";
        cout<<"3.   Insert at position p\n";
        cout<<"4.   Display List.\n";
        cout<<"5.   List Length\n";
        cout<<"6.   Delete from front\n";
        cout<<"7.   Delete from back\n";
        cout<<"-1.  To Quit.\n";
        cout<<"\n   Enter Your Choice.\n";
        cin>>ch;
        switch (ch) {
            case 1: insert_at_end(&head, &tail);
                    break;
            case 2: insert_in_front(&head, &tail);
                    break;
            case 3: insert_at_pos_p(&head, &tail);
                    break;
            case 4: display_list(&head);
                    break;
            case 5: x = list_length(&head);
                    cout<<"\nLength of List: "<<x<<"\n\n";
                    break;
            case 6: delete_from_front(&head, &tail);
                    break;
            case 7: delete_from_back(&head, &tail);
                    break;
            case -1:cout<<"\n Quitting...\n";
                    break;
            default:cout<<"\nWrong Choice\n";
        }
        if(ch==-1)
            break;
    }
    return 0;
}
