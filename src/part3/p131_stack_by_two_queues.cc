#include "p131_stack_by_two_queues.h"

int main() {
  Stack self(7);
  self.push(15);
  self.push(6);
  self.push(2);
  self.push(9);
  self.push(17);
  self.push(3);
  cout << self.pop() << endl;
}
