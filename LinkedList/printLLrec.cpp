
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x) , next(NULL){}
};
Node* insertAtEnd(Node *head, int x){
    Node *tt=head, *temp = new Node(x);
    if(!head){
        head = temp;
        return temp;
    }
    while(tt->next){
        tt = tt->next;
    }
    tt->next = temp;
    return head;
}
int length(Node* head){
    int cnt = 0;
    while(head){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void printLL(Node* head){
    cout<<"Current Linked List:  ";
    if(!head) cout<<"Empty List\n";
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void printLLRecurRev(Node *head){
    if(head== NULL) return;
    printLLRecurRev(head->next);
    cout<<head->data<<" ";
}
void printLLRecur(Node *head){
    if(head==NULL) return;
    
    cout<<head->data<<" ";
    printLLRecur(head->next);
}
int main()
{
    
    Node *head = NULL; // head of the linked list.
    cout<<"Enter initial size: ";
    int n,q; 
    cin>>n;
    cout<<"Enter initial elements: ";
    while(n--){
        int x; cin>>x;
        head = insertAtEnd(head, x);
    }
  
    // head = reverseLL(head);
    printLL(head);
    cout<<"Recursive printing: ";
    printLLRecur(head);
    cout<<"\nRecursive reverse Printing: ";
    printLLRecurRev(head);
    
    return 0;
}
