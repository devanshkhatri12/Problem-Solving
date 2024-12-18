#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int floor(vector<int> &v , int target)
{
    int ans = -1;
    int n = v.size();
    int low =0, high =n-1;

    while( low <= high)
    {
        int mid = (low + high)/2;

        if(v[mid] <= target)
        {
            ans = v[mid];
            low = mid +1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}

int ceil(vector<int> &v , int target)
{
    int ans = -1;
    int n = v.size();
    int low =0, high =n-1;

    while( low <= high)
    {
        int mid = (low + high)/2;

        if(v[mid] >= target)
        {
            ans = v[mid];
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {2,3,6,7,8,8,11,11,11,12};

    int target = 5;

    int Floor = floor(v, target);
    cout<<"floor is: "<<Floor<<endl;
    
    int Ceil = ceil(v, target);
    cout<<"Ceil is: "<<Ceil<<endl;
}