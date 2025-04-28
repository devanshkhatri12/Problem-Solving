#include<bits/stdc++.h>
using namespace std;

int evenlyDivides(int N){
        //code here
        int count = 0;
        int temp = N;
        
        while(N > 0)
        {
            int lastdigit = N % 10;
            
            if(lastdigit != 0 && temp % lastdigit == 0)
            {
                count += 1;
            }
            
            N = N / 10;
        }
        
        return count;
        
    }

int main()
{
    int n;
    cout<<"Enter no"<<endl;
    cin>>n;

    int ans = evenlyDivides(n);

    cout<<"total no. of digits which divides exaclty: "<<ans<<endl;


}