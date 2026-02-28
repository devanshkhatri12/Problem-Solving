#include<bits/stdc++.h>
using namespace std;

// Better approach :  using mapping and stack
bool isValid(string s)
{
    unordered_map<char , int> mp = {{'(', -1}, {')', 1}, {'{', -2}, {'}', 2}, {'[', -3}, {']', 3}};
    stack<char> st;

    for(char ch : s)
    {
        if(mp[ch] < 0){

            st.push(ch);
        }else{

            if(st.empty()) return false;

            int top = st.top();
            st.pop();

            if(mp[top] + mp[ch] != 0){
                return false;
            }
        }
    }

    if(!st.empty()){
        return false;
    }else{
        return true;
    }
}

int main(){

    string s;
    cout<<"enter a valid string"<<endl;
    getline(cin, s);

    if(isValid(s)){
        cout<<"String contain a valid Paranthesis"<<endl;
    }else{
        cout<<"String is not valid Paranthesis"<<endl;
    }

    return 0;
}