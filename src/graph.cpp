#include "../include/graph.hpp"

#include <cassert>

namespace graph {

Graph::Graph(std::size_t vertexCount) :
    edges_(vertexCount) 
{}

void Graph::addEdge(int v, int w) {    
    // т.к. граф - ненаправленный
    edges_.at(v).push_back(w); 
    edges_.at(w).push_back(v);
    // базовая гарантия исключений
}

const std::vector<int>& Graph::getEdges(int v) const {
    return edges_.at(v);
}

std::size_t Graph::size() const {
    return edges_.size();
}

}