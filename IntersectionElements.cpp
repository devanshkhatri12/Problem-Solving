#include<bits/stdc++.h>
using namespace std;

// Brute approach - TC - O(n*m) , SC - O(min(n,m));
vector<int> intersectionArrayElements(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m =  arr2.size();

    vector<int> ans;

    vector<int> visited(m+n , 0);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr1[i] == arr2[j] && visited[j] == 0)
            {
                ans.push_back(arr2[j]);
                visited[j] = -1;
                break;
            }

            if(arr2[j] > arr1[i])
            {
                break;
            }
        }
    }

    return ans;

}

// Optimal approach - TC- O(min(n,m)) , SC - O(n)
vector<int> intersectionArrayElements(vector<int>& arr1, vector<int>& arr2)
{
    vector<int> ans;

    int n = arr1.size();
    int m =  arr2.size();

    int i=0, j=0;

    while(i<n && j<m)
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1,2,2,3,3,4,5,6};
    vector<int> arr2 = {2,3,3,5,6,6,7};

    vector<int> Elements = intersectionArrayElements(arr1 , arr2);

    for(int val : Elements)
    {
        cout<<val<<" ";
    }
    cout<<endl;


}