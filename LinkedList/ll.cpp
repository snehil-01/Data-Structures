#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;

Node(int data){
    this->data=data;
    this->next=NULL;
}
~Node(){
    int value=this->data;
    if(this->next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"memory is free";
}
};

void deleteNode(Node* &head,Node* &tail,int position){
    if(position==1){
        Node* flag=head;
        head=head->next;
        flag->next=NULL;
        delete (flag);
        return;
    }
int cnt=1;
/*Node* temp=head;
while(cnt<position-1){
    temp=temp->next;
    cnt++;
}
 Node* flag=temp->next;
 temp->next=flag->next;
 flag->next=NULL;
 delete (flag);*/
 Node* curr=head;
 Node* prev=NULL;
 while(cnt<position){
    prev=curr;
    curr=curr->next;
 }
 if(curr->next==NULL){
    tail=prev;
 }
 prev->next=curr->next;
  curr->next=NULL;
  delete curr;
}

void insertAtPosition(Node* &head,int k,int data){
    Node* temp=head;
    k--;
    while(k--){
        temp=temp->next;
    }
    Node* flag=temp->next;
    Node* node= new Node(data);
    temp->next=node;
    node->next=flag;
   /* 
    if(k==1){
        insertAtHead();
        return;
    }
    if(k==len-1){
        insertAttail();
        return;
    }
    int cnt=1;
    while(cnt<k-1){
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertAttail();
        return;
    }
    Node* node= new Node(data);
    temp->next=node;
    node->next=flag;
    */
}

void insertAtHead(Node* &head,int data){
Node* temp=new Node(data);
temp->next=head;
head=temp;

}

void insertAttail(Node* &tail,int data){
     Node* node=new Node(data);
    
        tail->next=node;
        tail=tail->next;
    

}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    Node* node=new Node(1);
    Node* head=node;
    Node* tail=node;
    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,4);
    insertAttail(tail,5);
    print(head);
    return 0;
}