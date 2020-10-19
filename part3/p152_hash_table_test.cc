#include "p152_hash_table.h"

int main() {
  HashTable table(13);
  int keys[] = {79, 69, 98, 72, 14, 50};
  for (int key : keys) {
    table.Insert(key);
  }
  cout << table.Search(98)->key << endl;
  table.Remove(98);
  cout << table.Search(98) << endl;
  table.Insert(98);
  cout << table.Search(98)->key << endl;
}

/*
 * 98
 * 0x0
 * 98
 */
