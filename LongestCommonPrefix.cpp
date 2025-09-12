#include<bits/stdc++.h>
using namespace std;

string Prefix(vector<string>& strs)
{
    int n = strs.size();

    if(n == 0) return "";

    if(n == 1) return strs[0];

    string prefix = strs[0];

    for(int i=0; i<n; i++)
    {
        while(strs[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.length()-1);
        }

        if(prefix.empty()) return "";
    }

    return prefix;
}

int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;


    vector<string> strs(n);

    cout<<"enter strings"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>strs[i];

    }

    string ans = Prefix(strs);

    if(ans.empty()){
        cout<<"\" \""<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}