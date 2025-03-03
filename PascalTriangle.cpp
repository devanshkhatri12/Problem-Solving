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


// Optimal approach: TC - O(row) , SC - O(1)
void printRow(int row)
{
    long long result  = 1;
    cout<<result<<" ";
    for(int col=1; col<row; col++)
    {
        result = result * (row - col);
        result = result / (col);
        cout<<result<<" ";
    }
    cout<<endl;
}


// Variation 3 - print entire pascal triangle
// Brute approach : TC - O(n^3)
void generate(int numRows) 
{
    int n = numRows;

    for(int row=1; row<=n; row++)       // O(n)
    {
        for(int col=1; col<=row; col++)     // O(n)
        {
            cout<<nCr(row-1,col-1)<<" ";    //      O(n)
        }
        cout<<endl;
    }
}

int main()
{
    int row , col;
    cout<<"Enter row and col no."<<endl;
    cin>>row>>col;

    cout<<"The Element at position (row,col) is: "<<nCr(row-1, col-1)<<endl;

    cout<<"printing "<<row<<"th row"<<endl;
    printROW(row);

    cout<<"printing "<<row<<"th row"<<endl;
    printRow(row);

    cout<<"printing Pascal triangle till the nth row"<<endl;
    generate(row);
}