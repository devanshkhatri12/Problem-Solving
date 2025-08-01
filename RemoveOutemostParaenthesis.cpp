#include<bits/stdc++.h>
using namespace std;

string removeParentheses(string s)
{
    int n = s.size();
    int count  = 0;
    string ans = "";


    for(int i=0; i<n; i++)
    {
        if(s[i] == ')')
        {
            count -= 1;
        }

        // we add elemet in middle bcz it can't add outer most string
        if(count != 0)
        {
            ans += s[i];
        }

        if(s[i] == '(')
        {
            count += 1;
        }
    }

    return ans;

}

int main()
{
    string s;
    cout<<"Input Valid Paraenthesis"<<endl;
    getline(cin, s);


    cout<<"After remove outer most Parentheses: "<<removeParentheses(s)<<endl;

    
}