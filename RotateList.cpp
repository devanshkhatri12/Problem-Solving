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


// Brute approach : TC - O(3N) , sc - O(N)
    node* rotateRight(node* head, int k)
    {

        node* temp = head;
        vector<int> list;
        

        while(temp != nullptr)
        {
            list.push_back(temp->data);
            temp = temp->next;
        }

        int n = list.size();
        vector<int> v(n, 0);

        for(int i=0; i<n; i++)
        {
            v[(i+k)%n] = list[i];
        }

        temp = head;
        int i=0;

        while(temp != nullptr)
        {
            temp->data = v[i];
            i++;

            temp = temp->next;
        }

        return head;
    }

node* lastNode(node* temp, int l)
{
    if(temp == nullptr || l <= 0) return nullptr;

    int count = 1;
    while(temp != nullptr)
    {
        if(count == l) return temp;
        
        temp = temp->next;
        count++;
    }
    return nullptr;
}

// Optimal approach : TC - O(2N) , SC - O(1)
node* rotateRight(node* &head, int k)
{
    node* tail = head;
    int len = 1;           // we don't go the nullptr that why we keep the length initiliaze with 1


    while(tail->next != nullptr)
    {
        tail = tail->next;
        len++;
    }

    if(k % len == 0) return head;

    k = k % len;

    tail->next = head;
    node* newLastNode = lastNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = nullptr;

    return head;

}

int main()
{
    int k;
    cout<<"input k"<<endl;
    cin>>k;

    cout<<"enter list elements"<<endl;
    node* head = takeInput();

    cout<<"List before rotate k times"<<endl;
    printList(head);

    rotateRight(head, k);

    cout<<"List before rotate k times"<<endl;
    printList(head);

    return 0;

}