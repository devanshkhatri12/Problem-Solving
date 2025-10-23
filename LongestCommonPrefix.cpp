#include<bits/stdc++.h>
using namespace std;

// Brute approach -  TC - O(n^2) , SC - O(1)
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

// Better Appraoch : TC - O(N^2) , SC - O(1)
string Prefix(vector<string>& strs)
{
    int n = strs.size();

    if(n == 0) return " ";

    if(n == 1) return strs[0];

    string result = " ";

    for(int i=0; i<strs[0].size(); i++)
    {
        for(string s : strs)
        {
            if(s[i] != strs[0][i]){

                return result;
            }
        }

        result += strs[0][i];
    }

    return result;
}


string commonPrefix(string left, string right)
{
    int mini = min(left.length() , right.length());

    for(int i=0; i<mini; i++)
    {
        if(left[i] != right[i]) return left.substr(0 , i);
    }

    return left.substr(0, mini);
}

string longestCommonPrefix(vector<string>& strs, int l, int r)
{
        // only 1 string is present
    if(l == r){
         return strs[l];
    }
        // for multiple string
    else{
        int mid = (l + r)/2;
        string lcpleft = longestCommonPrefix(strs, l, mid);
        string lcpright = longestCommonPrefix(strs, mid+1, r);
        return commonPrefix(lcpleft, lcpright);
    }
}
string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.size() == 0) return "";
    return longestCommonPrefix(strs, 0, strs.size()-1);
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

    string ans = longestCommonPrefix(strs);

    if(ans.empty()){
        cout<<"\" \""<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}