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

int main()
{
    int threshold;
    cout<<"enter the threshold number"<<endl;
    cin>>threshold;

    vector<int> nums = {1,2,5,9};

    int maxi = maximum(nums);

    int ans = Divisor(nums, threshold, maxi);


    cout<<"possible smallest divisor is "<<ans<<endl;
}