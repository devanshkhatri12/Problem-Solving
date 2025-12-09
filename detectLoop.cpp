#include<bits/stdc++.h>
using namespace std;

class Node
{
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

// Brute approach : TC - O(N * 2logn) , SC - O(N)
bool detectCycle(Node* &head)
{
    Node* temp = head;
    map<Node* , int> mp;

    while(temp != NULL)
    {
        if(mp.find(temp) != mp.end()){
            return true;
        }

        mp[temp] = 1;

        temp = temp->next;
    }

    return false;
}

// Optimal apporach - (tortoise and Head algorithm) : TC - O(N/2) , SC - O(1)
bool detectCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Check if loop exists
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;

}