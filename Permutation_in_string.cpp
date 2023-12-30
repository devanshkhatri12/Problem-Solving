#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for(int i=0; i<26; i++)
    {
        if(a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

bool checkPermutation(string s1, string s2)
{
    // character count array
    int count1[26] = {0};

    // counting characters of s1 string 
    for(int i=0; i<s1.length(); i++)      
    { 
        int index = s1[i] -'a';
        count1[index]++;
    }

    // traverse s2 in window of size s1 length and compare

    int i=0;
    int windowsize = s1.length();
    int count2[26] = {0};

    // running for first window
    while(i<windowsize && i<s2.length())
    {
        int index = s2[i] -'a';
        count2[index]++;
        i++;
    }

    // checkinig string s1 is equal to s2 or not
    if(checkEqual(count1, count2))
    {
        return 1;
    }


    // aage process kro window ko check krna
    while(i<s2.length())
    {
        // adding new character
        char newchar = s2[i];
        int index = newchar -'a';
        count2[index]++;

        // remove old character
        char oldchar = s2[i-windowsize];
        index= newchar +'a';
        count2[index]--;

        i++;

        if(checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s1 = "ab";
    string s2 = "cdsb";

    if(checkPermutation(s1,s2))
    {
        cout<<"Permution is present"<<endl;
    }
    else
    {
        cout<<"permutation is not present"<<endl;
    }
}