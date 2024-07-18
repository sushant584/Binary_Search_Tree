#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* InsertIntoBST(Node*root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=InsertIntoBST(root->left,data);
    }
    else{
        root->right=InsertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=InsertIntoBST(root,data);
        cin>>data;
    }
}
int MinVal(Node*root){
    Node*temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

int MaxVal(Node*root){
    Node*temp=root;
    if(temp==NULL){
        return -1;
    }
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;

}

int main(){
    Node*root=NULL;
    cout<<"enter the data for Node"<<endl;
    takeInput(root);

    cout<<"minimum value :"<<MinVal(root)<<endl;
    cout<<"maximum value :"<<MaxVal(root)<<endl;


}