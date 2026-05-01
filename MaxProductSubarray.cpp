#include<bits/stdc++.h>
using namespace std;

// don't use brute and better approach bcz it can't handle the case which contain element 0;
// Optimal approach : TC - O(n), SC - O(1)
int maxProduct(vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for(int i=0;i<n;i++)
    {
        if(prefix == 0) prefix = 0;
        if(suffix == 0) suffix = 0;

        prefix *= nums[i];
        suffix *= nums[n-i-1];

        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;

    vector<int> nums(n);

    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int ans = maxProduct(nums);

    cout<<"Maximum product of subarray is : "<<ans<<endl;

    return 0;

}