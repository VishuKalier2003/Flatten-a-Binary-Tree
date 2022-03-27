/* Flattening a Tree in a Linked List form without using any Data Structure and without Copying the tree as a whole */
#include <iostream>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        if(root == NULL)   // If Tree is empty nothing to show
            return;            // Control moves out of the function
        Node* temp = root;
        ShowTree(root -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(root -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(root -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(root -> right);     // Recursive Call
    }
    public:
    void FlattenTheTree(Node* root)  // Flatten the Tree into Linear Data Structure
    {
        if(root == NULL || root -> left == NULL && root -> right == NULL) // If end of a branch is Traversed
            return;                // Backtrack the control
        if(root -> left != NULL)        // If the Left Subtree exists
        {
            FlattenTheTree(root -> left);  // Recursive Call to the Left Subtree
            Node* temp = root -> right;      // Temporary pointer to store the Right subtree reference
            root -> right = root -> left;     // Putting the Left Subtree in the place of the Right Subtree
            root -> left = NULL;            // Set the Leftmost node to Null
            Node* count = root -> right;     // Store the pointer reference for the Left subtree which is currently
            while(count -> right != NULL)    // in the place of the Right Subtree
            {
                count = count -> right;         // Incrementing while reaching the end of the Left Subtree in the place
            }                                   // of Right Subtree
            count -> right = temp;       
        }
        FlattenTheTree(root -> right);           // Recursive Call for the Right Subtree
    }
    void InOrderTraversal(Node* root)    // Function for Printing the Nodes in In-Order Traversal
    {
        if(root == NULL)            // Left Subtree -> Root Node -> Right Subtree
            return;
        if(root -> left)
            InOrderTraversal(root -> left);   // Recursive call for the Left Subtree
        cout << root -> data << ", ";
        if(root -> right)
            InOrderTraversal(root -> right);   // Recursive Call for the Right Subtree
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);    // Displaying binary tree with Nodes
    cout << "The Binary Tree after Flattening is : " << endl;
    binarytree.FlattenTheTree(root);      // Callling the function
    binarytree.InOrderTraversal(root);
    return 0;
}