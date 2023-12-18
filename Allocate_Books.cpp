#include<iostream>
using namespace std;

bool ispossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0; i<n; i++)
    {
            if(pageSum + arr[i] <= mid )
            {
                pageSum += arr[i];
            }
            else
            {
                studentCount++;
                if(studentCount > m  || arr[i] > mid)
                {
                    return false;
                }
                pageSum = arr[i];
            }
    }
    return true;

}
int allocatebooks(int arr[], int n, int m)
{
    if(m > n)
    return -1;


    int s =0, sum =0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;

    int  mid = s + (e-s)/2;

    while(s <= e)
    {
        if(ispossible(arr,n,m,mid))
        {
            ans =mid;
            e = mid -1;
        }
        else
        {
            s = mid+1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;
}

int main()
{
    int n=4, m=2;
    int arr[10] ={10,20,30,40};

    // cout<<"No. of Pages"<<endl;
    // cin>>n;

    // cout<<"No. of Student"<<endl;
    // cin>>m;

    int result = allocatebooks(arr,n,m);
    cout<<"result is "<<result<<endl;


}