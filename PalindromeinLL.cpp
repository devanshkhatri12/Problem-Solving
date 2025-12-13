#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head, int data)
{
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

// Brute approach : TC - O(2n) , SC - O(n)
bool checkPalindrome(Node* &head)
{
    stack<int> st;
    Node* temp = head;

    while(temp != NULL)
    {
        st.push(temp->data);
        
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL)
    {
        if(st.top() != temp->data){
            return false;
        }
        st.pop();

        temp = temp->next;
    }

    return true;
}

int main()
{
    Node* node = new Node(10);
    Node* head = node;

    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 12);
    insertNode(head, 11);
    insertNode(head, 10);

    if(checkPalindrome(head))
    {
        cout<<"Given Linked List has Palindrome "<<endl;
    }else{
        cout<<"Linked List has not any Palindrome "<<endl;
    }

    return 0;
    
}