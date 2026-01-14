#include <bits/stdc++.h>
using namespace std;

void insertStack(stack<int>& st, int x)
{
    if(st.empty() || st.top() <= x){
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();

    insertStack(st, x);
    st.push(temp);
}

void sortStack(stack<int>& st)
{
    if(st.empty()) return;

    int topElement = st.top();
    st.pop();

    sortStack(st);

    insertStack(st, topElement);
}

int main() {

    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(2);


    sortStack(st);

    // Print stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}