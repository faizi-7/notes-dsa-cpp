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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    Node *Dummy= new Node(-1);
    Node *finalHead= Dummy;
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            finalHead->next=head1;
            head1=  head1->next;
        }
        else{
            finalHead->next= head2;
            head2= head2->next;
        }
        finalHead=finalHead->next;
    }
    while(head1!=NULL){
        finalHead->next= head1;
        head1= head1->next;
        finalHead= finalHead->next;
    }
    while(head2!=NULL){
        finalHead->next= head2;
        head2= head2->next;
        finalHead= finalHead->next;
    }
    return Dummy->next;
}

Node *mergeSort(Node *head)
{   if(head!=NULL){
        if(head->next==NULL)
            return head;
        Node *slow= head;
        Node *fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        Node *head2= slow->next;
        slow->next= NULL;
        Node *ll1= mergeSort(head);
        Node *ll2= mergeSort(head2);
        return mergeTwoSortedLinkedLists(ll1,ll2);
    }
}