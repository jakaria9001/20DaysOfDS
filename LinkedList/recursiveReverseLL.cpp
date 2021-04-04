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
Node* recursiveReverseLL(Node *head){
    if(!head || !head->next) return head;
    
    Node *newHead = recursiveReverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
    
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
    
    printLL(head);  //Printing LL 
    cout<<"List after reversing Recursively: ";
    head = recursiveReverseLL(head);
    printLL(head);
    
    return 0;
}
