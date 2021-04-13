#include <bits/stdc++.h>
using namespace std;

int precedence(char x){
    switch(x){
        case '^' : return 3;
        case '*' :
        case '/' :
        case '%' : return 2;
        case '+' : 
        case '-' : return 1;
    }
    return 0;
}
string infixToPostfix(string infix){
    string postfix = "";
    
    stack<char> st;
    
    for(int i=0;i<infix.length();i++){
        if(isalnum(infix[i])){
            postfix+=infix[i];
        }else if(infix[i]=='(')
            st.push('(');
        else if(infix[i]==')'){ //pop all and add to postfix untill stack is empty or ) comes
            while(!st.empty() && st.top()!='('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }else { //operator: 
            while(!st.empty()){
                if(st.top()=='(' || precedence(infix[i])>precedence(st.top()))
                    break;
                else {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(infix[i]);
            
    
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main(){
    string infix, postfix;
    cout<<"Enter the infix expresion: ";  // use space as delimiter
    getline(cin,infix);
    
    postfix = infixToPostfix(infix);
    
    cout<<"Postfix expresion: "<<postfix<<endl;
    
    // evalatePostfix(postfix);
    
    // for evaluation of infix expresion, traverse the list from last, add and remove elements to/from stack accordingly.
    return 0;
}

// Output: 

// Enter the infix expresion: (a+b-(c/d)*e%f^g)                                                                                                                   
// Postfix expresion: ab+cd/e*fg^%-    


// Enter the infix expresion: (1+7-8*3)                                                                                                                           
// Postfix expresion: 17+83*-       
