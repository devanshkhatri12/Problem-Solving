#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>& arr, int pages)
{
    int pageSum = 0;
    int studentCount = 1;
    for(int i=0; i<arr.size(); i++)
    {
        if(pageSum + arr[i] <= pages)
        {
            pageSum += arr[i];
        }
        else{
            pageSum = arr[i];
            studentCount++;
        }
    }
    return studentCount;
}

// Brute approach(Linear search): TC - O((sum-max+1) * n) , SC: O(1)
int allocateBooks(vector<int>& arr, int n, int students)
{
    int low = *max_element(arr.begin() , arr.end());
    int high = accumulate(arr.begin() , arr.end(), 0);

    for(int pages = low; pages < high; pages++)
    {
        int validStudents = isPossible(arr, pages);

        if(validStudents == students)
        {
            return pages;
        }
    }

    return -1;

}

int main()
{

    int n = 5;
    vector<int> arr = {25, 46, 28, 49, 24};
    int students  = 4;

    int ans = allocateBooks(arr, n, students);

    cout<<" the maximum number of pages assigned to a student is minimized is: "<<ans<<endl;
    
}