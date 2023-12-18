#include<bits/stdc++.h>
using namespace std;

void WavePrint(int arr[][3], int n, int m)
{
    for(int col=0; col<m; col++)
    {
        // Odd case -> bottom to top
        if(col &1)
        {
            for(int row=n-1; row>=0; row--)
            {
                cout<<arr[row][col]<<" ";
            }
        }
        else           //even case -> top to bottom
        {
            for(int row=0; row<3; row++)
            {
                cout<<arr[row][col]<<" ";
            }
        }
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

    cout<<"Print Like a Wave"<<endl;
    WavePrint(arr,3,3);
}