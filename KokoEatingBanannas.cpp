#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>& arr)
{
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++)
    {
        maxi = max(maxi , arr[i]);
    }
    return maxi;
}

int findk(vector<int>& arr, int hour)
{
    int sum = 0;
    for(int i=0; i<arr.size(); i++)
    {
        sum += ceil(double(arr[i]) / double(hour));
    }
    
    return sum;
}
int kokoEat(vector<int>& arr, int k) {
    // Code here
    
    int n = arr.size();
    int MAX  = findMax(arr);
    
    for(int i=1; i<=MAX; i++)
    {
        int totalHour = findk(arr,i);
        
        if(totalHour <= k)
        {
            return i;
        }
    }
    
    return MAX;
}



int main()
{
    vector<int> arr = {3,6,7,11};

    int hour;
    cout<<"enter Hour"<<endl;
    cin>>hour;

    int ans = kokoEat(arr,hour);

    cout<<"Minimum integer to eat piles of banannas "<<ans<<endl;
}
























