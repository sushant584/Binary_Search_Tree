#include<iostream>
#include<queue>
#include<limits.h>
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

class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){

    }
    NodeData(int size,int max,int min,bool valid){
        this->size=size;
        minVal=min;
        maxVal=max;
        validBST=valid;
    }
};

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

NodeData* findLargestBST(Node*root,int &ans){
    if(root==NULL){
    NodeData*temp=new NodeData(0,INT_MIN,INT_MAX,true);
    return temp;
    }
    NodeData*leftKaAns=findLargestBST(root->left,ans);
NodeData*rightKaAns=findLargestBST(root->right,ans);

NodeData*currNodeKaAns=new NodeData();

currNodeKaAns->size=leftKaAns->size+rightKaAns->size + 1;

currNodeKaAns->maxVal=max(root->data,rightKaAns->maxVal);
currNodeKaAns->minVal=min(root->data,leftKaAns->minVal);

if(leftKaAns->validBST && rightKaAns->validBST && (root->data>leftKaAns->maxVal && root->data<rightKaAns->minVal)){
    currNodeKaAns->validBST=true;
}
else{
    currNodeKaAns->validBST=false;
}
if(currNodeKaAns->validBST){
    ans=max(ans,currNodeKaAns->size);
}
return currNodeKaAns;

}
int main(){

    Node*root=new Node(50);
    Node*first=new Node(30);
    Node*second=new Node(60);
    Node*third=new Node(5);
    Node*fourth=new Node(20);
    Node*fifth=new Node(45);
    Node*sixth=new Node(70);
    Node*seventh=new Node(65);
    Node*eight=new Node(80);

    root->left=first;
    root->right=second;
    first->left=third;
    first->right=fourth;
    second->left=fifth;
    second->right=sixth;
    sixth->left=seventh;
    sixth->right=eight;

    cout<<"printing the tree"<<endl;
    LevelOrderTraversal(root);

    int ans=0;
    findLargestBST(root,ans);
    cout<<"largest bsk ka size :"<<ans<<endl;
    return 0;

}

