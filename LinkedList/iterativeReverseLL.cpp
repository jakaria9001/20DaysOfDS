
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

Node* reverseLL(Node *head){
    cout<<"Linked List reversed iteratively.\n";
    if(!head || !head->next) return head;
    Node *prev = NULL, *next = NULL, *curr = head;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
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
    // printLL(head); 
    Node *nhead = head;
    head = nhead;
    
    // reverse a linked list:
    
    head = reverseLL(head);
    printLL(head);
    
    return 0;
}
