#include<bits/stdc++.h>
using namespace std;

// Brute approach : using stl function
void power(double x, int n)
{
    double ans = pow(x,n);
    cout<<"Power of x^n is: "<<ans<<setprecision(4)<<endl;
}

// Better approach : TC - O(N) , SC - O(1)
void power(double x, int n)
{
    double ans = 1;

    // base case
    if(n == 0 || x == 1.0) ans = 1;

    long long temp = n;

    if(n < 0)
    {
        x = 1/x;
        temp = -1*1LL*n;
    }

    for(long long i=0; i<temp; i++)
    {
        ans *= x;
    }

    cout<<"Power of x^n is: "<<ans<<endl;
}

int main()
{
    double x;
    cout<<"enter number: ";
    cin>>x;

    int n;
    cout<<"enter exponent: ";
    cin>>n;

    power(x,n);

    return 0;
}