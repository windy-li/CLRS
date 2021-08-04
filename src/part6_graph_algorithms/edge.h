#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_

#include "clrs.h"

struct Edge {
  int start_id;
  int end_id;
  int weight;

  Edge(int start_id, int end_id) : start_id(start_id), end_id(end_id) {}

  Edge(int start_id, int end_id, int weight) : start_id(start_id), end_id(end_id), weight(weight) {}

  [[nodiscard]] int Either() const { return start_id; }

  [[nodiscard]] int Other(int vertex_id) const {
    if (vertex_id == start_id) {
      return end_id;
    } else if (vertex_id == end_id) {
      return start_id;
    } else {
      throw std::invalid_argument("no such vertex in this edge");
    }
  }

  friend bool operator<(const Edge& lhs, const Edge& rhs) { return lhs.weight < rhs.weight; }

  static std::string ToString(const Edge* edge) {
    if (edge == nullptr) {
      return "nullptr";
    }
    std::string str;
    return str + std::to_string(edge->start_id) + ", " + std::to_string(edge->end_id) + ", " +
           std::to_string(edge->weight);
  }

  friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
    os << Edge::ToString(const_cast<Edge*>(&edge));
    return os;
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_
