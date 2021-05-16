#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_

#include "clrs.h"

struct Vertex {
  bool visited;
  int d;
  Vertex* pre;
  int id;
  int f;
  std::string label;
  int key;

  explicit Vertex(int id) : id(id) {}

  Vertex(int id, std::string& label) : id(id), label(std::string(label)) {}

  friend bool operator<(const Vertex& lhs, const Vertex& rhs) { return lhs.key < rhs.key; }

  static std::string ToString(Vertex* vertex) {
    if (vertex == nullptr) {
      return "nullptr";
    }
    return std::to_string(vertex->id);
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_VERTEX_H_
