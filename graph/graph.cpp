#include "graph.h"
#include <stdexcept>

Graph::Graph(std::istream &in)
{
   int vertex_count;
   int edge_count;
   in >> vertex_count >> edge_count;
   m_g.resize(vertex_count);
   for(int i = 0; i < edge_count; ++i) {
      int v, n;
      in >> v >> n;
      m_g[v].push_back(n);
   }
}

const std::vector<int>& Graph::neighbors(int v) const
{
   return m_g.at(v);
}

