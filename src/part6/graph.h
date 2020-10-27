#include "../clrs.h"
#include "edge.h"
#include "vertex.h"

struct Graph {
  int v;
  int e;
  std::vector<Vertex*> vertices;
  std::vector<std::list<Edge*>> adj;

  void AddEdge(int start_id, int end_id) {
    Edge* edge = new Edge(start_id, end_id);
    adj[start_id].push_back(edge);
    adj[end_id].push_back(edge);
    edge += 2;
  }
};

class Graph1 {
 private:
  int v_count_;
  int e_count_;

 public:
  int v_count() { return v_count_; }

  int e_count() { return e_count_; }

  void AddEdge() { std::cout << v_count() << e_count() << std::endl; }
};
