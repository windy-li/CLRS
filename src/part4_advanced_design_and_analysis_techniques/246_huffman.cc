#include "clrs.h"

struct Node {
  char key;
  int weight;
  Node* left;
  Node* right;

  Node() : key('-'), weight(0), left(nullptr), right(nullptr) {}

  Node(char key, int weight) : key(key), weight(weight), left(nullptr), right(nullptr) {}

  friend bool operator<(const Node& lhs, const Node& rhs) { return lhs.weight < rhs.weight; }

  static std::string ToString(Node* node) {
    if (node == nullptr) {
      return "nullptr";
    }
    std::string str;
    str += "Node{ key: " + std::to_string(node->key) + ", weight: " + std::to_string(node->weight) + " }";
    return str;
  }
};

class Solution {
 public:
  Node* BuildTree(std::vector<char>& keys, std::vector<int>& weights) {
    int n = keys.size();
    std::vector<Node*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
      nodes[i] = new Node(keys[i], weights[i]);
    }
    std::priority_queue<Node*> pq;
    for (Node* node : nodes) {
      pq.push(node);
    }
    for (int i = 0; i < n - 1; ++i) {
      Node* z = new Node();
      Node* x = pq.top();
      pq.pop();
      Node* y = pq.top();
      pq.pop();
      z->left = x;
      z->right = y;
      z->weight = x->weight + y->weight;
      pq.push(z);
    }
    Node* ret = pq.top();
    pq.pop();
    return ret;
  }

  void PrintCode(Node* node, const std::string& str) {
    if (node != nullptr) {
      PrintCode(node->left, str + "0");
      if (node->left == nullptr && node->right == nullptr) {
        std::cout << std::to_string(node->key) << ": " << str;
      }
      PrintCode(node->right, str + "1");
    }
  }
};

void TestHuffman() {
  Solution solution;
  std::vector<char> keys = {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<int> weights = {45, 13, 12, 16, 9, 5};
  Node* root = solution.BuildTree(keys, weights);
  std::cout << Node::ToString(root) << std::endl;
  solution.PrintCode(root, "");
}

int main() { TestHuffman(); }
