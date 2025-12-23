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

node* takeInput() {
    int x;
    cin >> x;

    node* head = NULL;
    node* tail = NULL;

    while (x != -1) {
        node* newNode = new node(x);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> x;
    }
    return head;
}

node* convert(vector<int>& list)
{
    int n = list.size();

    if(n == 0) return nullptr;

    node* head = new node(list[0]);
    node* current = head;

    for(int i=1; i<n; i++)
    {
        current->next = new node(list[i]);
        current = current->next;
    }

    return head;
}


// Optimal approach : TC - O(n + m) , Sc - O(1)
node* mergeSortedLists(node* &head1, node* head2)
{
    node* list1 = head1;
    node* list2 = head2;

    node* dummyNode = new node(-1);
    node* temp = dummyNode;

    while(list1 != nullptr && list2 != nullptr)
    {
        if(list1->data <= list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }

    }   

    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummyNode->next;
}

// Brute approach : TC - O(2 * (n + m)  +  logn) , SC - O(n * m)
node* mergeSortedLists(node* &head1, node* head2)
{
    vector<int> list;
    node* temp1 = head1;
    
    while(temp1 != nullptr)
    {
        list.push_back(temp1->data);
        temp1 = temp1->next;
    }

    node* temp2 = head2;

    while(temp2 != nullptr)
    {
        list.push_back(temp2->data);
        temp2 = temp2->next;
    }

    sort(list.begin() , list.end());

    node* newHead = convert(list);

    return newHead;

}

int main()
{
    cout<<"enter list 1 element"<<endl;
    node* head1 = takeInput();

    cout<<"enter list 2 elements"<<endl;
    node* head2 = takeInput();

    node* newHead = mergeSortedLists(head1, head2);

    cout<<"Sorted Linked list"<<endl;
    printList(newHead);
}