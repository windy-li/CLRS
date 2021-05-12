#include "clrs.h"

class Node {
 public:
  char key_;
  int weight_;
  Node* left_;
  Node* right_;

  Node() : key_('-'), weight_(0), left_(nullptr), right_(nullptr) {}

  Node(char key, int weight) : key_(key), weight_(weight), left_(nullptr), right_(nullptr) {}

  bool operator<(const Node& target) const { return weight_ < target.weight_; }

  friend std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "Node{ key: " << node.key_ << ", weight: " << node.weight_ << " }";
    return os;
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
    std::priority_queue<Node*, std::vector<Node*>, std::less<>> pq(nodes.begin(), nodes.end());
    for (int i = 0; i < n - 1; ++i) {
      Node* z = new Node();
      Node* x = pq.top();
      pq.pop();
      Node* y = pq.top();
      pq.pop();
      z->left_ = x;
      z->right_ = y;
      z->weight_ = x->weight_ + y->weight_;
      pq.push(z);
    }
    Node* ret = pq.top();
    pq.pop();
    return ret;
  }

  void PrintCode(Node* node, const std::string& s) {
    if (node != nullptr) {
      PrintCode(node->left_, s + "0");
      if (node->left_ == nullptr && node->right_ == nullptr) {
        std::cout << node->key_ << ": " << s;
      }
      PrintCode(node->right_, s + "1");
    }
  }
};

void TestHuffman() {
  Solution solution;
  std::vector<char> keys = {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<int> weights = {45, 13, 12, 16, 9, 5};
  Node* root = solution.BuildTree(keys, weights);
  std::cout << *root << std::endl;
  solution.PrintCode(root, "");
}

int main() { TestHuffman(); }
