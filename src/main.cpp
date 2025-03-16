#include <fstream>
#include <iostream>
#include <filesystem>
#include <exception>
#include <stdexcept>

#include "graph.hpp"
#include "solution.hpp"

static graph::Graph readGraph(std::istream& in, 
                              long long vertexesCount, 
                              long long edgesCount) 
{   
    if (vertexesCount < 0 || edgesCount < 0) {
        throw std::logic_error("It is impossible to create a graph.");
    }
    graph::Graph g(vertexesCount);
    while (edgesCount--) {
        int v, w;
        in >> v >> w;
        g.addEdge(v, w);
    }
    return g;
}


int main(int argc, char** argv) try {
    if (argc > 2) {
        std::cerr << "Too many arguments" << std::endl;
        return 1;
    }
    std::filesystem::path fname = "graph.txt";
    if (argc == 2) {
        fname = argv[1];
    }

    std::ifstream ifs(fname);
    if (!ifs) {
        std::cerr << "Couldn't open the file" << std::endl;
        return 1;
    }
    long long vertexesCount, edgesCount;
    ifs >> vertexesCount >> edgesCount;
    auto g = readGraph(ifs, vertexesCount, edgesCount);
    long long startVertex;
    ifs >> startVertex;

    auto res = solution::bfs(g, startVertex);

    for (auto n : res) {
        std::cout << n << '\n';
    }

} catch (const std::exception& e) {
    std::cerr << "The input graph is incorrect" << std::endl;
    std::cerr << e.what() << std::endl;
    return 1;
}