#include<bits/stdc++.h>
using namespace std;

// Brute approach: TC -O(N), SC -O(1)
int countPairs(int low , int high)
{
    int count = 0;
    for(int i=low; i<=high; i++)
    {
        string s = to_string(i);

        int len = s.length();

        if(len%2 != 0){
            continue;
        }


        int first_half = 0;
        int second_half =0;
        

        for(int i=0; i<len/2; i++)
        {
            first_half += s[i] - '0';
        }


        for(int i=len/2; i<len; i++)
        {
            second_half += s[i] - '0';
        }

        if(first_half == second_half)
        {
            count += 1;
        }
    }

    return count;

}


// Optimal approahc: TC -O(N), SC -O(1)
int countPairs(int low , int high){
     
    int count =0;
    for(int i=low; i<=high; i++)
    {
        if((i >= 10  &&  i <= 99) || (i%11 == 0))
        {
            count += 1;
        }
        else if((i >= 1000) && (i <= 9999))
        {
            string s = to_string(i);

            int len = s.length();
    
            if(len%2 != 0){
                continue;
            }
    
    
            int first_half = 0;
            int second_half =0;
            
    
            for(int i=0; i<len/2; i++)
            {
                first_half += s[i] - '0';
            }
    
    
            for(int i=len/2; i<len; i++)
            {
                second_half += s[i] - '0';
            }
    
            if(first_half == second_half)
            {
                count += 1;
            }
        
        }
        else
        {
            continue;
        }
    }

    return count;
}

int main()
{
    int low , high;

    cout<<"Enter low and high"<<endl;
    cin>>low>>high;

    int ans = countPairs(low ,high);

    cout<<"Number of symmertric pairs are: "<<ans<<endl;
}