#include<bits/stdc++.h>
using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
        
        int count =0;

        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]%2 != 0)
            {
                count += 1;  
            }
            else
            {
                count = 0;
            }

            if(count == 3)
            {
                return true;
            }
        }

        return false;
    }

int main()
{
    
    vector<int> arr = {1,2,34,3,4,5,7,23,12};

    bool ans = threeConsecutiveOdds(arr);

    if(ans)
    {
        cout<<"Numbers are present"<<endl;
    }
    else{
        cout<<"Numbers are not present"<<endl;
    }
    
}