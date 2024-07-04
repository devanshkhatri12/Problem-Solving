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

// OPTIMAL APPROACH
int SubarraySum(vector<int>& arr, int n)
{
    int maxi = INT16_MIN;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];

        if(sum > maxi)
        {
            maxi = sum;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

// BETTER APPROACH
int SubarraySum(vector<int>& arr, int n)
{
    int maxi = INT16_MIN;

    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            maxi = max(sum , maxi);
        }
    }
    return maxi;
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
