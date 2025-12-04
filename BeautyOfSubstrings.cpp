#include<bits/stdc++.h>
using namespace std;

// Brute approach : TC - O(n^3) , SC - O(1)
int countFreq(string str)
{
    int n = str.length();
    map<char , int> mp;

    for(int i=0; i<n; i++)
    {
        mp[str[i]]++;
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(auto it : mp)
    {
        if(it.second < mini)
        {
            mini = it.second;
        }

        if(it.second > maxi)
        {
            maxi = it.second;
        }
    }

    return maxi - mini;
}

int getBeauty(string s)
{
    int n = s.length();
    int count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            count += countFreq(s.substr(i , j-i+1));
        }
    }

    return count;
}

// Optimal approach : TC - O(n^2) , SC - O(1)
int getBeauty(string s)
{
    int n = s.length();
    int count = 0;

    for(int i=0; i<n; i++)
    {
        vector<int> freq(26 , 0);
        for(int j=i; j<n; j++)
        {
            freq[s[j] - 'a']++;

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for(auto f : freq)
            {
                if(f > 0)
                {
                    maxi = max(maxi , f);
                    mini = min(mini , f);
                }
            }

            count += maxi - mini;           
        }
    }

    return count;
}



int main()
{
    string s;
    cout<<"enter string "<<endl;
    getline(cin , s);

    int ans = getBeauty(s);
    cout<<"Sum of Beauty of All Substrings : "<<ans<<endl;
}