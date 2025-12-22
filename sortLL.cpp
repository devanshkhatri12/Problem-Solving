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


    Node* mergeLL(Node* list1, Node* list2) {
        
        Node* dummyNode = new Node(-1);
        
        
        Node* temp = dummyNode;

        
        while (list1 != nullptr && list2 != nullptr) {
           
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            
            temp = temp->next;
        }

        
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummyNode->next;
    }

Node* findMiddle(Node* &head)
{
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Optimal approach : TC - O(n logn) , SC - O(n)[bcz of reverse stack]
Node* sortLL(Node* &head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* middleNode = findMiddle(head);

        Node* right = middleNode->next;
        middleNode->next = nullptr;
        Node* left = head;

        // Recursively sort both halves
        left = sortLL(left);
        right = sortLL(right);


    return mergeLL(left ,  right);
    
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