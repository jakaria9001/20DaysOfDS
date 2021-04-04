#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x) , next(NULL) , prev(NULL) {}
};
// advantages: reverse lookup;
// disadvantage: extra memory for prev node;
Node *insertAtBeg(Node *head, int x){
    Node *newnode = new Node(x);
    if(!head) return newnode;
    
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    
    return head;
}
Node *insertAtEnd(Node *head, int x){
    Node *newnode = new Node(x);
    if(!head) return newnode;
    
    Node *temp = head;
    while(temp->next)
        temp = temp->next;
    
    temp->next = newnode;
    newnode->prev = temp;
    
    return head;
}
void printLL(Node *head){
    if(!head){
        cout<<"Empty List\n";
        return;
    }
    
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    
}
void reversePrint(Node *head){
    if(!head){
        // cout<<"Empty List\n";
        return;
    }
    // recursive : 
    reversePrint(head->next);
    cout<<head->data;
    // iterative : 
    /*
    Node *temp = head;
    while(temp->next)
        temp = temp->next;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    
    */
}
int main(){
    
  cout<<"Enter no of operations: ";
  int n; cin>>n;
  int x,ch;
  Node *head = NULL;
  while(n--){
      cout<<"\nEnter value : ";
      cin>>x;
      cout<<"\n1. insertAtBeg, 2. insertAtEnd : ";
      cin>>ch;
      if(ch==1) head = insertAtBeg(head, x);
      else head = insertAtEnd(head, x);
      cout<<"Current List: "
      printLL(head);
  }
}
