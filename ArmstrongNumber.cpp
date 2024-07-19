#include<bits/stdc++.h>
using namespace std;

bool ArmstrongNumber(int n)
{
    int sum = 0;
    int temp = n;

    while(n)
    {
        int lastdigit = n % 10;

        sum = sum + pow(lastdigit , 3);

        n /= 10;
    }

    if(temp == sum)
    {
        return true;
    }
    return false;
}

int main()
{
    int n; 
    cout<<"Enter a number "<<endl;
    cin>>n;

    if(ArmstrongNumber(n))
    {
        cout<<"Yes, It is Armstrong number"<<endl;
    }
    else{
        cout<<"No, it is not a Armstrong number"<<endl;
    }
}