#include<bits/stdc++.h>
using namespace std;

// Brute approach: TC - O(n*m) , SC - O(1)
bool search(vector<vector<int>>& matrix, int n, int m, int target)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] == target){
                return true;
            }
        }
    }

    return false;
}

bool binarySearch(vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(nums[mid] == target)
        {
            return true;
        }else if(nums[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    return false;
}

// Better approach: TC - O(n * logm) , SC - O(1)
bool search(vector<vector<int>>& matrix, int n, int m, int target)
{
    for(int i=0;i<n;i++)
    {
        // check for each row seprately
        if(matrix[i][0] <= target && target <= matrix[i][m-1]){
            // search element in each row
            return binarySearch(matrix[i], target);
        }
    }

    return false;
}

// Optimal approach : TC - O(n), SC - O(1)
bool search(vector<vector<int>>& matrix, int target) {

    int n = matrix.size();
    int m = matrix[0].size();
    
    // starting/ intial point to start traversal
    int i=0, j=m-1;

    while(i < n && j >= 0)
    {
        if(matrix[i][j] == target){
            return true;
        }
        else if(matrix[i][j] > target)
        {
            j--;
        }else{
            i++;
        }
    }

    return false;
}
int main()
{
    // int n, m;
    // cout<<"enter the size of row and column"<<endl;
    // cin>>n>>m;

    int target;
    cout<<"enter the element to search"<<endl;
    cin>>target;

    vector<vector<int>> matrix = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};


    if(search(matrix, 4, 4, target))
    {
        cout<<"Sucessfully found the Element..!"<<endl;
    }else{
        cout<<"Element not found !"<<endl;
    }

    return 0;
}