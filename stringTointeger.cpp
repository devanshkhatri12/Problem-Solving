#include <bits/stdc++.h>
using namespace std;


// Optimal approach : TC - O(N) , SC - O(1)
long long stringTointeger(string s)
{
    int n = s.length();
    int i=0;

    // handle white spaces
    while(i<n && s[i] == ' ')
    {
        i++;
    }

    // string contain all the white space 
    if(i == n){
        return 0;
    }

    // handle sign
    int sign = 1;
    if(s[i] == '-')
    {
        sign = -1;
        i++;
    }else if(s[i] == '+')
    {
        i++;
    }

    long long result = 0;
    while(i<n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        if(result > (long long)INT_MAX / 10 || result == (long long)INT_MAX / 10 && digit > 7)
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return (result * sign);
}

int main() {
    
    string s;
    cout<<"enter string ";
    getline(cin, s);

    long long ans = stringTointeger(s);

    cout<<"Final answer is: "<<ans<<endl;

    return 0;
}
