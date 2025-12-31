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

// Better appraoch : TC - O(2n) , SC - O(1)
node* sort012(node* &head)
{
    node* temp = head;
    int count0 = 0, count1 = 0, count2 = 0;

    while(temp != nullptr)
    {
        if(temp->data == 0){
            count0++;
            
        }else if(temp->data == 1)
        {
            count1++;

        }else{
            count2++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp != nullptr)
    {
        if(count0 != 0)
        {
            temp->data = 0;
            count0--;
        }else if(count1 != 0){
            temp->data = 1;
            count1--;
        }else{
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

// Optimal approach : TC - O(n) , SC - O(1);
node* sort012(node* &head)
{
    node* t1 = head;

    node* zeroNode = new node(-1);
    node* zero = zeroNode;

    node* oneNode = new node(-1);
    node* one = oneNode;

    node* twoNode = new node(-1);
    node* two = twoNode;

    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }

    while(t1 != nullptr)
    {
        node* newNode= t1->next;
        t1->next = nullptr;

        if(t1->data == 0)
        {
            zero->next = t1;
            zero = zero->next;

        }else if(t1->data == 1){
            one->next = t1;
            one = one->next;
        }else{
            two->next = t1;
            two = two->next;
        }

        t1 = newNode;
    }

    zero->next = (oneNode->next) ? oneNode->next : twoNode->next;
    one->next = twoNode->next;
    two->next = nullptr;

    head = zeroNode->next;

    delete zeroNode;
    delete oneNode;
    delete twoNode;

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