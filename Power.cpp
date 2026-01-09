#include<bits/stdc++.h>
using namespace std;

// Brute approach : using stl function
void power(double x, int n)
{
    double ans = pow(x,n);

    cout<<"Power of x^n is: "<<ans<<setprecision(4)<<endl;
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