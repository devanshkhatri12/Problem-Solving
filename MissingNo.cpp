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

int main()
{
    vector<int> arr = {3,0,1};

    cout<<"Missing no. is : "<<missing(arr)<<endl;

}