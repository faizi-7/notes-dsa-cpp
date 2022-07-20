#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data= d;
        this->left= NULL;
        this->right= NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in the left "<<endl;
    root->left= buildTree(root->left);
    cout<<"Enter data for inserting in the right "<<endl;
    root->right= buildTree(root->right);
    return root;
}

void buildTreeFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for the root"<<endl;
    int leftData;
    int rightData;
    int data;
    cin>>data;
    root= new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp= q.front();
        q.pop();
        
        cout<<"Enter data to the left of "<<temp->data<<endl;
        cin>>leftData;
        
        if(leftData!=-1){
            temp->left= new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data to the right of "<<temp->data<<endl;
        cin>>rightData;

        if(rightData!=-1){
            temp->right= new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp==NULL){ //old level has been completed
            
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        } else {

            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}


void reverseLevelOrder(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        s.push(temp);

        q.pop();
            
        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

    while(!s.empty()){
        node* top= s.top();
        cout<<top->data<<" ";
        s.pop();
    }
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}
 
//Implement Reverse Level Order Traversal
//Implement Inorder Preorder & Postorder using iteration



int main(){
    node* root= NULL;

    // Input: 2 4 8 -1 -1 10 -1 -1 5 11 -1 -1 -1

    buildTreeFromLevelOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    reverseLevelOrder(root);

    /* root= buildTree(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);
    cout<<"Inoreder Traversal: ";
    inOrder(root);
    cout<<endl;
    cout<<"PreOrder Traversal: ";
    preOrder(root);
    cout<<endl;
    cout<<"PostOrder Traversal: ";
    postOrder(root);
    cout<<endl; */

    return 0;
}