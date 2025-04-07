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


int main()
{
    int num;
    cout<<"Enter num to find perfect sqaure root or floor of num"<<endl;
    cin>>num;

    int ans = NumSquare(num);
    cout<<"floor or perfect square of num is: "<<ans<<endl;

}