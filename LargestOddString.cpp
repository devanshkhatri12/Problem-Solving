// Find out largest odd string in a string

#include<bits/stdc++.h>
using namespace std;

// Brute approach : TC -O(n^2)
string largestOddNumber(string num)
{
    int n = num.length();

    long long maxi = INT_MIN;
    string result = "";
    for(int i=0; i<n; i++)
    {
        string newS = "";
        long long number = 0;
        for(int j=i; j<n; j++)
        {
            newS += num[j];
            number = stoll(newS);
            if(number%2 != 0)
            {
                if(number > maxi)
                {
                    maxi = number;
                    result = to_string(maxi);
                }
            }
        }
    }

    return result;
}



int main()
{
    string num;
    cout<<"Enter number in string"<<endl;
    cin>>num;

    string ans = largestOddNumber(num);

    cout<<"ODD number "<<'"'<<ans<<'"'<<endl;
}