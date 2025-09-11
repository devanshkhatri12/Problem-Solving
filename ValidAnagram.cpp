#include<bits/stdc++.h>
using namespace std;

// Brute Approach : TC - O(NlogN) , SC - O(1)
bool validAnagram(string s, string t)
{
    if(s.length() != t.length())
    return false;

    sort(s.begin() , s.end());
    sort(t.begin() , t.end());

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s, t;

    cout<<"Enter string"<<endl;

    getline(cin, s);
    getline(cin, t);

    if(validAnagram(s, t)){
        cout<<"Strings are ANAGRAMS"<<endl;
    }
    else{
        cout<<"Strings are not ANAGRAMS"<<endl;
    }

}