#include <iostream>
#include "../clrs.h"

class Node {
public:
    int key;
    int priority;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        priority = clrs::RandomInt(0, 100);
        left = nullptr;
        right = nullptr;
    }
};

class Treap {
public:
    Node *root;

    Treap() {
        root = nullptr;
    }

    Node *rightRotate(Node *p) {
        Node *l = p->left;
        p->left = l->right;
        l->right = p;
        return l;
    }

    Node *leftRotate(Node *p) {
        Node *r = p->right;
        p->right = r->left;
        r->left = p;
        return r;
    }

    Node *search(int key) {
        return search(root, key);
    }

    Node *search(Node *node, int key) {
        if (node == nullptr || key == node->key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node *insert(Node *node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
            if (node->left->priority < node->priority) {
                node = rightRotate(node);
            }
        } else if (key > node->key) {
            node->right = insert(node->right, key);
            if (node->right->priority < node->priority) {
                node = leftRotate(node);
            }
        }
        return node;
    }

    void remove(int key) {
        root = remove(root, key);
    }

    Node *remove(Node *node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            if (node->left == nullptr) {
                node = node->right;
            } else if (node->right == nullptr) {
                node = node->left;
            } else {
                if (node->left->priority < node->right->priority) {
                    node = rightRotate(node);
                    node->right = remove(node->right, key);
                } else {
                    node = leftRotate(node);
                    node->left = remove(node->left, key);
                }
            }
        }
        return node;
    }

    void inorder(Node *node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node << std::endl;
            inorder(node->right);
        }
    }
};

int main() {
    auto *self = new Treap();
    int keys[] = {5, 3, 2, 4, 7, 6, 1, 8};
    for (int key : keys) {
        self->insert(key);
    }
    self->inorder(self->root);
    std::cout << self->search(3) << std::endl;
    self->remove(3);
    std::cout << self->search(3) << std::endl;
}
