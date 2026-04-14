#include<bits/stdc++.h>
using namespace std;

// Better approach : TC - O(n^3) * logm, SC - O(N) + O(no of triplet)
vector<vector<int>> Sum(vector<int>& nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            set<int> hashSet;
            for(int k=j+1; k<n; k++)
            {
                // to prevent to go out of bound
                long long sum = nums[i] + nums[j];
                sum += nums[j];
                int four = target - (sum);

                if(hashSet.find(four) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], four};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }

    return vector<vector<int>>(st.begin() , st.end());
}


int main()
{
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    int target;
    cout<<"enter target"<<endl;
    cin>>target;

    vector<int> nums(n);

    cout<<"enter elements"<<endl;
    for(int i=0; i<nums.size(); i++)
    {
        cin>>nums[i];
    }


    vector<vector<int>> ans = Sum(nums, target);

    cout<<"Triplets are"<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;

}