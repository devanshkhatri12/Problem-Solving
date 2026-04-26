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

// Better approach: TC - O(2n) , SC - O(n)
vector<int> repeatMiss(vector<int>& num)
{
    int n = num.size();
    vector<int> hashArr(n+1, 0);

    for(int i=0;i<n;i++)
    {
        hashArr[num[i]]++;
    }

    int repeat = -1, missed = -1;
    for(int i=1;i<=hashArr.size();i++)
    {
        if(hashArr[i] == 2){
            repeat = i;
        }

        if(hashArr[i] == 0){
            missed = i;
        }

        if(repeat != -1 && missed != -1){
            break;
        }
    }

    return {repeat, missed};
}

// Optimal approach : TC - O(n) , SC - O(1)
vector<int> repeatMiss(vector<int>& num)
{
    int n = num.size();

    long long Sn = (n * (n+1))/2;
    long long Sn2 = (n * (n+1) * (2*n + 1))/6;

    long long S = 0, S2 = 0;

    for(int i=0;i<n;i++)
    {
        S += num[i];
        S2 += (long long)num[i] * (long long)num[i];
    }

    long long val1 = S - Sn;
    long long val2 = S2 - Sn2;

    val2 = val2/val1;

    long long repeat = (val1 + val2)/2;
    long long missed = (repeat - val1);

    return {(int)repeat, (int)missed};
}

int main()
{

    vector<int> num = {4, 6, 3, 2, 1, 1};

    vector<int> ans = repeatMiss(num);

    cout<<"repeating number is: "<<ans[0]<<endl;
    cout<<"missing number is: "<<ans[1]<<endl;

    return 0;

}