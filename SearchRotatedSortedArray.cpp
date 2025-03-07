#include<bits/stdc++.h>
using namespace std;

// return index
int search(vector<int> &arr, int target)
{
    int n =arr.size();
    int low = 0, high=n-1;
    
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == target) return mid;

        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= target && target <= arr[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        else
        {
            if(arr[mid] <= target && target <= arr[high])
            {
                
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;

    vector<int> arr;

    cout<<"Enter array elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;

    int target;
    cout<<"enter target"<<endl;
    cin>>target;

    int ans = search(arr , target);

    cout<<"Minimum element is present in: "<<ans<<" index"<<endl;

    return 0;
}