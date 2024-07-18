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

    while(data !=-1){
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

Node* findNodeInBST(Node*root,int target){
    if(root==NULL)
        return NULL;

        if(root->data==target)
        return root;
    if(target>root->data){
        return findNodeInBST(root->right,target);
    }
    else{
        return findNodeInBST(root->left,target);
    }
    
}

int main(){
    Node*root=NULL;
    cout<<"enter the data for Node"<<endl;
    takeInput(root);
    cout<<"printing the tree"<<endl;
    LevelOrderTraversal(root);
    cout<<endl;

    bool ans=findNodeInBST(root,155);
    cout<<"present or not :"<<ans<<endl;

return 0;
}