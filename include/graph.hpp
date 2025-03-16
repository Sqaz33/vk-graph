// файл с объявлением класса графа

#ifndef INCLUDE_GRAPH_HPP
#define INCLUDE_GRAPH_HPP

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace graph {

// ненаправленный граф
class Graph {
public:
    Graph(std::size_t vertexCount);    
    void addEdge(int v, int w);
    const std::vector<int>& getEdges(int v) const;
    std::size_t size() const;

private:
    // список индексирован номерами вершин
    // для каждой вершины мы имеем список вершин
    std::vector<std::vector<int>> edges_;
};

} // namespace graph

#endif // INCLUDE_GRAPH_HPP