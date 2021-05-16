#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_

#include "clrs.h"

struct Edge {
  int start_id;
  int end_id;

  Edge(int start_id, int end_id) : start_id(start_id), end_id(end_id) {}

  int Other(int vertex_id) {
    if (vertex_id == start_id) {
      return end_id;
    } else if (vertex_id == end_id) {
      return start_id;
    } else {
      throw std::invalid_argument("no such vertex in this edge");
    }
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_EDGE_H_
