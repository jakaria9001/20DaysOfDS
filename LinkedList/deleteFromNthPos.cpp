
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
Node* deleteFromNthPos(Node* head, int n){
    int l = length(head);
    if(n<1 || n>l) { cout<<"Invalid position\n"; return head; }
    if(!head || !head->next) {cout<<"Deleted\n"; return NULL; }
    Node *temp = head;
    for(int i=1;i<n-1;i++)
        temp = temp->next;
    if(n==1) return head->next;
    
    if(temp->next->next == NULL) temp->next = NULL;
    else temp->next = temp->next->next;
    return head;
    
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
    
    // delete from nth position : 
    cout<<"No of queries for deletion: ";
    cin>>q;
    while(q--){
        cout<<"\nEnter position : ";
        int n0; 
        cin>>n0;
        nhead = deleteFromNthPos(nhead, n0);
        printLL(nhead);
    }
    
    return 0;
}
