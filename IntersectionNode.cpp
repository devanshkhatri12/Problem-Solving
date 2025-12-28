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

node* convert(node* listA, node* listB, int d)
{
    node* t1 = listA;
    node* t2 = listB;

    while(d)
    {
        d--;
        t2 = t2->next;
    }

    while(t1 != t2)
    {

        t1 = t1->next;
        t2 = t2->next;
    }

    return t1;
}

// Optimal approach (method -1): TC - O(n1 + 2n2) , SC - O(1)
// way - I
node* intersectionPoint(node* &headA, node* &headB)
{
    int n1 = 0, n2 = 0;
    node* tempA = headA;
    node* tempB = headB;

    while(tempA != nullptr)
    {
        n1++;
        tempA = tempA->next;
    }

    while(tempB != nullptr)
    {
        n2++;
        tempB =tempB->next;
    }

    if(n1 < n2)
    {
        return convert(headA , headB, n2-n1);
    }else{
        return convert(headB , headA, n1-n2);
    }

    
}
int getDifference(node* listA, node* listB)
{
    int n1 = 0 , n2 = 0;
    while(listA != nullptr || listB != nullptr)
    {
        if(listA == nullptr)
        {
            ++n1;
            listA = listA->next;
        }

        if(listB == nullptr)
        {
            ++n2;
            listB = listB->next;
        }

    }

    return n1 - n2;
}

// way - II
node* intersectionPoint(node* headA, node* headB)
{
    node* t1 = headA;
    node* t2 = headB;

    int diff = getDifference(headA, headB);

    if(diff < 0)
    {
        while(diff++ != 0) t2 = t2->next;
    }else{
        while(diff-- != 0) t1 = t1->next;
    }

    while(t1 != nullptr)
    {
        if(t1 == t2) return t1;

        t1 = t1->next;
        t2 = t2->next;
    }

    return t1;

}

// Optimal approach (method - 2) : TC - O(2MAX(N1, N2)) , SC - O(1) 
// way - I
node* intersectionPoint(node* headA , node* headB)
{
    node* l1 = headA;
    node* l2 = headB;

    while(l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next;

        if(l1 == l2) return l1;

        if(l1 == nullptr) l1 = headB;
        if(l2 == nullptr) l2 = headA;
    }

    return l1;
}

// Optimal approach (method - 2): TC - O(2 max(N1 , N2)) , SC - O(1)
// way - II
node* intersectionPoint(node* headA , node* headB)
{
    node* l1 = headA;
    node* l2 = headB;

    while(l1 != l2)
    {
        l1 = l1 == nullptr ? headB : l1->next;
        l2 = l2 == nullptr ? headA : l2->next;
    }

    return l1;
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