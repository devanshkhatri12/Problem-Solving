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

// Rotate Array ELemts by 1 place
void rotateArray(vector<int>& v)
{
    int n = v.size();
    int temp = v[0];

    for(int i=1; i<n; i++)
    {
        v[i-1] = v[i];
    }

    v[n-1] = temp;
}

int main()
{
    int n;
    cout<<"size of vector"<<endl;
    cin>>n;

    vector<int> v(n);

    inputElements(v);

    rotateArray(v);

    cout<<"After Rotation "<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}