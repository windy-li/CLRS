#include "clrs.h"

struct Node {
  int key;
  vector<shared_ptr<Node>> forward;

  Node(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
public:
  typedef shared_ptr<Node> NodeType;

  SkipList(int max_level, double p) :
      max_level_(max_level),
      p_(p),
      current_level_(0),
      head_(make_shared<Node>(-1, max_level)) {}

  void Insert(int key) {
    NodeType current = head_;

    // Create update array and initialize it
    vector<NodeType> update(max_level_ + 1, nullptr);

    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current.
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = current_level_; i >= 0; --i) {
      while (current->forward[i] != nullptr && current->forward[i]->key < key) {
        current = current->forward[i];
      }
      update[i] = current;
    }

    // Reached level 0 and forward pointer to right, which is desired position to insert key
    current = current->forward[0];

    // If current is null that means we have reached to end of the level
    // or current's key is not equal to key to insert that means
    // we have to insert node between update[0] and current node
    if (current == nullptr || current->key != key) {
      // Generate a random level for node
      int r = RandomLevel();

      // If random level is greater than list's current level
      // (node with highest level inserted in list so far),
      // initialize update value with pointer to head for further use
      if (r > current_level_) {
        for (int i = current_level_ + 1; i <= r; ++i) {
          update[i] = head_;
        }
        // Update the list current level
        current_level_ = r;
      }

      // Create new node with random level generated
      shared_ptr<Node> node = make_shared<Node>(key, r);

      // Insert node by rearranging pointers
      for (int i = 0; i <= r; i++) {
        node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = node;
      }
    }
  }

  shared_ptr<Node> Search(int key) {
    shared_ptr<Node> current = head_;
    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current.
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = current_level_; i >= 0; --i) {
      while (current->forward[i] != nullptr && current->forward[i]->key < key) {
        current = current->forward[i];
      }
    }

    // Reached level 0 and advance pointer to right, which is possibly our desired node
    current = current->forward[0];

    // If current node have key equal to search key, we have found our target node
    if (current != nullptr && current->key == key) {
      return current;
    }
    return nullptr;
  }

  void Remove(int key) {
    shared_ptr<Node> current = head_;

    // Create update array and initialize it
    vector<shared_ptr<Node>> update(max_level_ + 1, nullptr);

    // Start from highest level of skip list, move the current pointer forward
    // while key is greater than key of node next to current
    // Otherwise inserted current in update and move one level down and continue search
    for (int i = current_level_; i >= 0; --i) {
      while (current->forward[i] != nullptr && current->forward[i]->key < key) {
        current = current->forward[i];
      }
      update[i] = current;
    }

    // Reached level 0 and forward pointer to right, which is possibly our desired node
    current = current->forward[0];

    // If current node is target node
    if (current != nullptr && current->key == key) {
      // Start from lowest level and rearrange pointers just like we do in singly linked list
      // to remove target node
      for (int i = 0; i <= current_level_; ++i) {
        // If at level i, next node is not target node,
        // break the loop, no need to move further level
        if (update[i]->forward[i] != current) {
          break;
        }
        update[i]->forward[i] = current->forward[i];
      }

      // Remove levels having no elements
      while (current_level_ > 0 && head_->forward[current_level_] == nullptr) {
        current_level_--;
      }
    }
  }

private:
  shared_ptr<Node> head_;
  int max_level_;
  double p_;
  int current_level_;

  int RandomLevel() {
    int tmp = 0;
    while (clrs::Random() < p_ && tmp < max_level_) {
      tmp++;
    }
    return tmp;
  }
};
