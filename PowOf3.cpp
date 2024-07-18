#include<iostream>
#include<math.h>
using namespace std;

bool Power(int n)
{
    int ans = 0;
    for(int i=0; i<=30; i++)
    {
        ans = pow(3,i);
        if(ans == n)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int n;
    cin>>n;

    if(Power(n))
    {
        cout<<n<<" Comes in power of 3 "<<endl;
    }
    else
    {
        cout<<"power of 3 possible nhi h"<<endl;
    }
}
