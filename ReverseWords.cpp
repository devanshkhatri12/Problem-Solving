#include<bits/stdc++.h>
using namespace std;

// Brute approach:
string reverseStringWords(string s)
{
    stringstream ss(s);

    string token  = "";
    string result = "";

    while(ss >> token)
    {
        result = token + " " + result;
    }

    return result.substr(0 , result.length()-1);
}

int main()
{
    string s;
    cout<<"Enter String: ";
    getline(cin , s);

    string ans = reverseStringWords(s);

    cout<<"after reverse string: "<<ans<<endl;
}