#include<bits/stdc++.h>
using namespace std;


// Brute approach : TC - O(N^2) , SC - O(1)
int missing(vector<int>& arr)
{
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        bool flag = false;
        for(int j=0; j<n; j++)
        {
            if(arr[j] == i)
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            return i;
        }
    }
    return n;
}

// Better approach - TC - O(nlogn) , SC O(1)
int missing(vector<int>& arr)
{
    int n = arr.size();

    sort(arr.begin() , arr.end());

    for(int i=0; i<n; i++)
    {
        if(arr[i] != i)
        {
            return i;
        }
    }
    return n;
}

// Better approach - TC - O(2N) , SC - O(N)
int missing(vector<int>& arr)
{
    int n = arr.size();

    vector<int> hashArr(n+1, 0);

    for(int i=0; i<n; i++)
    {
        hashArr[arr[i]] = -1;
    }

    for(int i=0; i<n; i++)
    {
        if(hashArr[i] != -1)
        {
            return i;
            break;
        }
    }
    return n;

}

// Optimal approach - TC - O(N) , SC - (1)
int missing(vector<int>& arr)
{
    int n = arr.size();

    int sum = 0;
    int TotalSum = (n*(n+1))/2;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    return TotalSum - sum;
}


int main()
{
    vector<int> arr = {3,0,1};

    cout<<"Missing no. is : "<<missing(arr)<<endl;

}