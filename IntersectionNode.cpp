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

void print(node* &head)
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
            tail = newNode;
        }
        cin>>x;
    }

    return head;

}



// Brute approach : TC - O(n^2) , SC - O(1)
node* intersectionPoint(node* &headA, node* &headB)
{
    while(headB != nullptr)
    {
        node* temp = headA;

        while(temp != nullptr)
        {
            if(headB == temp) return headB;

            temp = temp->next;
        }

        headB = headB->next;
    }

    return nullptr;
}

// Better approach : TC - O(2n) , SC - O(n);
node* intersectionPoint(node* &headA, node* &headB)
{
    node* tempA = headA;
    node* tempB = headB;

    unordered_map<node* , int> mp;

    while(tempA != nullptr)
    {
        mp[tempA] = 1;
        tempA = tempA->next;
    }

    while(tempB != nullptr)
    {
        if(mp.find(tempB) != mp.end())
        {
            return tempB;
            break;
        }

        tempB = tempB->next;
    }

    return nullptr;
}

void createIntersection(node* headA, node* headB, int pos) {
    if (pos <= 0) return;

    node* tempA = headA;
    node* tempB = headB;

    // Move tempA to the intersection position
    for (int i = 1; i < pos && tempA != nullptr; i++) {
        tempA = tempA->next;
    }

    if (tempA == nullptr) return;

    // Move tempB to last node
    while (tempB->next != nullptr) {
        tempB = tempB->next;
    }

    // Create intersection
    tempB->next = tempA;
}

int main()
{
    cout<<"Enter elements of List A"<<endl;
    node* headA = takeInput(); 

    cout<<"Enter elements of List B"<<endl;
    node* headB = takeInput();


    int pos;
    cout << "Enter intersection position in List A: ";
    cin >> pos;

    
    createIntersection(headA, headB, pos);


    node* intersectNode = intersectionPoint(headA, headB);

    print(intersectNode);


}