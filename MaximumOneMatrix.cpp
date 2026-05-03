#include<bits/stdc++.h>
using namespace std;

// Brute approach : TC - O(n2) , SC - O(1)
int Mat(vector<vector<int>>& matrix, int n, int m)
{
    int maxiRow = 0;
    int index = -1;
    
    for(int i=0;i<n;i++)
    {
        int countOne = 0;
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j] == 1){
                countOne++;
            }
        }
        
        if(countOne == n){
            return i;
            break;
        }
        
        if(countOne > maxiRow){
            maxiRow = countOne;
            index = i;
        }
    }
    
    return index;
}

int lowerBound(vector<int>& arr, int n, int target)
{   
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] >= target)
        {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

// Optimal approach : TC - O(n * logm), SC - O(1)
int Mat(vector<vector<int>>& matrix, int n, int m)
{   
    int countMax = 0;
    int index = -1;

    for(int i=0;i<n;i++)
    {   
        // 1s = total - first index of 1
        int countOne = m - lowerBound(matrix[i], m, 1);

        if(countOne > countMax)
        {
            countMax = countOne;
            index = i;
        }
    }

    return index;

}

int main() {
    
    vector<vector<int>> matrix = {{1, 0, 0}, {1, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;


    cout << "The row with maximum no. of 1's is: " << Mat(matrix, n, m) << '\n';

    return 0;
}