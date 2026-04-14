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

// Optimal approach: TC - O(n^2) * O(N) , SC - O(no. of triplets)
vector<vector<int>> Sum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin() , nums.end());

    for(int i=0; i<n; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1; j<n; j++)
        {
            if(j>i+1 && nums[j] == nums[j-1]) continue;

            int k =j+1;
            int l= n-1;

            while(k<l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }

                    while(k<l && nums[l] == nums[l+1]){
                        l--;
                    }
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }

    return ans;
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