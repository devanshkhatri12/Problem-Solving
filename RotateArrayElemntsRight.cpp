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