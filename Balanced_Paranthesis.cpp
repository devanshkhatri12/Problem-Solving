#include<iostream>
#include<bits/stdc++.h>
using namespace std;


unordered_map <char,int> symbol = {{'[',-1},{']',1},{'(',-2},{')',2},{'{',-3},{'}',3}};
string BalancedParanthesis(string s)
{
    stack<char> st;
    
    for(char bracket : s)
    {
        if(symbol[bracket] < 0)
        {
            st.push(bracket);
        }
        else
        {
            if(st.empty())
            {
                return "NO";
            }
            
                char top = st.top();
                st.pop();
            
            if(symbol[bracket] + symbol[top] != 0)
            {
                return "NO";
            }
        }
    }

    if(!st.empty())
    {
        return "NO";
    }
    else{
        return "YES";
    }
}

int main()
{
    string s;
    cout<<"Input Breackets string"<<endl;
    cin>>s;

    cout<<BalancedParanthesis(s);
}