#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node* child;

    node(int data)
    {
        this->data = data;
        this->child = nullptr;
        this->next = nullptr;
    }
};

void printList(node* &head)
{
    node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->child;
    }cout<<endl;
}

node* takeInput()
{
    int n;
    cin>>n;

    node* head = nullptr;
    node* prev = nullptr;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;

        node* colHead = nullptr;
        node* colTail = nullptr;

        while(x != -1)
        {
            node* newNode= new node(x);

            if(!colHead)
            {
                colHead = colTail = newNode;
            }else{
                colTail->child = newNode;
                colTail = newNode;
            }
            cin>>x;
        }

        if(!head){
            head = colHead;
        }else{
            prev->next = colHead;
        }

        prev = colHead;
    }

    return head;
}

node* convert(vector<int> &list)
{
    int n = list.size();

    if(n == 0) return nullptr;

    node* head = new node(list[0]);
    node* temp = head;

    for(int i=1; i<n; i++)
    {
        temp->child = new node(list[i]);
        temp = temp->child;
    }

    return head;
}

node* flattening(node* &head)
{
    node* t1 = head;
    vector<int> list;

    while(t1 != nullptr)
    {
        node* t2 = t1;
        while(t2 != nullptr)
        {
            list.push_back(t2->data);
            t2 = t2->child;
        }
        t1 = t1->next;
    }

    sort(list.begin() , list.end());

    node* newHead= convert(list);

    return newHead;
}

int main()
{
    cout<<"input Elements"<<endl;
    node* head = takeInput();

    node* newHead = flattening(head);

    cout<<"Sorted Linked List"<<endl;
    printList(newHead);

    return 0;
}