#include<bits/stdc++.h>
using namespace std;

int firstOccur(vector<int> &v , int target)
{
    int n = v.size();
    int first = -1;
    int start=0, end=n-1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(v[mid] == target)
        {
            first = mid;
            end = mid-1;
        }
        else if(v[mid] > target)
        {
            end= mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return first;
}

int lastOccur(vector<int> &v , int target)
{
    int n = v.size();
    int last = -1;
    int start=0, end=n-1;
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        if(v[mid] == target)
        {
            last = mid;
            start = mid+1;
        }
        else if(v[mid] < target)
        {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return last;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3, 3};
    int target = 3;

    int first = firstOccur(v , target);
    int last = lastOccur(v , target);

    if(first == -1)
    {
        cout<<"not Occur"<<endl;
    }
    cout<<"Occur "<<last - first + 1<<" times"<<endl;

}