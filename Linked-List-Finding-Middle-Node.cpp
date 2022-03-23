#include <iostream>
using namespace std;

// creating node

class Node{
public:
int data;
Node* next;

Node(int data){
  this->data=data;
  Node* next = NULL;
}
};

// insert node to linked list

void insertNode(Node* &head,int position, int data){
  Node* temp = new Node(data);
  Node* current = head;
  if(position==1){
    temp->next=head;
    head=temp;
  }
  else{
    int count=1;
    while(count<position-1){
      current=current->next;
      count++;
    }
    temp->next=current->next;
    current->next=temp;
  }
}

// Printing linked list

void print(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

// Length of Linked list

int getLen(Node* head){
  int count = 0;
  Node* temp = head;
  while(temp!=NULL){
    temp=temp->next;
    count++;
  }
  return count;
}

// Approach 1

void middleNode(Node* head){
  Node* temp = head;
  int elePos;
  if(getLen(head)%2!=0){
    int count = 1;
    elePos = ((getLen(head))/2)+1;
    while(count<elePos){
      temp=temp->next;
      count++;
    }
    cout<<"Middle Node: "<<temp->data<<endl;
  }
  else{
    int count = 1;
    elePos = ((getLen(head))/2)+1;
    while(count<elePos){
      temp=temp->next;
      count++;
    }
    cout<<"Middle Node: "<<temp->data<<endl;
  }
}

// Approach 2

void middleNodePro(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast->next!=NULL&&fast!=NULL){
    fast=fast->next->next;
    slow=slow->next;
  }
  cout<<"Middle Node: "<<slow->data<<endl;
}

int main() {
  Node* node1 = new Node(1);
  Node* head = node1;
  insertNode(head,2,2);
  insertNode(head,3,3);
  insertNode(head,4,4);
  insertNode(head,5,5);
  insertNode(head,6,6);
  print(head);
  middleNodePro(head);
  
}
