// Parenthesis Validity Check : 

#include <bits/stdc++.h>
using namespace std;

bool checkValidity(string s){
    stack<char> st;
    
    for(char ch: s){
        
        if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
        else if(ch==')'){
            if(st.empty() || st.top()!='(') return false;
            else st.pop();
        }else if(ch=='}'){
            if(st.empty() || st.top()!='{') return false;
            else st.pop();
        }else if(ch==']'){
            if(st.empty() || st.top()!='[') return false;
            else st.pop();
        }
    }
    if(st.size()) return false;
    return true;
}
int main(){
    string s;
    cin>>s;
    
    bool flag = checkValidity(s);
    
    if(flag) cout<<"Parenthesis Valid"<<endl;
    else cout<<"Parenthesis Invalid"<<endl;
    
    return 0;
}
