#include<bits/stdc++.h>
using namespace std;

// Brute Approach: TC - O(n) , SC - O(1)
int peakIndex(vector<int>& arr)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if((i == 0 || arr[i-1] < arr[i]) && (i == n-1 || arr[i] > arr[i+1]))
        {
            return i;
        }
    }
    return -1;
}




// Optimal Approach: TC - O(logN) , SC - O(1)
int peakIndex(vector<int>& arr) 
{
    int n = arr.size();

    //CASE -1 : when array has only 1 element
    if(n == 1)
    return 0;

    // CASE-2: when array is like [5, 4, 3, 2 ,1]
    if(arr[0] > arr[1])
    return 0;

    // case-3: when array is like [1, 2, 3, 4, 5]
    if(arr[n-1] > arr[n-2])
    return n-1;

    int low =1, high=n-2;
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        // mid ==  peak
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        // peak on right side
        if(arr[mid] > arr[mid-1])
        {
            low  = mid+1;
        }
        // peak on left side
        else
        {
            high = mid-1;
        }
    }

    // can't find peak
    return -1;
    
}



int main()
{
    int n;
    cout<<"Enter array size"<<endl;
    cin>>n;

    vector<int> arr;

    cout<<"enter Elements"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;


    cout<<"Peak Element Index: "<<peakIndex(arr)<<endl;


}