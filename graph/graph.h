#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>

class Graph
{
public:
   explicit Graph(std::istream&);

   const std::vector<int>& neighbors(int vtx) const;

private:
   std::vector<std::vector<int> > m_g;
};

