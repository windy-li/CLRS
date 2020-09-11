#include <iostream>

class Table {
public:
    int num;
    int *slots;
    int size;

    Table() {
        num = 0;
        size = 0;
    }

    Table(int capacity) {
        num = 0;
        slots = new int[capacity];
        this->size = capacity;
    }

    void insert(int key) {
        if (size == 0) {
            slots = new int[1];
            size = 1;
        }
        if (num == size) {
            int *tmp = new int[2 * size];
            for (int i = 0; i < size; i++) {
                tmp[i] = slots[i];
            }
            slots = tmp;
            size *= 2;
        }
        slots[num] = key;
        num++;
    }
};

int main() {
    auto *self = new Table();
    self->insert(8);
    self->insert(3);
    std::cout << self->slots[0] << " " << self->slots[1];
}

/*
 * 8
 * 3
 */
