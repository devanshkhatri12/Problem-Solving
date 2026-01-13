#include <bits/stdc++.h>
using namespace std;
const int m = 1e9+7;

long long myPow(int a, long long b)
{
    if(b == 0) return 1;
    if(b == 1) return a;

    long long half = myPow(a, b/2);

    long long result = (half * half) % m;

    if(b % 2 == 1)
    {
        return (result * a) % m;
    }

    return result;
}

// Optimal approach: TC - O(logn) , SC - O(1)
long long goodNumbers(long long n)
{
    return (long long)(myPow(5, (n+1)/2) * myPow(4, n/2)) % m ;
}

int main() {

    long long n;
    cout<<"enter number n: "<<endl;
    cin>>n;

    long long ans = goodNumbers(n);

    cout<<"Total good numbers are: "<<ans<<endl;

    return 0;
}