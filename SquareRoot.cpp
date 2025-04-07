#include<bits/stdc++.h>
using namespace std;

// Brute approach
int NumSquare(int num)
{
    return floor(sqrt(num));
}


int main()
{
    int num;
    cout<<"Enter num to find perfect sqaure root or floor of num"<<endl;
    cin>>num;

    int ans = NumSquare(num);
    cout<<"floor or perfect square of num is: "<<ans<<endl;

}