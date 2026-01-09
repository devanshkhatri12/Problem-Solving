#include<bits/stdc++.h>
using namespace std;

// Brute approach : using stl function
double power(double x, int n)
{
    double ans = pow(x,n);
    return ans;
}

// Better approach : TC - O(N) , SC - O(1)
double power(double x, int n)
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

    return ans;
}

// Optimal approach : recursive method : TC - O(logn) , SC - O(logn)[recursive stack]
double power(double x, int n)
{
    // base case
    if(n == 0) return 1;
    if(n == 1) return x;

    if(n % 2 == 0){
        return power(x*x, n/2);         // i.e 2^10 = (2 * 2)^5
    }

    return x*power(x, n-1);             // i.e 2^5 = 2 * 2^4
}

int main()
{
    double x;
    cout<<"enter number: ";
    cin>>x;

    int n;
    cout<<"enter exponent: ";
    cin>>n;

    double ans = power(x,n);

    cout<<"Power of x^n is: "<<ans<<endl;

    return 0;
}