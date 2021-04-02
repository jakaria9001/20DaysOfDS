// adding a new element at the begining of the list.

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* insert(Node* head, int x){
 // definition of insertAtBeg function here 
  
  Node *temp = new Node();
  temp->data = x;
  
  temp->next = head;
  head = temp;  
  
  
}
void printLL(Node* head){
  // to print the values in LL
  cout<<"Elements in LL :\n";
   Node *tmp = head;
   while(tmp!=NULL){
    cout<< tmp->data <<" ";
    tmp = tmp->next;
  }
}
int main(){
  int n,x; cin>>n;
  Node *head = NULL, *temp;
  for(int i=0;i<n;i++){
     cin>>x;
     head = insert(head, x);
     printLL(head);
    cout<<endl;
  }
  printLL(head);
  cout<<endl;
  // inserting 6 at the begining : 
  head = insert(head, 6);
  printLL(head);
  return 0;
}
