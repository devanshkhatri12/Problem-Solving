#include<bits/stdc++.h>
using namespace std;

int maximum(vector<int>& nums)
{
    int maxi = INT_MIN;
    for(int i=0; i<nums.size(); i++)
    {
        maxi = max(maxi , nums[i]);
    }
    return maxi;
}

// Brute approach: TC- O(n^2) , Sc -O(1)
int Divisor(vector<int>& nums, int threshold, int maxi)
{
    for(int i=1; i<=maxi; i++)
    {
        int elem  = i;
        int result = 0;

        for(int i=0; i<nums.size(); i++)
        {
            result += ceil(double(nums[i]) / double(elem));
        }

        if(result <= threshold)
        {
            return elem;
        }
    }

    return -1;
}

int possible(vector<int>& nums, int mid)
{
    int result=0;
    for(int i=0; i<nums.size(); i++)
    {
        result += ceil(double(nums[i]) / double(mid));
    }
    return result;
}

// Optimal approach: TC -O(logn) , SC -O(1)
int Divisor(vector<int>& nums, int threshold, int maxi)
{
    int mini = 1;
    int ans = INT_MIN;

    while(mini <= maxi)
    {
        int mid = mini + (maxi - mini)/2;

        int result = possible(nums, mid);

        if(result <= threshold)
        {
            ans = mid;
            maxi = mid-1;
        }
        else{
            mini = mid+1;
        }
    }

    return ans;
}

int main()
{
    int threshold;
    cout<<"enter the threshold number"<<endl;
    cin>>threshold;

    vector<int> nums = {44,22,33,11,1};

    int maxi = maximum(nums);

    int ans = Divisor(nums, threshold, maxi);


    cout<<"possible smallest divisor is "<<ans<<endl;
}