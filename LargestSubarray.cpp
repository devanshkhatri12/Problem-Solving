#include<bits/stdc++.h>
using namespace std;

// Optimal approach: TC - O(nlogn), SC - O(n)
int Subarray(vector<int>& nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum += nums[i];
        if(sum == 0){

            maxi = i+1;

        }else{
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
    }

    return maxi;

}

int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    vector<int> nums(n);

    cout<<"enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int ans = Subarray(nums);

    cout<<"Largest Subarray with zero sum"<<ans<<endl;

    return 0;
}