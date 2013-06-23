#include "graph.h"
#include <functional>
#include <queue>
#include <unordered_set>
#include <algorithm>

void bfs(const Graph &g, int start, const std::function<void(int)> &visit_callback)
{
   std::queue<int> q;
   std::unordered_set<int> discovered;

   q.push(start);
   while(!q.empty()) {
      int v = q.front();
      q.pop();
      visit_callback(v);
      const std::vector<int> &neighbors = g.neighbors(v);
      for(int v: neighbors) {
         if(discovered.count(v) == 0){
            q.push(v); 
            discovered.insert(v);
         }
      }
   }
}

int main()
{
   Graph g(std::cin);
   bfs(g, 0, [](int v){ std::cout << v << std::endl; });
   return 0;
}

