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

// Optimal approach : TC - O(max(N1 , N2)) , SC - O(max(N1 , N2))
node* addTwo(node* &head1, node* &head2)
{
    node* l1 = head1;
    node* l2 = head2;

    node* currentNode = new node(-1);
    node* current = currentNode;

    int carry = 0;

    while(l1 != nullptr || l2 != nullptr)
    {
        int sum = carry;
        if(l1) sum += l1->data;
        if(l2) sum += l2->data;

        carry = sum / 10;

        current->next = new node(sum % 10);  // 🔥 FIX
        current = current->next;
        

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    if(carry)
    {
        node* newNode = new node(carry);
        current->next = newNode;
    }

    return currentNode->next;
}

int main()
{
    cout<<"enter list 1 elements"<<endl;
    node* head1 = takeInput();

    cout<<"enter list 2 elements"<<endl;
    node* head2 = takeInput();

    cout<<endl;



    node* newHead = addTwo(head1, head2);

    cout<<"List after adding two Lists"<<endl;
    printList(newHead);

    return 0;

}