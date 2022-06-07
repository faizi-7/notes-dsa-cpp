#include<iostream>
using namespace std;
 
class Node {
    public :
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
    Node *head;
    Node *tail;
    int size;
    
    public:
    Queue() {
        head=NULL;
        tail=NULL;
        size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void enqueue(int data) {
        if(head==NULL){
            Node *newNode=new Node(data);
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        Node *newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
        size++;
    }

    int dequeue() {
        if(isEmpty())
            return -1;
        int ans=head->data;
        Node *rem=head;
        head=head->next;
        delete []rem;
        size--;
        return ans;
    }

    int front() {
        if(isEmpty())
            return -1;
        return head->data;
    }
};