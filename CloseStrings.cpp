// Leetcode Que.1657 -> https://leetcode.com/problems/determine-if-two-strings-are-close/description/
// TC - O(1)
// SC - O(1)
#include<bits/stdc++.h>
using namespace std;

bool Closestr(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    if(n != m)
    return false;

    vector<int> freq1;
    vector<int> freq2;

    //coutning freq. all char present in string s1 and s2
    for(int i=0; i<n; i++)          
    {
        char ch1 = word1[i];
        char ch2 = word2[i];
        freq1[ch1-'a']++;
        freq2[ch2-'a']++;
    }

    // 1st -> char in s1 also must also present in s2 OR char not present either both of them
    for(int i=0; i<26; i++)
    {
        if(freq1[i] != 0 && freq2[i] != 0)
        continue;

        if(freq1[i] == 0 && freq2[i] == 0)
        continue;

        return false;
    }
    // 2nd -> sort both string freq. wise
    sort(freq1.begin() , freq1.end());
    sort(freq2.begin() , freq2.end());

    return freq1 == freq2;
}

int main() 
{
    string s1 , s2;
    cout<<"Input strings "<<endl;
    cin>>s1>>s2;

    
    if(Closestr(s1,s2))
    {
        cout<<"string are close"<<endl;
    }
    else{
        cout<<"string are not close"<<endl;
    }
}