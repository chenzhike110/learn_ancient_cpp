#ifndef LINKED_TREE
#define LINKED_TREE

#include "binaryTree.hpp"

template<class T>
struct binaryTreeNode
{
    T _element;
    binaryTreeNode* left_node;
    binaryTreeNode* right_node;

    binaryTreeNode() {
        left_node = right_node = NULL;
    }

    binaryTreeNode(const T& Element) {
        _element = Element;
        left_node = right_node = NULL;
    }

    binaryTreeNode(const T& Element, binaryTreeNode* left_node, binaryTreeNode* right_node) {
        this->left_node = left_node;
        this->right_node = right_node;
        this->_element = _element;
    }
};

template<class T>
void visit(binaryTreeNode<T>* node) {
    cout << node->_element << ' ';
}

template<class T>
void preOrder(binaryTreeNode<T>* father) {
    if (father != nullptr) {
        visit(father);
        preOrder(father->left_node);
        preOrder(father->right_node);
    }
}

template <class T>
void inOrder(binaryTreeNode<T>* father) {
    if (father != NULL) {
        visit(father->left_node);
        visit(father);
        visit(father->right_node);
    }
}

template<class T>
void postOrder(binaryTreeNode<T>* father) {
    if (father != NULL) {
        visit(father->left_node);
        visit(father->right_node);
        visit(father);
    }
}

template<class T>
class linkedBinaryTree : public binaryTree<binaryTreeNode<T>> {
    public:
        linkedBinaryTree() { _root = NULL; _size = 0; }
        ~linkedBinaryTree() { erase(); }
        bool empty const { return _size == 0; }
        int size() const { return _size; }
        void preOrder(void(*theVisit)(binaryTreeNode<T>*)) {
            
        }

    private:
        binaryTreeNode<T>* _root;
        int _size;
        static void (*visit)(binaryTreeNode<T>*);
        static void preOrder(binaryTreeNode<T>*);
        static void inOrder(binaryTreeNode<T>*);
        static void postOrder(binaryTreeNode<T>*);
        static void dispose(binaryTreeNode<T>*t) {delete t;}
};

#endif