#include<bits/stdc++.h>
using namespace std;

bool allzeros(vector<int>& Counter)
{
    for(int &i : Counter)
    {
        if(i != 0)
        {
            return false;
        }
    }
    return true;
}

int search(string pattern, string text)
{
    int n = text.length();

    vector<int> Counter(26, 0);

    // count the freq of each character in patterns
    for(int i=0; i<pattern.length(); i++)
    {
        char ch = pattern[i];

        Counter[ch -'a']++;
    }

    int i=0 , j=0;
    int k = pattern.length();
    int result = 0;

    while(j < n)
    {
        Counter[text[j] - 'a']--;

        if((j-i+1) == k)
        {
            if(allzeros(Counter))
            {
                result++;
            }

            Counter[text[i] -'a']++;                // i pr jo char h uski freq. normal krdi
            i++;
        }
        j++;
    }
    return result;
}

int main()
{
    string text = "forxxorfxdofr";
    string pattern  = "for";

    int ans = search(pattern , text);

    cout<<"total NO. Anagrams occur "<<ans<<endl;
}