#include<bits/stdc++.h>
using namespace std;

// Brute approach -  TC - O(n^2) , SC - O(1)
int AppearOnce(vector<int>& arr)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        int count = 0;
        int num = arr[i];
        for(int j=0; j<n; j++)
        {
            if(arr[j] == num)
            {
                count++;
            }
        }

        if(count == 1)
        {
            return num;
        }
    }

    return -1;
}

// Better approach - TC - O(3N) , SC- O(N)
int AppearOnce(vector<int>& arr)
{
    int n = arr.size();
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    vector<int> hashArr(maxi+1, 0);

    for(int i=0; i<n; i++)
    {
        hashArr[arr[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        if(hashArr[arr[i]] == 1)
        {
            return arr[i];
            break;
        }
    }
    return -1;
}

// Better appraoch - TC - O(n) + O(n/2+1) , SC - O(n/2+1)
int AppearOnce(vector<int>& arr)
{
    int n = arr.size();

    map<long long, int> mp;

    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it : mp)
    {
        if(it.second == 1)
        {
            return it.first;
        }
    }
}

// Optimal approach - TC -O(N) , SC - O(1)
int AppearOnce(vector<int>& arr)
{
    int n = arr.size();

    int XOR = 0;
    for(int i=0; i<n; i++)
    {
        XOR ^= arr[i];
    }
    return XOR;
}

int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4,5};

    int ans = AppearOnce(arr);

    cout<<"Appear Once Element is: "<<ans<<endl;




}