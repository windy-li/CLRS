#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_

#include "clrs.h"

struct Vertex {
  bool visited;
  int d;
  Vertex* pre;
  int id;
  int f;

  explicit Vertex(int id) : id(id) {}

  friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
    os << vertex.id;
    return os;
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_
