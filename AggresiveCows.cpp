#include<bits/stdc++.h>
using namespace std;

bool CountCows(vector<int>& stalls, int minDistance, int cows)
{
    int CowCount = 1;
    int lastCoordinate = stalls[0];

    for(int i=1; i<stalls.size(); i++)
    {
        if(stalls[i] - lastCoordinate >= minDistance)
        {
            CowCount++;
            lastCoordinate = stalls[i];
        }

        if(CowCount >= cows) return true;
    }

    return false;
}

// Optimal approach: TC - O(logn) , SC - O(1)
int AggresiveCows(vector<int>& stalls, int cows)
{
    int n = stalls.size();

    if(cows < 2)
    return -1;

    sort(stalls.begin() , stalls.end());

    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(CountCows(stalls, mid, cows) == true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return high;
}

// Brtue appraoch: TC - O(n^2) , SC - O(1)
int AggresiveCows(vector<int>& stalls, int cows)
{
    int n = stalls.size();

    if(cows < 2)
    return -1;

    sort(stalls.begin() , stalls.end());

    int limit = stalls[n-1] - stalls[0];


    for(int i=1; i<=limit; i++)
    {
        if(CountCows(stalls, i, cows) == false){
            return (i-1);
        }
    }

    return limit;
}

int main()
{
    vector<int> stalls = {0,3,4,7,10,9};
    int n = stalls.size();
    int cows = 4;

    int ans = AggresiveCows(stalls, cows);
    cout<<"Maxi. of the min. distance b/w two cows "<<ans<<endl;

}