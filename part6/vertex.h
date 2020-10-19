#include "clrs.h"

struct Vertex {
  int id;
  bool visited;
  int d;
  Vertex *pre;

  explicit Vertex(int id) :
      id(id),
      visited(false),
      d(-1),
      pre(nullptr) {}
};
