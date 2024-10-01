#include<bits/stdc++.h>
using namespace std;


vector<int> rearrangeElements(vector<int>& num)
{
    int n= num.size();

    vector<int> positive;
    vector<int> negative;

    for(int i=0; i<n; i++)
    {
        if(num[i] > 0)
        {
            positive.push_back(num[i]);
        }
        else{
            negative.push_back(num[i]);
        }
    }

    int x =0;
    for(int i=0; i<n; i+=2)
    {
        num[i] = positive[x];
        x++;
    }

    int y=0;
    for(int i=1; i<=n; i+=2)
    {
        num[i] = negative[y];
        y++;
    }

    return num;

}

int main()
{
    vector<int> num = {3,1,-2,-5,2,-4};
    int n = num.size();

    cout<<"After Rearranging Elements"<<endl;

    rearrangeElements(num);

    int i=0;
    while(i<n)
    {
        cout<<num[i]<<" ";
        i++;
    }
    cout<<endl;

}