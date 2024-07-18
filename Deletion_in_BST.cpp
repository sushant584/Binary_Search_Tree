#include<iostream>
#include<queue>
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

void LevelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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

Node* deleteNodeInBST(Node*root,int target){
    if(root==NULL){
        return NULL;
    }
    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node*child=root->right;
            return child;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node*child=root->left;
            return child;
        }
        else{
            int inorderpre=MaxVal(root->left);
            root->data=inorderpre;
            root->left=deleteNodeInBST(root->left,inorderpre);
            return root;
        }
    }
    else if(target>root->data){
        root->right=deleteNodeInBST(root->right,target);
    }
    else if(target<root->data){
        root->left=deleteNodeInBST(root->left,target);
    }
    return root;
}

int main(){
    Node*root=NULL;
    cout<<"enter the data for Node"<<endl;
    takeInput(root);
    cout<<"printing the tree"<<endl;
    LevelOrderTraversal(root);
    cout<<endl;

    root=deleteNodeInBST(root,100);
     LevelOrderTraversal(root);

     return 0;


}
