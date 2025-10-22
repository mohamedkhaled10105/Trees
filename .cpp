#include <iostream> 
using namespace std; 

class Node{ 
public: 
int data; 
Node* left; 
Node* right; 

Node(int value){ 
data = value; 
left = right = nullptr; 
}

}; 

class Tree{ 
public: 
Node* root; 

tree(){ 
root = nullptr
}

Node* insert(Node* node, int value){ 
if(node == nullptr){ 
return new Node (value); 
} 
if(value < node->data){ 
node->left = insert(node->left,value)
}else{ 
node->right = insert(node->right,value);
}
return node; 

}  

void inorderTraversal(Node* node){ 
if (node != nullptr){ 
inorderTraversal(node->left); 
cout<<node->data<<" "; 
inorderTraversal(node->right); 
} 
} 

void preorderTraversal(Node* node){
if(node!=nullptr){ 
cout<<node->data<<" "; 
preorderTraversal(node->left)
preorderTraversal(node->right)

void postorderTraversal(Node* node){
if(node!=nullptr){ 
 postorderTraversal(node->left)
postorderTraversal(node->right)
cout<<node->data<<" ";  




#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    } 

    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    Node* deletenode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->value) {
            root->left = deletenode(root->left, value);
        } else if (value > root->value) {
            root->right = deletenode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            }

            // Node with two children
            Node* tmp = findMin(root->right);
            root->value = tmp->value;
            root->right = deletenode(root->right, tmp->value);
        }
        return root;
    }

    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->value << " ";
        }
    }
};

int main() {
    Tree tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preOrderTraversal(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal(tree.root);
    cout << endl;

    // Search for a node
    int searchValue = 40;
    cout << "Searching for " << searchValue << ": ";
    if (tree.search(tree.root, searchValue)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    // Find minimum and maximum node
    Node* minNode = tree.findMin(tree.root);
    Node* maxNode = tree.findMax(tree.root);
    cout << "Minimum value in the tree: " << minNode->value << endl;
    cout << "Maximum value in the tree: " << maxNode->value << endl;

    // Delete a node
    tree.root = tree.deletenode(tree.root, 40);
    cout << "After deleting 40, In-order traversal: ";
    tree.inOrderTraversal(tree.root);
    cout << endl;

    return 0;
}
