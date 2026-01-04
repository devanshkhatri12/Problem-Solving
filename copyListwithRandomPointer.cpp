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