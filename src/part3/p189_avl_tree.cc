#include <iostream>
#include <cstdlib>
#include <algorithm>

class Node {
public:
    int key;
    int height;
    Node *left;
    Node *right;
};

class AVLTree {
public:
    Node *root;

    AVLTree() {
        root = nullptr;
    }

    bool isAVL() {
        return dfsHeight(root) != -1;
    }

    Node *insert(Node *node, int key) {
        if (node == nullptr) {
            return new Node{key};
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        updateHeight(node);
        return balanceInsert(node);
    }

    void insert(int key) {
        root = insert(root, key);
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
                Node *suc = minimum(node->right);
                node->key = suc->key;
                node->right = remove(node->right, suc->key);
            }
        }
        updateHeight(node);
        return balanceDelete(node);
    }

private:
    int dfsHeight(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = dfsHeight(node->left);
        int rightHeight = dfsHeight(node->right);
        if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return std::max(leftHeight, rightHeight) + 1;
    }

    Node *rightRotate(Node *p) {
        Node *l = p->left;
        p->left = l->right;
        l->right = p;
        updateHeight(p);
        updateHeight(l);
        return l;
    }

    Node *leftRotate(Node *p) {
        Node *r = p->right;
        p->right = r->left;
        r->left = p;
        updateHeight(p);
        updateHeight(r);
        return r;
    }

    int getHeight(Node *node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node->height;
        }
    }

    void updateHeight(Node *node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int balanceFactor(Node *node) {
        if (node == nullptr) {
            return 0;
        } else {
            return getHeight(node->left) - getHeight(node->right);
        }
    }

    Node *balanceInsert(Node *node) {
        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balanceFactor(node) == 2 && balanceFactor(node->left) == 1) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balanceFactor(node) == -2 && balanceFactor(node->right) == -1) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balanceFactor(node) == 2 && balanceFactor(node->left) == -1) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor(node) == -2 && balanceFactor(node->right) == 1) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    Node *balanceDelete(Node *node) {
        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balanceFactor(node) == 2 && balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balanceFactor(node) == -2 && balanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balanceFactor(node) == 2 && balanceFactor(node->left) == -1) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor(node) == -2 && balanceFactor(node->right) == 1) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    Node *minimum(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void preOrder(Node *node) {
        if (node != nullptr) {
            std::cout << node->key << " " << std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main() {
    auto *self = new AVLTree();
    int keys[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    for (int key : keys) {
        self->insert(key);
    }
    std::cout << self->isAVL() << std::endl;
    std::cout << self->root << std::endl;
    return 0;
}
