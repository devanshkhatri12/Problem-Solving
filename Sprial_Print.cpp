#include<bits/stdc++.h>
using namespace std;


void SprialPrint(int arr[][3] ,int n, int m)
{
    int total = n * m;
    int count =0;
    int ans;

    int StartingRow =0;
    int StartingCol =0;
    int EndingRow = n-1;
    int EndingCol = m-1;

    while(count < total)
    {
        // starting ROW
        for(int index=StartingCol; count<total && index<=EndingCol; index++)
        {
            cout<<arr[StartingRow][index]<<" ";
            count++;
        }
        StartingRow++;

        // Ending COLUMN
        for(int index=StartingRow; count< total && index<=EndingRow; index++)
        {
            cout<<arr[index][EndingCol]<<" ";
            count++;
        }
        EndingCol--;

        // Ending ROW
        for(int index=EndingCol; count<total && index>=StartingCol; index--)
        {
            cout<<arr[EndingRow][index]<<" ";
            count++;
        }
        EndingRow--;

        // Starting COLUMN
        for(int index=EndingRow; count<total && index>=StartingRow; index--)
        {
            cout<<arr[index][StartingCol]<<" ";
            count++;
        }
        StartingCol++;
    }
}


int main()
{
    int arr[3][3];

    // Input array
    cout<<"Input Elements"<<endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    cout<<"Sprial Printing the Elements"<<endl;
    SprialPrint(arr,3,3);
}