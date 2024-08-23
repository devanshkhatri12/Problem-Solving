#include<bits/stdc++.h>
using namespace std;

// Optimal approach - TC - O(n) , SC - O(1)
int totalConsecutiveOnes(int arr[], int n)
{
    int count = 0;
    int maxi = 0;

    for(int i=0; i<n; i++)
    {
        count += arr[i];
        if(count > maxi)
        {
            maxi = count;
        }

        if(arr[i] == 0)
        {
            count = 0;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {0,1,1,0,1,1,1,0,0,1,1,1,1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = totalConsecutiveOnes(arr, n);

    cout<<"total consecutive 1 "<<ans<<endl;
}