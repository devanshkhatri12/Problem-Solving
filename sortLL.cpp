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

// Brute approach : TC - O(n * logn * n) , SC - O(n)
Node* sortLL(Node* &head)
{
    Node* temp = head;
    vector<int> list;

    while(temp != NULL)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    sort(list.begin() , list.end());

    temp = head;
    int i = 0;

    while(temp != NULL)
    {
        temp->data = list[i];
        i += 1;

        temp = temp->next;
    }

    return head;
}

int main()
{
    Node* node = new Node(101);
    
    Node* head = node;

    insertNode(head, 31);
    insertNode(head, 2);
    insertNode(head, 35);
    insertNode(head, 14);

    cout<<"Before sorting LL"<<endl;
    print(head);

    Node* newHead = sortLL(head);

    cout<<"After sorting LL"<<endl;
    print (newHead);
}