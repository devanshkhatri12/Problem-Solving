#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>& bloomDay, int day, int bouquek, int flower)
{
    int n = bloomDay.size();
    int count  =0, NumOfBouquet = 0;

    for(int i=0; i<n; i++)
    {
        if(bloomDay[i] <= day){
            count += 1;
        }
        else{
            NumOfBouquet += (count / flower);
            count = 0;
        }
    }

    NumOfBouquet += (count / flower);

    if(NumOfBouquet >= bouquek){
        return true;
    }
    return false;
}

// Brute approach: using Linear approach: TC -O(N) ,O(1)
int MinimumBloomDay(vector<int>& bloomDay, int m, int k)
{
    int n = bloomDay.size();

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++)
    {
        mini = min(mini , bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    int value = m * 1LL * k * 1LL;

    // edge case if total number of flower is less
    if(value > n)
    {
        return -1;
    }

    int ans = -1;

    for(int i=mini; i<=maxi; i++)
    {
        if(possible(bloomDay, i, m, k)){
            return i;
        }
    }
    return ans;
}


int main()
{
    vector<int> bloomDay = {7,7,7,7,13,11,12,7};

    int m;
    cout<<"no. of bouquek you want to make"<<endl;
    cin>>m;


    int k;
    cout<<"no. of flower per bouquek"<<endl;
    cin>>k;

    
    int ans = MinimumBloomDay(bloomDay, m, k);

    cout<<"Minimum no of day is "<<ans<<" to make "<<m<<" Bouquet"<<endl;

}