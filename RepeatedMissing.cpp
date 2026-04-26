#include<bits/stdc++.h>
using namespace std;

// Brute approach: TC - O(n2) , SC - O(1)
vector<int> repeatMiss(vector<int>& num)
{
    int n = num.size();
    int repeat = -1, missed = -1;

    for(int i=1;i<=n;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(num[j] == i)
            {
                count++;
            }
        }

        if(count == 2) repeat = i;
        if(count == 0) missed = i;

        if(repeat != -1 && missed != -1){
            break;
        }
    }
    return {repeat , missed};
}


int main()
{

    vector<int> num = {4, 6, 3, 2, 1, 1};

    vector<int> ans = repeatMiss(num);

    cout<<"repeating number is: "<<ans[0]<<endl;
    cout<<"missing number is: "<<ans[1]<<endl;

    return 0;

}