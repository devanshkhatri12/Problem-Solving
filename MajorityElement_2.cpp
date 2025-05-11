// Element which is present more than n/3 times., here n is size of array

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& v)
{
    int n = v.size();
    map<int , int> mp;

    for(int i=0; i<n; i++)
    {
        mp[v[i]]++;
    }

    for(auto it : mp)
    {
        if(it.second > n/3)
        {
            return it.first;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {2,3,3,3,1,2,3};

    int ans = majorityElement(v);

    cout<<ans<<" is present more than n/3 times"<<endl;

}