#include<bits/stdc++.h>
using namespace std;

vector<int> consecutiveSum(int n) 
{  
        vector<int> ans;
        if(n%3 == 0)
        {
            for(int i=2; i<n; i++)
            {
                if((i-1) + (i) + (i+1) == n)
                {
                    ans.push_back(i-1);
                    ans.push_back(i);
                    ans.push_back(i+1);
                }
            }
        }
        else
        {
            ans.push_back(-1);
            return ans;
            
        }
        
        return ans;
}

int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    vector<int> ans = consecutiveSum(n);

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
