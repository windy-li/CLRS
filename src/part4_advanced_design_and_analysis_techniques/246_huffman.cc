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

  bool operator>(const Node& target) const { return weight_ > target.weight_; }
};

class Solution {
 public:
};
