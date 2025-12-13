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

Node* reverseLinkedList(Node* &head)
{
    // base case:
    if(head->next == NULL || head == NULL)
    {
        return head;
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

// Optimal approach : TC - O(2n) , SC - O(1)
bool checkPalindrome(Node* &head)
{
    // base case
    if(head->next == NULL || head == NULL)
    {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    // step - 1 : find middle of LL
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // step - 2 : reverse second half
    Node* newHead = reverseLinkedList(slow->next);

    // step - 3 : take two pointers check and check palindrome
    Node* first = head;
    Node* second = newHead;

    while(second != NULL)
    {
        if(first->data != second->data){

            reverseLinkedList(newHead);
            return false;
        }

        first = first->next;
        second = second->next;

    }

    reverseLinkedList(newHead);
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