#include <iostream>
#include <algorithm> // For std::max
#include <cstring>   // For memset
using namespace std;

// Node structure for the tree
struct tree {
    int data;     // Data value
    tree* left;   // Pointer to left child
    tree* right;  // Pointer to right child
};

// BST class
class BST {
public:
    tree *root, *loc, *par;

    BST() {
        root = NULL; // Initialize root to NULL
    }

    void createbst(int);                // Insert a node into the BST
    void inorder(tree*);                // Inorder traversal
    void preorder(tree*);               // Preorder traversal
    void postorder(tree*);              // Postorder traversal
    void deletenode(int);               // Delete a node from the BST
    void casea(tree*, tree*);           // Deletion case A: Node with 0 or 1 child
    void caseb();                       // Deletion case B: Node with 2 children
    void search(int);                   // Search for a node in the BST
    int depth(tree*);                   // Find the depth of the tree
    void printLeafNodes(tree*);         // Print all leaf nodes
    void mirror_tree(tree*);            // Convert tree to its mirror
};

// Function to insert a node into the BST
void BST::createbst(int x) {
    tree *newnode, *ptr, *parent;
    newnode = new tree;
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) { // If the tree is empty
        root = newnode;
    } else {
        ptr = root;
        while (ptr != NULL) {
            parent = ptr;
            if (x > ptr->data) {
                ptr = ptr->right; // Move to the right subtree
            } else {
                ptr = ptr->left; // Move to the left subtree
            }
        }
        if (x > parent->data) {
            parent->right = newnode; // Insert as the right child
        } else {
            parent->left = newnode; // Insert as the left child
        }
    }
}

// Deletion case A: Node with 0 or 1 child
void BST::casea(tree* loc, tree* par) {
    tree* child;
    if (loc->left == NULL && loc->right == NULL) {
        child = NULL; // No children
    } else if (loc->left != NULL) {
        child = loc->left; // Left child exists
    } else {
        child = loc->right; // Right child exists
    }

    if (par != NULL) { // If loc is not the root
        if (loc == par->left) {
            par->left = child; // Update parent's left pointer
        } else {
            par->right = child; // Update parent's right pointer
        }
    } else {
        root = child; // If loc is the root
    }
}

// Deletion case B: Node with 2 children
void BST::caseb() {
    tree *suc, *parsuc, *ptr, *save;
    ptr = loc->right;
    save = loc;

    // Find in-order successor (leftmost node in the right subtree)
    while (ptr->left != NULL) {
        save = ptr;
        ptr = ptr->left;
    }

    suc = ptr;
    parsuc = save;

    // Handle the successor
    casea(suc, parsuc);

    if (par != NULL) {
        if (loc == par->left) {
            par->left = suc;
        } else {
            par->right = suc;
        }
    } else {
        root = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}

// Function to delete a node
void BST::deletenode(int x) {
    loc = root;
    par = NULL;

    // Search for the node to delete
    while (loc != NULL && x != loc->data) {
        par = loc;
        if (x < loc->data) {
            loc = loc->left; // Move to the left subtree
        } else {
            loc = loc->right; // Move to the right subtree
        }
    }

    if (loc == NULL) { // Node not found
        cout << "\n" << x << " not found.\n";
        return;
    }

    if (loc->left != NULL && loc->right != NULL) {
        caseb(); // Node has two children
    } else {
        casea(loc, par); // Node has 0 or 1 child
    }

    delete loc; // Free the memory of the deleted node
}

// Function to search for a node
void BST::search(int x) {
    tree* ptr = root; // Declare ptr as a local variable and initialize it with root
    if (root == NULL) {
        cout << "\nTree is empty\n";
        return;
    }

    while (ptr != NULL) {
        if (ptr->data == x) {
            cout << x << " is found.\n";
            return;
        } else if (x < ptr->data) {
            ptr = ptr->left; // Move to the left subtree
        } else {
            ptr = ptr->right; // Move to the right subtree
        }
    }

    cout << x << " is not found.\n"; // If the loop ends without finding the node
}

// Function to calculate the depth of the tree
int BST::depth(tree* ptr) {
    if (ptr == NULL) {
        return 0;
    }

    int lh = depth(ptr->left);
    int rh = depth(ptr->right);
    return (max(lh, rh) + 1);
}

// Inorder traversal
void BST::inorder(tree* ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

// Preorder traversal
void BST::preorder(tree* ptr) {
    if (ptr != NULL) {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// Postorder traversal
void BST::postorder(tree* ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

// Print all leaf nodes
void BST::printLeafNodes(tree* ptr) {
    if (ptr == NULL) {
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL) {
        cout << ptr->data << " ";
        return;
    }
    if (ptr->left) {
        printLeafNodes(ptr->left);
    }
    if (ptr->right) {
        printLeafNodes(ptr->right);
    }
}

// Convert tree to its mirror
void BST::mirror_tree(tree* ptr) {
    if (ptr != NULL) {
        tree* temp;
        temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;

        mirror_tree(ptr->left);
        mirror_tree(ptr->right);
    }
}

int main() {
    int ch, x;
    BST t;

    do {
        cout << "\n1. Insertion into Binary Search Tree";
        cout << "\n2. Traversals";
        cout << "\n3. Deletion from Binary Search Tree";
        cout << "\n4. Search";
        cout << "\n5. Depth of the tree";
        cout << "\n6. Print Leaf Nodes";
        cout << "\n7. Mirror the tree";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter data to insert: ";
                cin >> x;
                t.createbst(x);
                break;
            case 2:
                cout << "\nInorder: ";
                t.inorder(t.root);
                cout << "\nPreorder: ";
                t.preorder(t.root);
                cout << "\nPostorder: ";
                t.postorder(t.root);
                break;
            case 3:
                cout << "\nEnter data to delete: ";
                cin >> x;
                t.deletenode(x);
                break;
            case 4:
                cout << "\nEnter data to search: ";
                cin >> x;
                t.search(x);
                break;
            case 5:
                x = t.depth(t.root);
                cout << "\nDepth of the tree: " << x;
                break;
            case 6:
                cout << "\nLeaf Nodes: ";
                t.printLeafNodes(t.root);
                break;
            case 7:
                t.mirror_tree(t.root);
                cout << "\nInorder display of the mirrored tree: ";
                t.inorder(t.root);
                break;
        }
    } while (ch != 8);

    return 0;
}
