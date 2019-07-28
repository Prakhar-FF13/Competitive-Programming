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
    cout<<"\n";
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
        cout<<"Not able to create node\n";
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


int main(){
    Node *head=nullptr, *tail=nullptr;
    int ch,x,y,z;
    while(1){
        cout<<"1.   Insert at the end.\n";
        cout<<"2.   Insert in the front\n";
        cout<<"3.   Display List.\n";
        cout<<"4.   List Length\n";
        cout<<"-1.  To Quit.\n";
        cout<<"\n   Enter Your Choice.\n";
        cin>>ch;
        switch (ch) {
            case 1: insert_at_end(&head, &tail);
                    break;
            case 2: insert_in_front(&head, &tail);
                    break;
            case 3: display_list(&head);
                    break;
            case 4: x = list_length(&head);
                    cout<<"\nLength of List: "<<x<<"\n";
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
