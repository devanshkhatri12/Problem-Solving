#include<bits/stdc++.h>
using namespace std;

void inputElements(vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cin>>v[i];
    }
    cout<<endl;
}

// Brute Approach ->  TC - O(N) , SC - O(N)
void rotateArrayLeft(vector<int>& v, int k)
{
    int n = v.size();
    vector<int> temp(n);

    for(int i=0; i<n; i++)
    {
        temp[i] = v[(i+k)%n];
    }

    v = temp;                        // copy into original array
}

// Better Approach -> TC - O(N+K) , SC - O(K)
void rotateArrayLeft(vector<int>&v , int k)
{
    int n = v.size();
    vector<int> temp(n);
    k = k%n;

    for(int i=0; i<k; i++)
    {
        temp[i] = v[i];
    }

    for(int i=k; i<n; i++)
    {
        v[i-k] = v[i];
    }

    int j=0;
    for(int i=n-k; i<n; i++)
    {
        v[i] = temp[j];
        j++;
    }
}

int main()
{
    int n;
    cout<<"size of vector"<<endl;
    cin>>n;

    vector<int> v(n);

    inputElements(v);

    int k;
    cout<<"Rotate number ";
    cin>>k;

    rotateArrayLeft(v , k);

    cout<<"After Rotation "<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}