#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Pair {
    public:
    Node* head;
    Node* tail;
};

//Reverse of a linked-list using brute-force recursion. Time Complexity: O(N^2)

Node* reverseLL1(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead= reverseLL1(head->next);
    Node* temp= newHead;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= head;
    head->next= NULL;
    return newHead;
}

//Using the pair class we can optimise the time taken. Time Complexity: O(N)

Pair reverseLL2Helper(Node* head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head= head;
        ans.tail= head;
        return ans;
    }
    Pair smallAns= reverseLL2Helper(head->next);
    smallAns.tail->next= head;
    head->next= NULL;
    Pair ans;
    ans.head= smallAns.head;
    ans.tail= head;
    return smallAns;
}
Node* reverseLL2(Node *head){
    return reverseLL2Helper(head).head;
}

//Reverse of a linked-list recursion using best possible approach. Time Complexity: O(N)

Node* reverseLL3(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead= reverseLL3(head->next);
    Node* tail= head->next;
    tail->next= head;
    head->next= NULL;
    return newHead;
}
