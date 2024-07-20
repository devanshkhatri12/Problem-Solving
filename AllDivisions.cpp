#include<bits/stdc++.h>
using namespace std;

void allDivisions(int n)
{
    vector<int> v;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n % i == 0)
        {
            v.push_back(i);
            if((n/i) != i)
            {
                v.push_back(n/i);
            }
        }
    }

    sort(v.begin() , v.end());
    for(auto it : v)
    {
        cout<<it<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter no."<<endl;
    cin>>n;

    allDivisions(n);
}