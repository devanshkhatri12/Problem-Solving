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