#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 15, 5, 10, 5};
    map<int , int> mp;

    int first = 0;
    int second = 0;

    int mini = INT16_MAX;
    int maxi = INT16_MIN;

    for(int &num : v)
    {
        mp[num]++;
    }

    for(auto it : mp)
    {
        if(maxi < it.second)
        {
            first = it.first;
            maxi = max(maxi , it.second);
        }

        if(mini > it.second)
        {
            second = it.first;
            mini = min(mini , it.second);
        }
    }

    cout<<"highest occur "<<first<<" Lowest occur "<<second<<endl;
}