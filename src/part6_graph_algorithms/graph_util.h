#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_

#include "clrs.h"
#include "part6_graph_algorithms/vertex.h"

namespace graph_util {

void PrintPath(Vertex* src, Vertex* dst) {
  if (src == dst) {
    std::cout << Vertex::ToString(src) + " ";
  } else {
    if (dst->pre == nullptr) {
      std::cout << "no path from " + Vertex::ToString(src) + " to " + Vertex::ToString(dst) << std::endl;
    } else {
      PrintPath(src, dst->pre);
      std::cout << Vertex::ToString(dst) + " ";
    }
  }
}

}  // namespace graph_util

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_GRAPH_UTIL_H_
