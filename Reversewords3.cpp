#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();

    int i=0, l=0, r=0;
    while(i <= n)
    {
        // reversing words when we find space
        if(i == n || s[i] == ' '){
            reverse(s.begin() + l , s.begin() + r);

            i++;
            r++;

            l = r;
        }else{
            i++;
            r++;
        }
    }
    return s;
}

int main()
{
    string s;
    cout<<"enter string"<<endl;
    getline(cin, s);


    string ans = reverseWords(s);

    cout<<"after Reverse words: "<<ans<<endl;





}