#include<bits/stdc++.h>
using namespace std;

// Brute approach: TC - O(n3) , SC - 2 * O(no of triplets)
vector<vector<int>> Sum(vector<int>& num){
    int n = num.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(num[i] + num[j] + num[k] == 0){
                    vector<int> temp = {num[i] , num[j], num[k]};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin() , st.end());

}

int main()
{
    int n=6;

    vector<int> num(n);

    cout<<"enter elements"<<endl;
    for(int i=0; i<num.size(); i++)
    {
        cin>>num[i];
    }


    vector<vector<int>> ans = Sum(num);

    cout<<"Triplets are"<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;


}