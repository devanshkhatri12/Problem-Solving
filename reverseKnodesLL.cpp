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

// Brute approach : TC - O(3N) , SC - O(N)
node* reverseKnodes(node* &head, int k)
{
    node* temp = head;
    vector<int> list;
    int len = 0;

    if(head == nullptr || head->next == nullptr) return head;

    while(temp != nullptr)
    {
        len++;
        list.push_back(temp->data);
        temp = temp->next;
    }

    if(len == k)
    {
        reverse(list.begin() , list.end());
    }else{
        for(int i=0; i+k <= len; i += k)
        {
            reverse(list.begin() + i, list.begin() + i + k);
        }
    }

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
    int k;
    cout<<"enter k"<<endl;
    cin>>k;

    cout<<"enter List elements"<<endl;
    node* head = takeInput();
    cout<<endl;

    cout<<"List before reversing k-nodes"<<endl;
    printList(head);

    node* newHead = reverseKnodes(head, k);

    cout<<"List after reversing k-nodes"<<endl;
    printList(newHead);

}