#include<bits/stdc++.h>
using namespace std;

// Brute approach : TC - O(N) , SC -O(1)
int Difference(int n, int m)
{
    int num1 = 0, num2=0;
    for(int i=1; i<=n; i++)
    {
        if(i%m != 0)
        {
            num1 += i;
        }
        else
        {
            num2 += i;
        }
    }

    return num1 - num2;
}

// Optimal Approach: TC - O(1) , SC - O(1)
int Difference(int n, int m)
{
    int k = n/m;

    return (n * (n+1)/2) - (k * m * (m+1));
}

int main()
{
    int n , m;
    cin>>n>>m;

    int ans  = Difference(n,m);

    cout<<"Sum of Divisible and Non-Divisible is: "<<ans<<endl;
    
}