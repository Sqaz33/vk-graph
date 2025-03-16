// файл с объявлением решения

#ifndef INCLUDE_SOLUTION_HPP
#define INCLUDE_SOLUTION_HPP

#include <vector>

#include "graph.hpp"

namespace solution {
// поиск в ширину
std::vector<int> bfs(const graph::Graph& g, int startV);

}

#endif // INCLUDE_SOLUTION_HPP