#include<bits/stdc++.h>
using namespace std;

bool check(string s1, string s2)
{
    if(s1.length() != s2.length()) return false;

    unordered_map<char, char> mp1;
    unordered_map<char, char> mp2;

    for(int i=0; i<s1.length(); i++)
    {
        char ch1 = s1[i];
        char ch2 = s2[i];

        // check if char is not in map or char os string 1 is not map with char of map2 
        if((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)){
            return false;
        }

        mp1[ch1] = ch2;
        mp2[ch2] = ch1;
    }

    return true;
}
int main()
{
    string s1 , s2;
    cout<<"enter first string";
    getline(cin, s1);

    cout<<"enter second string";
    getline(cin , s2);

    if(check(s1, s2)){
        cout<<"Strings are Isomorphic"<<endl;
    }else{
        cout<<"Strings are not Isomorphic"<<endl;
    }

    return 0;

}
