// evaluation of infix and postfix expresion using stack: 

#include <bits/stdc++.h>
using namespace std;
int calculate(int x, int y, char oper){
    switch(oper){
        case '+' : return x+y;
        case '-' : return x-y;
        case '*' : return x*y;
        case '/' : return x/y;
    }
    return -1;
}
int main()
{
    // cout<<"Hello World";
    
    string postfix, prefix;
    cout<<"Enter the postfix expresion: ";  // use space as delimiter
    getline(cin,postfix);
    
    stack<int> st;
    for(int i=0;i<postfix.length();i++){
        char ch = postfix[i];
        if(ch==' '|| ch==',') continue;
        
        else if(isdigit(ch)){     //operand -> push to stack.
            // st.push(ch);
            int operand = 0;
            while(i<postfix.length() && isdigit(postfix[i])){
                operand = operand*10+(postfix[i]-'0');
                i++;
            }
            i--;
            st.push(operand);
        }
        else{              //operator -> apply operator to the last to elements in the stack and push the result
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = calculate(op2,op1,postfix[i]);
            st.push(res);
        }
    }
    cout<<"Value after evaluation: "<<st.top();
    
    // for evaluation of infix expresion, traverse the list from last, add and remove elements to/from stack accordingly.
    return 0;
}

// Output: 

// Enter the postfix expresion: 2 3 * 5 4 * + 9 -                                                                                                                   
// Value after evaluation: 17      
