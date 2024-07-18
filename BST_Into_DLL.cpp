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

Node* bstUsingInorder(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    int element=inorder[mid];
    Node*root=new Node(element);

    root->left=bstUsingInorder(inorder,s,mid-1);
    root->right=bstUsingInorder(inorder,mid+1,e);
    return root;
}

void ConvertIntoSortedDLL(Node*root,Node*&head){
    if(root==NULL){
        return ;
    }
    ConvertIntoSortedDLL(root->right,head);
    root->right=head;

    if(head!=NULL)
        head->left=root;

    head=root;
}

void printLinkedList(Node*head){
    Node*temp=head;
    cout<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;

    }
    cout<<endl;
}

int main(){
    int inorder[]={1,2,3,4,5,6,7,8,9};
    int s=0;
    int e=8;
    Node*root=bstUsingInorder(inorder,s,e);
    LevelOrderTraversal(root);

    cout<<"printing the sorted linked list"<<endl;
    Node*head=NULL;
    ConvertIntoSortedDLL(root,head);
    return 0;
}

