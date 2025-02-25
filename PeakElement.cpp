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