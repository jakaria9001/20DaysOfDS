// Stack using linked list: 

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL){}
};
Node *head = NULL;

void push(int x){
    Node *temp = new Node(x);
    if(head==NULL)
        head = temp;
    else{
        temp->next = head;
        head = temp;
    }
    cout<<"Push successful"<<endl;
}
void pop(){
    if(head==NULL) 
        cout<<"Underflow"<<endl;
    else {
        Node* temp = head;
        head = head->next;
        delete(temp);
    
        cout<<"Pop successful"<<endl;
    }
}
int top(){
    if(head==NULL) 
        return -1;
    return head->data;
}
bool isEmpty(){
    if(head) return false;
    return true;
}
int main()
{
    // printf("Hello World");
    int n = 1, x;
    while(n){
        cout<<"1.For pushing, 2.For pop, 3.Top, 4.isEmpty, 0.To exit:\n ";
        cin>>n;
        switch(n){
            case 0: break;
            case 1: cin>>x;
                    push(x);
                    break;
            case 2: pop();
                    break;
            case 3: cout<< (top()==-1 ? "Stack Empty" : to_string(top() )) << endl;
                    break;
            case 4: cout<< ( isEmpty()?"Empty" : "Not empty" ) <<endl;
                    break;
            default: break;
        }
        if(n==0) cout<<"See You Next Time"<<endl;
    }
    
    return 0;
}
