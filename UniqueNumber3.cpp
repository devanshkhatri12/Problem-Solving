#include<bits/stdc++.h>
using namespace std;

int getSingle(vector<int> &arr) {
    // code here
    int n= arr.size();
    
    for(int i=0; i<n; i++)
    {
        int count =0;
        int elem = arr[i];
        
        for(int j=0; j<n; j++)
        {
            if(elem == arr[j])
            {
                count++;
            }
        }
        
        if(count == 1)
        {
            return elem;
            break;
        }
    }
    
    return -1;
}

int main()
{
    vector<int> arr = {3, 2, 1, 34, 34, 1, 2, 34, 2, 1};

    int ans = getSingle(arr);

    cout<<"number that appear once "<<ans<<endl;
}