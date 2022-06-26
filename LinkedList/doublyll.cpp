#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
     ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1+getLength(head->next);
}

void insertAthead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        head=new Node(data);
        tail=head;
        return;
    }
    Node* node=new Node(data);
    node->next=head;
    head->prev=node;
    head=node;
}
void insertAttail(Node* &tail,int data){
    if(tail==NULL){
        insertAthead(tail,tail,data);
        return; 
    }
    Node* node=new Node(data);
    node->prev=tail;
    tail->next=node;
    tail=node;
}
void insertAtPosotion(Node* &head,Node* &tail,int data,int position){
Node* node=new Node(data);
if(position==1){
    /*insertAtHead()*/
    return;
}
if(position==getLength()){
    /*insertAtTail()*/
}
int cnt=1;
Node* temp=head;
while(cnt<position-1){
temp=temp->next;
}
Node* flag=temp->next;
temp->next=node;
node->next=flag;
flag->prev=node;
node->prev=temp;

} 
void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    Node* node=new Node(1);
    Node* head=node;
    Node* tail=node;
    insertAthead(head,tail,2);
    insertAthead(head,tail,3);
    insertAthead(head,tail,4);
    insertAthead(head,tail,5);
   
    print(head);
    return 0;
}