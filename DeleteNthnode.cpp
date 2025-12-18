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

void printLL(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertNode(Node* &head, int data)
{
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

// Brute approach : TC - O(2n) , SC - O(1)
Node* deleteNthNode(Node* &head, int n)
{
    int count  = 0;
    Node* temp =head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int result = count - n;
    temp = head;

    while(temp != head)
    {
        result--;
        if(result == 0)
        {
            break;
        }
        temp = temp->next;
    }

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;

    return head;
}

int main()
{
    int n;
    cout<<"Nth node that wants to delete"<<endl;
    cin>>n;

    Node* node = new Node(10);
    Node* head = node;

    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 14);

    cout<<"Before delete nth node from last"<<endl;
    printLL(head);

    deleteNthNode(head, n);

    cout<<"After delete nth node form last"<<endl;
    printLL(head);

    return 0;
}