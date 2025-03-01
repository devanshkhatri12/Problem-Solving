#include<bits/stdc++.h>
using namespace std;


// Variation 1 - find out element present at particular index
// TC - O(r) , SC - O(1)
int nCr(int n, int r)
{
    long long result = 1;
    for(int i=0; i<r; i++)
    {
        result = result * (n - i);
        result = result / (i+1);
    }
    return result;
}

// Variation 2 - Print the entire nth row of pascal triangle
// Brute approach:  TC - O(n*r) , SC-O(1)
void printROW(int row)
{
    // printing row
    for(int col=1; col<=row; col++)
    {
        cout<<nCr(row-1, col-1)<<" ";
    }
    cout<<endl;
}


int main()
{
    int row , col;
    cout<<"Enter row and col no."<<endl;
    cin>>row>>col;

    cout<<"The Element at position (row,col) is: "<<nCr(row-1, col-1)<<endl;

    cout<<"printing "<<row<<"th row"<<endl;
    printROW(row);
}