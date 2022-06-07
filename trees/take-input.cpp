#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>

class TreeNode {
    public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data){
        this->data= data;
    }
};

//Take Input using Recursion

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data: "<<endl;
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the number of children of "<<rootData<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        TreeNode<int>* child= takeInput();
        root->children.push_back(child);
    }
    return root;
}

//Take Input level wise using queue

TreeNode<int>* takeInputLevelwise(){
    
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;
    TreeNode<int> *root= new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0; i<numChild; i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child= new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}