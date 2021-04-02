#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *next;
};

int main(){
  
  Node *head = NULL; // head pointer
  Node *tail = new Node();  // tail pointer
  // inserting first node 
  tail->data = 5;
  tail->next = NULL;
  head = tail;
  // adding 1 more node
  Node *newNode = new Node();
  newNode->data = 7;
  tail->next = newNode;
  tail = newNode;
  // one more. . .
  newNode = new Node();
  newNode->data = 7;
  tail->next = newNode;
  tail = newNode;
  // printing all the nodes data.
  while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
  }
  
  return 0;
}
