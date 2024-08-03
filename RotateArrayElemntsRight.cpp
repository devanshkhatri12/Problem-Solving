#include<bits/stdc++.h>
using namespace std;


// Brute Approach ->  TC - O(N) , SC - O(N)
void rotateArrayRight(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> temp(n);

    for(int i=0; i<n; i++)
    {
        temp[(i+k)%n] = v[i];
    }

    v = temp;                        // copy into original array
}

// Better Approach -> TC - O(N+K) , SC - O(K)
void rotateArrayRight(vector<int>&v , int k)
{
    int n = v.size();
    vector<int> temp(n);
    k = k%n;

    int j=0;
    for(int i=n-1; i>=k; i--)
    {
        temp[j] = v[i];
        j++;
    }

    for(int i=0; i<k; i++)
    {
        v[k+i] = v[i];
    }

    for(int i=0; i<k; i++)
    {
        v[i] = temp[i];
    }
}

int main()
{
    int n;
    cout<<"size of vector"<<endl;
    cin>>n;

    vector<int> v = {1, 2, 3, 4};

    int k;
    cout<<"Rotate number ";
    cin>>k;

    rotateArrayRight(v , k);

    cout<<"After Rotation "<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}