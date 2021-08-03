#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_

#include "clrs.h"
#include "part6_graph_algorithms/digraph.h"
#include "part6_graph_algorithms/edge.h"
#include "part6_graph_algorithms/vertex.h"

namespace graph_util {

void PrintPath(Vertex* src, Vertex* dst) {
  if (src == dst) {
    std::cout << Vertex::ToString(src) + " ";
  } else {
    if (dst->predecessor == nullptr) {
      std::cout << "no path from " + Vertex::ToString(src) + " to " + Vertex::ToString(dst) << std::endl;
    } else {
      PrintPath(src, dst->predecessor);
      std::cout << Vertex::ToString(dst) + " ";
    }
  }
}

void InitializeSingleSource(Digraph* digraph, Vertex* src) {
  for (Vertex* u : digraph->vertices) {
    u->depth = std::numeric_limits<int>::max();
    u->predecessor = nullptr;
  }
  src->depth = 0;
}

void Relax(Digraph* digraph, Edge* e) {
  Vertex* u = digraph->vertices[e->Either()];
  Vertex* v = digraph->vertices[e->Other(u->id)];
  int weight = e->weight;
  if (v->depth > u->depth + weight) {
    v->depth = u->depth + weight;
    v->predecessor = u;
  }
}

}  // namespace graph_util

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_
