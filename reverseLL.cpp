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

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

// Brute approach : TC - O(2n) , SC - O(n)
Node* reverseLinkedList(Node* &head)
{
    Node* temp = head;
    stack<int> st;

    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL)
    {
        temp->data = st.top();
        st.pop();

        temp = temp->next;
    }

    return head;
}

// Better approach : TC - O(n) , SC - O(1)
Node* reverseLinkedList(Node* &head)
{
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;

}

// Optimal approach : TC - O() , SC - O()
Node* reverseLinkedList(Node* &head)
{
    // base case: list is empty or only 1 node 
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* newHead = reverseLinkedList(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    Node* node = new Node(10);
    
    Node* head = node;

    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 14);

    cout<<"Before reverse"<<endl;
    print(head);

    Node* newHead = reverseLinkedList(head);

    cout<<"After reverse"<<endl;
    print (newHead);
}