#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//We can find the mid-point of a linked-list by mid-point= (length - 1)/2 where length is the length of the linked-list
//But if we want to find the mid-point without finding mid-point. 
//Using fast & slow pointer.

Node *midPoint(Node *head){   
    if(head!=NULL){
        Node *slow= head;
        Node *fast= head->next;

        //for odd-length stop as soon as fast reaches null. for even-length stop as soon as fast->next reaches null.
        //fast!=NULL && fast->next!=NULL this takes care of the both above con

        while(fast!=NULL && fast->next!=NULL){ 
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
}


