#include<bits/stdc++.h>
using namespace std;

int findDays(vector<int>& weights , int capacity)
{
    int load = 0, day = 1;

    for(int i=0; i<weights.size(); i++)
    {
        if(load + weights[i] > capacity)
        {
            load = weights[i];
            day += 1;

        }
        else{
            load += weights[i];
        }
    }

    return day;
}
// Optimal approach: TC - O(logn) , SC - O(1)
int shipWithinDays(vector<int>& weights , int days)
{
    int maxi = *max_element(weights.begin() , weights.end());
    int sum = accumulate(weights.begin() , weights.end() , 0);

    int low = maxi, high = sum;
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        int daysRequired = findDays(weights , mid);

        if(daysRequired <= days)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    return low;
}

// Brute approach: TC - O(n^2) , SC - O(1)
// int shipWithinDays(vector<int>& weights, int days)
// {
//     int maxi = *max_element(weights.begin() , weights.end());
//     int sum = accumulate(weights.begin() , weights.end() , 0);

//     for(int i=maxi; i<=sum; i++)
//     {
//         int daysRequired = findDays(weights , i);

//         if(daysRequired <= days)
//         return i;
//     }

//     return -1;

// }

int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    int ans = shipWithinDays(weights ,days);

    cout<<"Least weight capacity of the ship is: "<<ans<<endl;
}