
#include <bits/stdc++.h>
using namespace std;
// queue using array:
const int SIZE = 100;
int QUE[SIZE];    
int front = -1, rear = -1;
bool isempty(){
    if(front==-1 && rear==-1)
        return true;
    return false;
}
void enqueue(int x){
    if(rear>=SIZE){
        cout<<"Overflow";
        return;
    }
    
    if(isempty()){ rear = 0, front=0;}
    else rear++;
    
    QUE[rear] = x;
    cout<<"Enqueue Successful"<<endl;
}
void dequeue(){
    if(isempty()) return;
    if(front == rear ){
        front = rear = -1;
    }else front++;    
    
    cout<<"Dequeue Successful"<<endl;
}
int frontQ(){
    if(!isempty()) cout<<QUE[front]<<" ";
    else cout<<"Empty";
    // cout<<endl;
}

void printQ(){
    if(isempty()) return;
    for(int i=front;i<=rear;i++)
        cout<<QUE[i]<<" ";
    
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
            case 3 : frontQ();
                    break;
            case 4 : (isempty()?cout<<"Empty":cout<<"Not Empty");
                    break;
            default : break;
        }
        cout<<endl;
    }
    return 0;
}
