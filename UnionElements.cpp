#include<bits/stdc++.h>
using namespace std;

// Brute approach - TC - O(nlogn) + O(mlogn) + O(n + m) , SC - O(n +m) + O(n + m)
void unionElem(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    set<int> st;

    for(int i=0; i<n; i++)
    {
        st.insert(arr1[i]);
    }

    for(int i=0; i<m; i++)
    {
        st.insert(arr2[i]);
    }
    vector<int> unionArr(st.size());

    int i=0;
    cout<<"Union elemts are: "<<endl;
    for(auto it : st)
    {
        unionArr[i] = it;
        cout<<unionArr[i]<<" ";
        i++;
    }
}

// Optimal approach - TC - O(n + m) , SC - O(n + m)
vector<int> unionElem1(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> unionArr;

    int i=0, j=0;
    while(i<n && j<m)
    {
        if(arr1[i] <= arr2[j])
        {
            if(unionArr.back() != arr1[i] || unionArr.size() == 0)
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.back() != arr2[j] || unionArr.size() == 0)
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n)
    {
        if(unionArr.back() != arr1[i] || unionArr.size() == 0)
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while(j<m)
    {
        if(unionArr.back() != arr2[j] || unionArr.size() == 0)
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

    unionElem(arr1, arr2);

    vector<int> Union = unionElem1(arr1, arr2);

    for(auto val : Union)
    {
        cout<<val<<" ";
    }
    cout<<endl;

}