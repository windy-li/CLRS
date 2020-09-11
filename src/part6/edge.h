#include "clrs.h"

struct Edge {
  int start_id;
  int end_id;

  Edge(int start_id, int end_id) :
      start_id(start_id),
      end_id(end_id) {}

  int either() {
    return start_id;
  }

  int other(int vertex_id) {
    if (vertex_id == start_id) {
      return end_id;
    } else if (vertex_id == end_id) {
      return start_id;
    } else {
      throw runtime_error("no such vertex in this edge");
    }
  }
};
