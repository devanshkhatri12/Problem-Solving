#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void printList(node* &head)
{
    node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

node* takeInput()
{
    int n;
    cin>>n;

    node* head = nullptr;
    node* tail = nullptr;

    while(n != -1)
    {
        node* newNode = new node(n);

        if(head == nullptr)
        {
            head = tail = newNode;
        }else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>n;
    }

    return head;
}

// Brtue approach : TC - O(n + nlogn + n) , SC - O(n)
node* sort012(node* &head)
{
    node* temp = head;
    vector<int> list;

    while(temp != nullptr)
    {
        list.push_back(temp->data);
        temp = temp->next;
    }

    sort(list.begin() , list.end());

    temp = head;
    int i=0;

    while(temp != nullptr)
    {
        temp->data = list[i];
        i++;


        temp = temp->next;
    }

    return head;
}

int main()
{
    cout<<"enter Elements"<<endl;
    node* head = takeInput();

    cout<<"List before Sorting"<<endl;
    printList(head);

    node* newHead = sort012(head);

    cout<<"List after Sorting"<<endl;
    printList(newHead);

}