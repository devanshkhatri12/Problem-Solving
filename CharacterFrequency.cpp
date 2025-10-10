#include<bits/stdc++.h>
using namespace std;

string frequencyCount(string s)
{
    unordered_map<char , int> mp;
    multimap<int , char> m;
    string ss = "";

    // storing freq. of char. in string
    for(auto ch : s)
    {
        mp[ch]++;
    }

    // map freq count with charcter
    for(auto ch : mp)
    {
        m.insert({ch.second , ch.first});
    }

    // stroe in a string
    for(auto it = m.rbegin(); it != m.rend(); ++it){
        ss += string(it->first , it->second);
    }

    return ss;
}

int main()
{
    string s;
    cout<<"Enter a string without using space"<<endl;
    getline(cin , s);

    string ans = frequencyCount(s);

    cout<<"Sort characters by frequency: "<<ans<<endl;
}