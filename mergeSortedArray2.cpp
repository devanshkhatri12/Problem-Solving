// Merge sorted array without using extra space;
#include<bits/stdc++.h>
using namespace std;

// Optimal approach: TC - O(min(n, m)) + nlogn + mlogm, SC - O(1)
void mergeSorted(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    int left = n-1;
    int right = 0;

    while(left >= 0 && right < m)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break;  
        }
    }


    sort(arr1.begin() , arr1.end());
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

void swapAtIndex(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2)
{
    if(arr1[idx1] > arr2[idx2]){
        swap(arr1[idx1], arr2[idx2]);
    }
}

// Optimal approach : TC - O()
void mergeSorted(vector<int>& arr1, vector<int>& arr2, int n, int m)
{
    int len = n+m;
    int gap = (len/2) + (len%2);

    while(gap > 0)
    {
        int left = 0;
        int right = gap+left;

        while(right < len)
        {
            // arr1 & arr2
            if(left < n && right >= n)
            {
                swapAtIndex(arr1, arr2, left, right-n);
            }
            // arr2 & arr2
            else if(left >= n)
            {
                swapAtIndex(arr1, arr2, left-n, right-n);
            }
            // arr1 & arr1
            else{
                swapAtIndex(arr1, arr2, left, right);
            }

            left++;
            right++;
        }

        if(gap == 1) break;
        gap = (len/2) + (gap%2);
    }

    for(int i=0;i<len;i++)
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