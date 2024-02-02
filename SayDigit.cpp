#include<iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    // Basecase 
    if(n == 0)
    return ;

    // processing
    int digit = n % 10;
    n = n / 10;

    sayDigit(n ,arr);

    cout<<arr[digit]<<" ";
}

int main()
{
    int n;
    cin>>n;


    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    cout<<endl<<endl;
    sayDigit(n, arr);
    cout<<endl<<endl;
}