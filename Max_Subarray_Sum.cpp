#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void inputElements(vector<int>& arr, int n)
{   int input;
    cout<<"Enter Elements"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>input;
        arr.push_back(input);
    }
    cout<<endl;
}

// BRUTEFORCE APPROACH
int SubarraySum(vector<int>& arr, int n)
{
    int maxi = INT16_MIN;

    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int sum = 0;
            for(int k=i; k<j; k++)
            {
                sum += arr[k];
            }
            maxi = max(sum , maxi);
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr;

    inputElements(arr, 8);

    int ans = SubarraySum(arr, 8);

    cout<<"Maximum Subarray Sum: "<<ans<<endl;

}