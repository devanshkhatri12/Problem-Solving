#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BBRUTE APPROACH - LOOPING
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