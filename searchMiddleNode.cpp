#include<bits/stdc++.h>
using namespace std;

class listNode{

    public:
    int value;
    listNode* next;

    listNode(int value)
    {
        this->value = value;
        this->next = NULL;
    }
   
};

void insertNode(listNode* &head, int value)
{
    listNode* temp = new listNode(value);

    temp->next = head;
    head = temp;
}

void print(listNode* &head)
{
    listNode* temp = head;

    while(temp != NULL)
    {
        cout<<temp->value<<" ";
        temp = temp->next;
    }cout<<endl;
}

// Brute approach : TC - O(n + nlogn) , SC - O(1)
listNode* findMiddle(listNode* &head)
{
    listNode* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int middleNode = (count/2) + 1;
    temp = head;

    while(temp != NULL)
    {
        middleNode = middleNode - 1;

        if(middleNode == 0)
        {
            break;
        }
        temp = temp->next;
    }

    return temp;

}

int main()
{
    listNode* node = new listNode(10);

    listNode* head = node;

    cout<<"Inserting nodes"<<endl;

    insertNode(head, 11);
    insertNode(head, 12);
    insertNode(head, 13);
    insertNode(head, 14);
    // insertNode(head, 15);
    print(head);

    listNode* temp = findMiddle(head);
    cout<<"Print from middle"<<endl;
    print(temp);

    
}
