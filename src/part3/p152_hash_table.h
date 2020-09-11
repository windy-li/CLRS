#include "clrs.h"

struct Slot {
  int key;
  bool deleted;

  Slot(int key, bool deleted) : key(key), deleted(deleted) {}
};

class HashTable {
 public:
  int m;
  std::vector<Slot*> slots;

  HashTable(int capacity)
      : m(capacity), slots(std::vector<Slot*>(capacity, new Slot(INT_MIN, false))) {}

  void Insert(int key) {
    int i = 0;
    while (i < m) {
      int j = H(key, i);
      if (slots[j]->key == INT_MIN || slots[j]->deleted) {
        slots[j] = new Slot(key, false);
        return;
      }
      i++;
    }
    throw std::overflow_error("hash table overflow");
  }

  Slot* Search(int key) {
    int i = 0;
    while (i < m) {
      int j = H(key, i);
      if (slots[j] == nullptr) {
        return nullptr;
      } else if (slots[j]->key == key && !slots[j]->deleted) {
        return slots[j];
      }
      i++;
    }
    return nullptr;
  }

  void Remove(int key) {
    Slot* slot = Search(key);
    if (slot != nullptr) {
      slot->deleted = true;
    }
  }

 private:
  int H(int key, int i) { return (H1(key) + i * H2(key)) % m; }

  int H1(int key) { return key % m; }

  int H2(int key) { return 1 + (key % (m - 1)); }
};
