#include <iostream>
using namespace std;

enum Color{RED, BLACK};

template <class T>
class RBTreeNode {
    Color color;
    T value;
    RBTreeNode *left;
    RBTreeNode *right;
    RBTreeNode *parent;
    
    RBTreeNode(Color c, T v, RBTreeNode *l, RBTreeNode *r, RBTreeNode *p):
        color(c), value(v), left(l), right(r), parent() {}
};

template <class T>
class RBTree {
    private:
        RBTreeNode<T> root;
    
    public:
        void rotateLeft(RBTreeNode<T> * &root, RBTreeNode<T> * node);
        void rotateRight(RBTreeNode<T> * &root, RBTreeNode<T> * node);
};

template <class T>
void RBTree<T>::rotateLeft(RBTreeNode<T> * &root, RBTreeNode<T> * node) {
    RBTreeNode<T> * parentNode = node->parent;
    RBTreeNode<T> * rightNode = node->right;
    
    if(parentNode == NULL) {
        root = rightNode;
    } else {
        rightNode->parent = parentNode;
        if(node == parentNode->left){
            parentNode->left = rightNode;
        } else {
            parentNode->right = rightNode;
        }
    }
    
    if(rightNode->left != NULL) {
        node->right = rightNode->left;
        rightNode->left->parent = node;
    }
    
    rightNode->left = node;
    node->parent = rightNode;
}

template <class T>
void RBTree<T>::rotateRight(RBTreeNode<T> * &root, RBTreeNode<T> * node) {
    RBTreeNode<T> * parentNode = node->parent;
    RBTreeNode<T> * leftNode = node->left;
    
    if (parentNode == NULL) {
        root = leftNode;
    } else {
        leftNode->parent = parentNode;
        if(node == parentNode->left) {
            parentNode->left = leftNode;
        } else {
            parentNode->right = leftNode;
        }
    }
    
    if (leftNode->right != NULL) {
        node->left = leftNode->right;
        leftNode->right->parent = node;
    }
    
    leftNode->right = node;
    node->parent = leftNode;
}

template <class T>
void RBTree<T>::insert(RBTreeNode * &root, RBTreeNode * node) {
    RBTreeNode * parentNode = NULL;
    RBTreeNode * childNode = root;
    
    while (childNode != NULL) {
        parentNode = childNode;
        if (node->value < childNode->value) {
            childNode = childNode->left;
        } else {
            childNode = childNode->right;
        }
    }
    
    if (parentNode == NULL) {
        node->color = Color.BLACK;
        root = node;
        return;
    } else {
        node->parent = parentNode;
        if (node->value < parentNode->value) {
            parentNode->left = node;
        } else {
            parentNode->right = node;
        }
    }
    
    
}

template <class T>
void RBTree::fixInsert(RBTreeNode * &root, RBTreeNode * node) {
    while(node->parent != NULL && node->parent->color == Color->RED) {
        
    }
    
    
}


int main() {
	// your code goes here
	cout<< "test";
	return 0;
}
