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

int main()
{
    vector<int> arr1 = {1, 1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 6};

    unionElem(arr1, arr2);

}