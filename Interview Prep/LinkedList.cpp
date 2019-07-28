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

void insert_at_end(Node **head, Node **tail){
    cout<<"Enter the element to be inserted: ";
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
    int ch;
    while(1){
        cout<<"1.   Insert at the end.\n";
        cout<<"2.   Display List.\n";
        cout<<"3.   List Length\n";
        cout<<"-1.  To Quit.\n";
        cout<<"\n   Enter Your Choice.\n";
        cin>>ch;
        switch (ch) {
            case 1: insert_at_end(&head, &tail);
                    break;
            case 2: display_list(&head);
                    break;
            default: break;
        }
        if(ch==-1)
            break;
    }
    return 0;
}
