#include<iostream>
#include<vector>
using namespace std;
template <typename T>

//TreeNode class using vector for its childrens

class TreeNode {
    public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data){
        this->data= data;
    } 
    //Insted of delete tree function below we can also use directly as destructor.
    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};

//Print Tree using recursion

void printTree(TreeNode<int> *root){
    cout<<root->data<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}

void printTree2(TreeNode<int> *root){
    if(root==NULL) //edge case don't confuse it with base case.
        return;
    cout<<root->data<<" : ";
    for(auto x: root->children){
        cout<<x->data<<", ";
    }
    cout<<endl;
    for(int i=0; i<root->children.size(); i++){
        printTree2(root->children[i]);
    }
}

//if we call "delete root" only then data & vector is deleted but childrens are not deleted.
//So first we should delete children then only parents. Like post-order traversal.

void deleteTree(TreeNode<int> *root){
    for(int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
    TreeNode<int> *root= new TreeNode<int>(10);
    TreeNode<int> *node1= new TreeNode<int>(20);
    TreeNode<int> *node2= new TreeNode<int>(30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    printTree(root);
    printTree2(root);
}