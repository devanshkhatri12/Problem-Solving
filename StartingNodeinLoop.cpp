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

// Brute approach : TC - O(n * 2logn) , SC - O(N)
Node* startingNode(Node* &head)
{
    Node* temp = head;
    map<Node* , int> mp;

    while(temp != NULL)
    {
        if(mp.find(temp) != mp.end())
        {
            return temp;
        }

        mp[temp] = 1;

        temp = temp->next;
    }

    return NULL;
}

// Optimal approach : TC - O(n/2 * l1) , SC - O(1)
Node* startingNode(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;

            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
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

    Node* node = startingNode(head);

    cout<<"the first node is : "<<node->data<<endl;

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;

}