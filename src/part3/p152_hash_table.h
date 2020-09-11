#include "clrs.h"

struct Slot {
  int key;
  bool deleted;

  Slot(int key, bool deleted) : key(key), deleted(deleted) {}
};

class HashTable {
 public:
  int m;
  vector<Slot *> slots;

  HashTable(int capacity) : m(capacity), slots(vector<Slot *>(capacity, nullptr)) {
    for (int i = 0; i < capacity; i++) {
      slots[i] = new Slot(INT_MIN, false);
    }
  }

  void Insert(int key) {
    int i = 0;
    while (i < m) {
      int j = h(key, i);
      if (slots[j]->key == INT_MIN || slots[j]->deleted) {
        slots[j] = new Slot(key, false);
        return;
      }
      i++;
    }
    throw std::overflow_error("Hash table overflow");
  }

  Slot *Search(int key) {
    int i = 0;
    while (i < m) {
      int j = h(key, i);
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
    Slot *slot = Search(key);
    if (slot != nullptr) {
      slot->deleted = true;
    }
  }

 private:
  int h(int key, int i) { return (h1(key) + i * h2(key)) % m; }

  int h1(int key) { return key % m; }

  int h2(int key) { return 1 + (key % (m - 1)); }
};
