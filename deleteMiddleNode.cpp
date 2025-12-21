#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(node* &head, int data)
{
    node* temp = new node(data);

    temp->next = head;
    head = temp;
}

void printNode(node* &head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Brute approach : TC - O(2 * length) , SC - O(1)
node* deleteNode(node* &head, int n)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }

    
    node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if(count == n){
        node* newHead = head->next;
        delete head;
        return newHead;
    }

    int result = count - n;
    temp = head;

    while(temp != NULL)
    {
        result--;
        if(result == 0)
        {
            node* deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    int n;
    cout<<"enter node number from back"<<endl;
    cin>>n;

    node* node1 = new node(21);
    node* head = node1;


    insertNode(head, 23);
    insertNode(head, 37);
    insertNode(head, 1);
    insertNode(head, 20);

    cout<<"Before delete nth node from end"<<endl; 
    printNode(head);

    node* newHead = deleteNode(head, n);

    cout<<"After delete nth node from end"<<endl; 
    printNode(newHead);
}