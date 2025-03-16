#include <gtest/gtest.h>

#include "graph.hpp"
#include "solution.hpp"

// Тест на создание графа и добавление рёбер
TEST(VK_GRAPH, GraphCreation) {
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    EXPECT_EQ(g.size(), 5);
    EXPECT_EQ(g.getEdges(0), std::vector<int>({1, 2}));
    EXPECT_EQ(g.getEdges(1), std::vector<int>({0, 3}));
    EXPECT_EQ(g.getEdges(3), std::vector<int>({1, 4}));
}

// Тест BFS на простой граф
TEST(VK_GRAPH, BFSSimple) {
    graph::Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    auto distances = solution::bfs(g, 0);

    EXPECT_EQ(distances, (std::vector<int>{0, 1, 1, 2, 3}));
}

// Тест BFS на несвязный граф
TEST(VK_GRAPH, BFSDisconnectedGraph) {
    graph::Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    auto distances = solution::bfs(g, 0);

    EXPECT_EQ(distances, (std::vector<int>{0, 1, 2, -1, -1, -1}));
}

// Тест BFS на граф с циклом
TEST(VK_GRAPH, BFSWithCycle) {
    graph::Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // Цикл

    auto distances = solution::bfs(g, 0);

    EXPECT_EQ(distances, (std::vector<int>{0, 1, 2, 2}));
}

// Тест BFS на одновершинный граф
TEST(VK_GRAPH, BFSOneVertex) {
    graph::Graph g(1);

    auto distances = solution::bfs(g, 0);

    EXPECT_EQ(distances, (std::vector<int>{0}));
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}