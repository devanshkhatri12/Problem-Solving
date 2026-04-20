// Merge sorted array without using extra space;
#include<bits/stdc++.h>
using namespace std;

// Optimal approach: TC - O(min(n, m)) + nlogn + mlogm, SC - O(1)
void mergeSorted(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    int left = n-1;
    int right = 0;

    while(left >= 0 && right < n)
    {
        if(arr1[left] <= arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;  
        }
    }

    sort(arr1.begin() , arr2.end());
    sort(arr2.begin() , arr2.end());

    int x = n+m;

    for(int i=0;i<x;i++)
    {
        if(i<n){
            cout<<arr1[i]<<" ";
        }else{
            cout<<arr2[i-n]<<" ";
        }
    }
    cout<<endl;

}

void inputElement(vector<int>& arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int n, m;
    cout<<"Size of Array1 and Array2"<<endl;
    cin>>n>>m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    cout<<"Enter array 1 Elements"<<endl;
    inputElement(arr1, n);

    cout<<"enter array 2 Elements"<<endl;
    inputElement(arr2, m);

    cout<<"Merge sorted Array"<<endl;
    mergeSorted(arr1, arr2, n, m);


    return 0;
}