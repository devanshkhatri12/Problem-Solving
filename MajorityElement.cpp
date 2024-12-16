#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BETTER APPROACH - HASHING                TC -O(nlogn) + O(n) , SC - O(n)
int majorityElement(vector<int> &v)
{
    int n = v.size();

    map<int , int> mp;

    for(int i=0 ;i<n; i++)
    {
        mp[v[i]]++;
    }

    for(auto it : mp)
    {
        if(it.second > n/2)
        {
            return it.first;
            break;
        }
    }
    return -1;
}

// BBRUTE APPROACH - LOOPING                TC - O(n^2) , SC -O(1)
int majorityElement(vector<int> &v)
{
    int n = v.size();

    for(int i=0; i<n; i++)
    {
        int count =0;
        for(int j=0; j<n; j++)
        {
            if(v[j] == v[i])
            {
                count++;
            }

            if(count > n/2)
            {
                return v[i];
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {2,2,3,3,1,2,2};

    int ans = majorityElement(v);

    cout<<"Majority Element: "<<ans<<endl;

}