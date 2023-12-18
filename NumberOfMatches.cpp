#include<bits/stdc++.h>
using namespace std;

int NumberOfMatches(int n)
{
    int matches =0;

    while(n>1)
    {
        if(n%2 == 0)
        {
            matches += n/2;
            n =n/2;
        }
        else
        {
            matches += (n-1) /2;
            n = ((n-1) / 2) + 1;
        }
    }
    return matches;
}

int main()
{
    int n;
    cout<<"no. of teams"<<endl;
    cin>>n;

    cout<<"Total no. of matches "<<NumberOfMatches(n);
}