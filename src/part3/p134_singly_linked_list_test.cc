#include "p134_singly_linked_list.h"

int main() {
    LinkedList list;
    list.PushFront(1);
    list.PushFront(4);
    list.PushFront(16);
    list.PushFront(9);
    list.PushFront(25);
    cout << list.Search(1) << endl;
    list.Remove(4);
    cout << list.Search(4) << endl;
}

/*
 * 0x7fd71c400680
 * 0x0
 */
