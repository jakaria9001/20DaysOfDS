// reversals using stack: 

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL){}
};
Node* head = NULL;

void reverse_string(string &s){
    stack<char> st;
    for(char ch: s)
        st.push(ch);
    // while(!st.empty()){
    //     cout<<st.top();
    //     st.pop();
    // }
    for(int i=0;i<s.length();i++){
        s[i] = st.top();
        st.pop();
    }
}
void reverse_LL(){
    Node *temp = head;
    
    stack<Node*> st;
    while(temp){
        st.push(temp);
        temp = temp->next;
    }
    temp = NULL;
    
    while(!st.empty()){
        if(temp==NULL){
            head = temp = st.top();
        }else{
            temp->next = st.top();
            temp = temp->next;
        }
        st.pop();
    }
    temp->next = NULL;
}

void insertAtEnd(int x){
    Node *temp = new Node(x);
    if(!head){
        head = temp;
    }else {
        Node* tail = head;
        while(tail->next)
            tail = tail->next;
        tail->next = temp;
    }
}
void printLL(){
    if(!head) return;
    
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    
    // string reversal : 
    string s;
    cout<<"Enter string to be reversed:\n";
    getline(cin,s);
    
    cout<<"Reversed string using stack:\n";
    
    reverse_string(s);
    
    cout<<s<<endl;
    
    // Linked List reversal:
    int n,x;
    cout<<"No of elements in LL: ";
    cin>>n;
    cout<<"Enter elements: ";
    while(n--){
        cin>>x;
        insertAtEnd(x);
    }
    cout<<"Current LL: ";
    printLL();
    reverse_LL();
    cout<<"List after reversal: ";
    printLL();
    return 0;
}
