#include<bits/stdc++.h>
using namespace std;

// Brute appraoch - TC - O(n^2) , SC - O(1)
vector<int> twoSum(vector<int>& arr, int target)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j) continue;

            if(arr[i] + arr[j] == target)
            {
                return  {i , j};
            }
        }
    }

    return {-1, -1};
}

// Better approach - approx: TC - O(n^2) , SC - O(1);
vector<int> twoSum(vector<int>& arr, int target)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(i == j) continue;

            if(arr[i] + arr[j] == target)
            {
                return  {i , j};
            }
        }
    }

    return {-1, -1};
}


// Optimal approahc - TC - O(N) , SC - O(N)
vector<int> twoSum(vector<int>& arr, int target)
{
    int n = arr.size();

    map<int, int> mp;

    for(int i=0; i<n; i++)
    {
        int element = arr[i];
        int difference = target - element;

        if(mp.find(difference) != mp.end())
        {
            return {mp[difference] , i};
        }

        mp[element] = i;
    }

    return {-1, -1};
}

int main()
{
    int target;
    cout<<"Eneter target Sum"<<endl;
    cin>>target;

    vector<int> arr = {2, 6, 5, 8, 11};

    vector<int> ans = twoSum(arr, target);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
