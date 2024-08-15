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


int main()
{
    vector<int> arr = {1,1,2,3,3,4,4};

    int ans = AppearOnce(arr);

    cout<<"Appear Once Element is: "<<ans<<endl;




}