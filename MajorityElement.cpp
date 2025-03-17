#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// OPTIMAL AAPROACH - MOORE'S VOTING ALGORITHM
int majorityElement(vector<int> &v)
{
    int n = v.size();

    int count=0;
    int elem;

    // moose voting algo 
    for(int i=0; i<n; i++)
    {
        if(count == 0)
        {
            count =1;
            elem = v[i];
        }
        else if(elem  == v[i])
        {
            count++;
        }
        else{
            count--;
        }
    }

    int countFinal = 0;
    for(int j=0; j<n; j++)
    {
        if(elem == v[j]) countFinal++;
    }

    if(countFinal > n/2)
    return elem;
    
    return -1;
}


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
    vector<int> v = {2,3,3,3,1,2,3};

    int ans = majorityElement(v);

    cout<<"Majority Element: "<<ans<<endl;

}