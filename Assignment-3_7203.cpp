#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
};

class Tree{
    public:
    Node* add_edge();
    void preorder(Node* root){
    if(root == 0){
        return;
    }
    cout<<root->value<<" -} ";
    preorder(root->left);
    preorder(root->right);
}
// preorder iterative
// void preorderIterative(Node* root)
// {
//     if (root == NULL)
//         return;
 
//     stack<Node*> st;
//     Node* curr = root;
 

//     while (!st.empty() || curr != NULL) {

//         while (curr != NULL) {
//             cout << curr->data << " ";
 
//             if (curr->right)
//                 st.push(curr->right);
 
//             curr = curr->left;
//         }

//         if (st.empty() == false) {
//             curr = st.top();
//             st.pop();
//         }
//     }
// }
Node* newNode(char data)
{
    Node* node = new Node();
    node->value = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void inorder(Node* root){
    if(root == 0){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" -} ";
    inorder(root->right);
}
// iterative solution
// void inOrder(Node *root)
// {
//     stack<Node *> s;
//     Node *curr = root;
 
//     while (curr != NULL || s.empty() == false)
//     {
//         while (curr !=  NULL)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }
//         curr = s.top();
//         s.pop();
//         cout << curr->data << " ";
//         curr = curr->right;
 
//     } 
// }

void postorder(Node* root){
    if(root == 0){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" -} ";
}

// iterative postorder
// void postOrderIterative(Node* root)
// {
//     if (root == NULL)
//         return;
//     stack<Node *> s1, s2;

//     s1.push(root);
//     Node* node;

//     while (!s1.empty()) {
//         // Pop an item from s1 and push it to s2
//         node = s1.top();
//         s1.pop();
//         s2.push(node);
//         if (node->left)
//             s1.push(node->left);
//         if (node->right)
//             s1.push(node->right);
//     }

//     while (!s2.empty()) {
//         node = s2.top();
//         s2.pop();
//         cout << node->data << " ";
//     }
// }
int height(Node* root){
       if(root ==0){
           return 0;
       }
       return max(height(root->left),height(root->right))+1;
   }
void linear_order(Node *root){
    if(root == 0) return;
    Node* curr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        cout<<curr->value<<" -} ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
} 
void deleteTree(Node* node)
{
    if (node == 0) return;
 
    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
     
    /* then delete the node */
    cout << "\n Deleting node: " << node->value;
    delete node;
}

void deletDeepest(Node* root,Node* d_node)
{
    queue<struct Node*> q;
    q.push(root);
 
    // Do level order traversal until last node
    struct Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

Node* delete_node(Node* root,int key){
    if(root==0){
        return 0;
    }
    if((root->left == 0) && (root->right == 0)){
        if(root->value == key){
            return 0;
        }
        else{
        return root;
        }
    }
    queue<Node*> qu;
    qu.push(root);
    Node* key_node = 0;
    Node* temp;
    while(!qu.empty()){
        temp = qu.front();
        qu.pop();
        if(temp->value == key){
           key_node = temp; 
        }
        if(temp->left){
            qu.push(temp->left);
        }
        if(temp->right){
            qu.push(temp->right);
        }
    }
        if(key_node !=0){
            int x = temp->value;
            deletDeepest(root,temp);
            key_node->value = x;
    }
    return root;
}
    int preIndex = 0;
    Node* create_tree(int in[],int pre[],int is,int ie){
        if(is>ie){
            return 0;
        }
        Node* root = newNode(pre[preIndex++]);
        int Inindex;
        for(int i=is;i<=ie;i++){
            if(in[i] == root->value){
                Inindex = i;
                break;
            }
        }
        root->left = create_tree(in,pre,is,Inindex-1);
        root->right = create_tree(in,pre,Inindex+1,ie);
        return root;
    }
    
    bool identical_trees(Node* a,Node* b){
        if(a == 0 && b == 0){
            return true;
        }
        if((a!=0) && (b!=0)){
            return(
        (a->value == b->value) && (identical_trees(a->left,b->left)) && (identical_trees(a->right,b->right))
        );
    }
    }
    Node* cloneBinaryTree(Node* root)
{
    // base case
    if (root == 0) {
        return 0;
    }
 
    // create a new node with the same data as the root node
    Node* root_copy = new Node;
    root_copy->value = root->value;
    root_copy->left = 0;
    root_copy->right = 0;
 
    // clone the left and right subtree
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);
 
    // return cloned root node
    return root_copy;
}
unsigned int countnodes(Node* root)
{
    if (root == NULL)
       return 0;
  
    int res = 0;
    if  (root->left && root->right)
       res++;
  
    res += (countnodes(root->left) + countnodes(root->right));
    return res;
}
};

Node* Tree::add_edge(){
    int x;
    Node* newnode = new Node;
    cout<<"Enter the value to enter or -1 to exit\n";
    cin>>x;
    if(x==-1){
        return 0;
    }
    newnode->value = x;
    cout<<"Enter the value for left child of "<<newnode->value<<"\n";
    newnode->left = add_edge();
    cout<<"Enter the value for right child of "<<newnode->value<<"\n";
    newnode->right = add_edge();
    return newnode;
}



int main(){
    Tree t;
    Node* root;
    bool flag = true;
    // t.inorder(root);
    while(flag){
    cout<<"-----------MENU-----------\n";
    cout<<"1.Add edge in the tree\n";
    cout<<"2.All traversals on tree\n";
    cout<<"3.Find the height of a tree\n";
    cout<<"4.Create clone of a tree and then erase all nodes in a original tree.\n";
    cout<<"5.Construct a binary tree from inorder and perorder traversal.\n";
    cout<<"6.Delete a node from binary tree.\n";
    cout<<"7.Check whether two trees are equal.\n";
    cout<<"8.Count the toatal number of node in tree\n";
    cout<<"9.Exit\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
            root = t.add_edge();
            break;
        }
        case 2:{
            cout<<"The inorder traversal of given tree is\n";
            t.inorder(root);
            cout<<"\n======================================\n";
            cout<<"The preorder traversal of given tree is\n";
            t.preorder(root);
            cout<<"\n======================================\n";
            cout<<"The postorder traversal of given tree is\n";
            t.postorder(root);
            cout<<"\n";
            cout<<"\n======================================\n";
            cout<<"The level order traversal of given tree is\n";
            t.linear_order(root);
            cout<<"\n";
            break;
        }
        case 3:{
            cout<<"The height of the given tree is\n";
            cout<<t.height(root)<<"\n";
            break;
        }
        case 4:{
            Node* cl;
            cl = t.cloneBinaryTree(root);
            cout<<"The tree is succesfully cloned\n";
            t.deleteTree(root);
            cout<<"\n";
            break;
        }
        case 5:{
            cout<<"Enter the total number of node in the tree\n";
            int n;
            cin>>n;
            int in[n];
            int pre[n];
            cout<<"Enter the inorder of tree\n";
            for(int i=0;i<n;i++){
                cin>>in[i];
            }
            cout<<"Enter the preorder of tree\n";
            for(int i=0;i<n;i++){
                cin>>pre[i];
            }
            Node *temp=t.create_tree(in,pre,0,n-1);
            cout<<"The create is successfully created\n";
            cout<<"The inorder traversal of given tree is\n";
            t.inorder(temp);
            cout<<"\n======================================\n";
            cout<<"The preorder traversal of given tree is\n";
            t.preorder(temp);
            cout<<"\n======================================\n";
            cout<<"The postorder traversal of given tree is\n";
            t.postorder(temp);
            cout<<"\n";
            break;
        }
        case 6:{
            cout<<"Enter the key to be deletd\n";
            int key;
            cin>>key;
            root = t.delete_node(root,key);
            cout<<"The tree after deletion of node is\n";
            t.inorder(root);
            cout<<"\n";
            break;
        }
        case 7:{
            Node* check =new Node;
            cout<<"let Create the second binary tree\n";
            check = t.add_edge();
            if(t.identical_trees(root,check)){
                cout<<"The two tree are equall\n";
            }
            else{
                cout<<"The two tree are not equall\n";
            }
            cout<<"\n";
            break;
        }
        case 8:{
            cout<<"The total number of full node in the tree are : "<<t.countnodes(root)<<"\n";
            break;
        }
        case 9:{
            flag = false;
            cout<<"Thank you\n";
            break;
        }
        default:{
            cout<<"Enter the correct value\n";
            break;
        }
    }
    }
    return 0;
}

