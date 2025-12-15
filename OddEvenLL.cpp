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

void printNode(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Brute approach : TC - O(2n) , SC - O(n)
Node* oddEven(Node* &head)
{
    Node* temp = head;
    vector<int> Value;

    while(temp != NULL)
    {
        Value.push_back(temp->data);
        if (temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }


    temp = head->next;

    while(temp != NULL)
    {
        Value.push_back(temp->data);
        if (temp->next != NULL)
            temp = temp->next->next;
        else
            break;
    }


    int i=0;
    temp = head;

    while(temp != NULL)
    {
        temp->data = Value[i];
        i++;

        temp = temp->next;
    }

    return head;

}

// Optimal approach :  TC - O(n) , SC - O(1)
Node* oddEven(Node* &head)
{
    Node* odd = head;
    Node* even = head;
    Node* evenHead = head->next;

    while(even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
}

int main()
{
    Node* node = new Node(10);
    Node* head = node;

    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 14);
    insertNode(head, 15);

    cout<<"Before Segrregate Odd or Even"<<endl;
    printNode(head);

    Node* newHead = oddEven(head);

    cout<<"After Segrregate Odd or Even"<<endl;
    printNode(newHead);

    return 0;

}