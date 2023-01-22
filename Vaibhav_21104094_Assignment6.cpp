
/*                           Vaibhav
                             21104094
                             Assignment 6
                             Comparing Binary Search and Binary Search Tree (BST)
*/

#include <bits/stdc++.h>                                      
using namespace std;

//Creating node of a tree
class BinaryTreeNode{
    public:
        int data;
        BinaryTreeNode*left;
        BinaryTreeNode*right;

    BinaryTreeNode(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }   
};

//Function to insert data in a Binary Search Tree
BinaryTreeNode* insertInBST(BinaryTreeNode*root, int data){
    if(root == NULL){
        BinaryTreeNode* new_node = new BinaryTreeNode(data);
        root=new_node;
        return root;
    }

    if(data > root -> data){
        root -> right = insertInBST(root->right,data);
    }

    else if(data < root->data){
        root -> left = insertInBST(root->left,data);
    }

    else{
        return root;
    }

    return root;
}

//Function to print a tree using Level Order Traversal
void levelOrderTraversal(BinaryTreeNode* root){
    
    queue <BinaryTreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BinaryTreeNode* temp=q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){q.push(NULL);};
        }

        else{
            cout << temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//Function to get min value node in a Binary Search Tree
BinaryTreeNode* min_value_node(BinaryTreeNode* node){
    BinaryTreeNode* current = node;

    while (current && current->left != NULL){
        current = current -> left;   
    }
    return current;
}

//Function to delete a node in Binary Search Tree
BinaryTreeNode* deleteNode(BinaryTreeNode* root, int key)
{
    if(root == NULL){
        return root;
    }
  
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else{
        if(root->left==NULL and root->right==NULL){
            return NULL;
        }
        
        else if(root -> left == NULL){
            BinaryTreeNode* temp = root -> right;
            free(root);
            return temp;
        }

        else if(root -> right == NULL){
             BinaryTreeNode* temp = root -> left;
            free(root);
            return temp;
        }
 
        BinaryTreeNode* temp = min_value_node(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root->right, temp->data);
    }
    return root;
}

//Function to print an array
void printArr(int arr[],int n){
    for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
    }
}

int main(){
    //Taking number of element in array as input
    int n;
    cout << "\nEnter number elements in the ARRAY to form BST:";
    cin >> n;

    int arr[n];
    cout << "\nEnter elements of the array to form BST:";

    //Taking elements of array as input
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //printing the array
    cout << "\nArray:[";
    printArr(arr,n);
    cout << "]";
    cout << endl;

    //root is the top most node of Binary Search Tree
    BinaryTreeNode* root = NULL;

    //Inserting element of the array in Binary Search Tree
    for(int i =0 ;i < n; i++){
        root=insertInBST(root,arr[i]);
    }

    //Displaying Binary Search Tree using Level Order Traversal
    cout << "\nBinary Search Tree using Level Order Traversal\n" << endl;
    levelOrderTraversal(root);

    //key is the data to be deleted from Binary Search Tree
    int key;
    cout << "\nEnter data to be deleted from BST:";
    cin >> key;

    //deleting key from Binary Search Tree
    root = deleteNode(root,key);

    //Displaying Binary Search Tree after deletion of key
    cout << "\nBinary Search Tree after deleting:" << key << endl;
    cout<<endl;
    levelOrderTraversal(root);
}



/*
If an array has n elements and all elements are inserted in binary
search tree than the tree has space complexity of O(n) and the array
has also the space complexity of O(n)
*/





