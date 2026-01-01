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

node* reverse(node* &head)
{
    if(head == nullptr || head->next == nullptr) return head;


    node* newHead = reverse(head->next);
    node* frontNode= head->next;
    
    frontNode->next = head;
    head->next = nullptr;
    return newHead;
}

// Brute approach : TC - O(3N) , SC - O(1)
node* addOne(node* &head)
{
    head = reverse(head);
    node* temp = head;
    int carry = 1;

    while(temp != nullptr)
    {
        temp->data = temp->data + carry;

        if(temp->data < 10)
        {
            carry = 0;
            break;
        }else{
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if(carry == 1)
    {
        node* newNode = new node(carry);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;

}

int helper(node* &head)
{
    node* temp = head;
    if(temp == nullptr) return 1;

    int carry = helper(temp->next);
    temp->data = temp->data + carry;

    if(temp->data < 10) return 0;

    temp->data = 0;
    return 1;
}

// Optimal approach : TC - O(N) , SC - O(N)
node* addOne(node* &head)
{
    int carry = helper(head);
    if(carry == 1){
        node* newNode = new node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}

int main()
{
    cout<<"enter input elements"<<endl;
    node* head = takeInput();
    cout<<endl;


    cout<<"List before adding 1 to list"<<endl;
    printList(head);

    node* newHead = addOne(head);

    cout<<"List after adding 1 to List"<<endl;
    printList(newHead);

    return 0;

}