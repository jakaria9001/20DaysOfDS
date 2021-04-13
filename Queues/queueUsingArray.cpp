/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
// queue using array:
const int SIZE = 100;
int QUE[SIZE];    
int front = -1, rear = -1;

void enqueue(int x){
    if(rear>=SIZE){
        cout<<"Overflow";
        return;
    }
    if(rear==-1) front++;
    QUE[++rear] = x;
    cout<<"Enqueue Successful"<<endl;
}
void dequeue(){
    front++;
    if(front > rear || front==-1){
        cout<<"Queue Empty";
        return;
    }    
    
    cout<<"Dequeue Successful"<<endl;
}
int frontQ(){
    if(front<rear) cout<<QUE[front]<<" ";
    else cout<<"Empty";
    // cout<<endl;
}
bool isempty(){
    if(front>rear || rear==-1) return true;
    return false;
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
/*
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
1                                                                                                                                                                
Enter value to be Enqueued: 5                                                                                                                                    
Enqueue Successful                                                                                                                                               
5                                                                                                                                                                
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
2                                                                                                                                                                
Queue Empty                                                                                                                                                      
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
1                                                                                                                                                                
Enter value to be Enqueued: 8                                                                                                                                    
Enqueue Successful                                                                                                                                               
8                                                                                                                                                                
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
2                                                                                                                                                                
Queue Empty                                                                                                                                                      
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
2                                                                                                                                                                
Queue Empty                                                                                                                                                      
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
3                                                                                                                                                                
Empty                                                                                                                                                            
                                                                                                                                                                 
Enter 1.Enqueue, 2.Dequeue, 3.Front, 4.Empty, 0.Exit:                                                                                                            
0    
*/
