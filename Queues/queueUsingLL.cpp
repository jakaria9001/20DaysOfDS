// Queue using Linked List: 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL){}
};
Node *head = NULL;

bool isempty(){
    if(head==NULL) return  true;
    return false;
}
void enqueue(int x){
    Node *newnode = new Node(x);
    if(!head) head = newnode;
    else {
        Node *temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
    
    cout<<"Enqueue Successful"<<endl;
}
void dequeue(){
    if(isempty()) return;
    
    Node *temp = head;
    head = temp->next;
    delete(temp);
    
    cout<<"Dequeue Successful"<<endl;
}
int frontQ(){
    if(isempty()) return -1;
    return head->val;
}

void printQ(){
    if(isempty()) return;
    cout<<"Current elements in Queue: ";
    Node *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
    
}
int main()
{
    // cout<<"Hello World";
    int n = 1,x,val;
    while(n){
        cout<<"Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:\n";
        cin>>n;
        switch(n){
            case 1 : cout<<"Enter value to be Enqueued: ";
                    cin>>val;
                    enqueue(val);
                    printQ();
                    break;
            case 2 : dequeue();
                    printQ();
                    break;
            case 3 : cout<<"Front element: "<<frontQ();
                    break;
            case 4 : (isempty()?cout<<"Empty":cout<<"Not Empty");
                    break;
            default : break;
        }
        cout<<endl;
    }
    return 0;
}
/*
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
1                                                                                                                                               
Enter value to be Enqueued: 6                                                                                                                   
Enqueue Successful                                                                                                                              
Current elements in Queue: 6                                                                                                                    
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
1                                                                                                                                               
Enter value to be Enqueued: 8                                                                                                                   
Enqueue Successful                                                                                                                              
Current elements in Queue: 6 8                                                                                                                  
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
1                                                                                                                                               
Enter value to be Enqueued: 7                                                                                                                   
Enqueue Successful                                                                                                                              
Current elements in Queue: 6 8 7                                                                                                                
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
2                                                                                                                                               
Dequeue Successful                                                                                                                              
Current elements in Queue: 8 7                                                                                                                  
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
3                                                                                                                                               
Front element: 8                                                                                                                                
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
4                                                                                                                                               
Not Empty                                                                                                                                       
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                           
0
*/
