#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node* random;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};

void printList(node* &head)
{
    node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* takeInput()
{
    int x;
    cin>>x;

    node* head = nullptr;
    node* tail = nullptr;

    while(x != -1)
    {
        node* newNode = new node(x);

        if(head == nullptr)
        {
            head = tail = newNode;

        }else{

            tail->next = newNode;
            tail = tail->next;
        }
        cin>>x;
    }

    return head;
}

// Brute approach : TC - O(2N) , SC - O(2N)
node* copyList(node* &head)
{
    node* temp = head;
    unordered_map<node* , node*> mp;

    // copy values in dummyList  
    while(temp != nullptr)
    {
        node* newNode = new node(temp->data);
        mp[temp] = newNode;

        temp = temp->next;
    }

    temp = head;

    // copy next pointer and random pointer in dummyList
    while(temp != nullptr)
    {
        node* copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];

        temp = temp->next;
    }

    return mp[head];
}


// Optimal status : TC - O(2N) , SC - O(N)
node* copyList(node* &head)
{
    node* temp = head;

    // first create node in middle  and insert values
    while(temp != nullptr)
    {
        node* nextElement = temp->next;
        node* copyNode = new node(temp->data);
        copyNode->next = nextElement;
        temp->next = copyNode;

        temp = nextElement;
    }

    // second copy random pointer 
    temp = head;
    while(temp != nullptr)
    {
        node* copyNode = temp->next;
        if(temp->random)
        {
            copyNode->random = temp->random->next;   
        }else{
            copyNode->random = nullptr;
        }

        temp = temp->next->next;
    }

    // copy next pointer
    temp = head;
    node* dummyNode = new node(-1);
    node* result = dummyNode;
    while(temp != nullptr)
    {
        // creating new LL
        result->next = temp->next;
        result = result->next;

        // disconnect and going back to initial state of LL
        temp->next = temp->next->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

int main()
{
    cout<<"Input list elements"<<endl;
    node* head = takeInput();
    cout<<endl;
    

    cout<<"Original List"<<endl;
    printList(head);

    copyList(head);

    cout<<"Copied List"<<endl;
    printList(head);

}