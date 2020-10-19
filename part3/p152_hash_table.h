#include "clrs.h"

struct Slot {
  int key;
  bool is_deleted;

  Slot(int key, bool deleted) : key(key), is_deleted(deleted) {}
};

class HashTable {
 public:
  explicit HashTable(int capacity)
      : m_(capacity), slots_(std::vector<Slot*>(capacity, new Slot(INT_MIN, false))) {}

  void Insert(int key) {
    int i = 0;
    while (i < m_) {
      int j = H(key, i);
      if (slots_[j]->key == INT_MIN || slots_[j]->is_deleted) {
        slots_[j] = new Slot(key, false);
        return;
      }
      i++;
    }
    throw std::overflow_error("hash table overflow");
  }

  Slot* Search(int key) {
    int i = 0;
    while (i < m_) {
      int j = H(key, i);
      if (slots_[j] == nullptr) {
        return nullptr;
      } else if (slots_[j]->key == key && !slots_[j]->is_deleted) {
        return slots_[j];
      }
      i++;
    }
    return nullptr;
  }

  void Remove(int key) {
    Slot* slot = Search(key);
    if (slot != nullptr) {
      slot->is_deleted = true;
    }
  }

 private:
  int m_;
  std::vector<Slot*> slots_;

  int H(int key, int i) { return (H1(key) + i * H2(key)) % m_; }

  int H1(int key) { return key % m_; }

  int H2(int key) { return 1 + (key % (m_ - 1)); }
};
