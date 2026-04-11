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

// Better approach: TC - O(n2) * O(logn) , SC - O(N)
vector<vector<int>> Sum(vector<int>& num)
{
    int n = num.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++)
    {
        set<int> hashSet;
        for(int j=i+1; j<n; j++)
        {
            int third =  - (num[i] + num[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int>temp = {num[i] , num[j], third};
                sort(temp.begin() , temp.end());
                st.insert(temp);
            }
            hashSet.insert(num[j]);
        }
    }

    return vector<vector<int>>(st.begin() , st.end());
}

// optimal approach: TC - nlogn + O(n*m), SC - O(no. of triplets)
vector<vector<int>> Sum(vector<int>& num)
{
    int n = num.size();
    vector<vector<int>> ans;

    sort(num.begin() , num.end());

    for(int i=0; i<n; i++){
        if(i>0 && num[i] == num[i-1]) continue;

        int j=i+1;
        int k=n-1;

        while(j<k)
        {
            int sum = num[i] + num[j] + num[k];
            if(sum < 0){
                j++;
            }else if(sum > 0)
            {
                k--;
            }
            else{
                vector<int> temp = {num[i] + num[j] + num[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j<k && num[j] == num[j-1]){
                    j++;
                }

                while(j<k && num[k] == num[k+1]){
                    k--;
                }
            }
        }

    }

    return ans;
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