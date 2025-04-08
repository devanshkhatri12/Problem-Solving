#include<bits/stdc++.h>
using namespace std;

// Brute approach
int NumSquare(int num)
{
    return floor(sqrt(num));
}

// Better approach: Liner search: TC - O(n) , SC- O(1)
int NumSquare(int num)
{
    int ans = 0;

    for(int i=1; i<=num; i++)
    {
        if((i*i) <= num)
        {
            ans= i;
        }
        else
        {
            break;
        }
    }

    return ans;
}

// Optimal Approach: TC -O(logn) , SC - O(1);
int NumSquare(int num)
{
    int low=1, high=num, ans=0;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if((mid*mid) <= num)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return ans;
}

// Optimal Approach: Using Newton Rapson method: TC -O(logn) , SC - O(1)
int NumSquare(int num)
{
    long long x = num;

    while((x*x) > num)
    {
        x = (x + (x/num) / 2);
    }
    return (x*x) == num;
}

int main()
{
    int num;
    cout<<"Enter num to find perfect sqaure root or floor of num"<<endl;
    cin>>num;

    int ans = NumSquare(num);
    cout<<"floor or perfect square of num is: "<<ans<<endl;

}