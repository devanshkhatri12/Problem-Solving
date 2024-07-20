#include<bits/stdc++.h>
using namespace std;

int GCD(int a , int b)
    {   
        while(a > 0 && b > 0)
        {
            if(a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }
        
        if(a == 0)
        {
            return b;
        }
        else
        {
            return a;
        }
    }

int main()
{
    int a , b;
    cout<<"Enter two numbers"<<endl;
    cin>>a>>b;

    int HCF = GCD(a,b);

    int LCM = (a*b)/HCF;

    cout<<"HCF IS "<<HCF<<endl;
    cout<<"LCM IS "<<LCM<<endl;
}