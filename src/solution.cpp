#include "solution.hpp"

#include <queue>

namespace solution {
    std::vector<int> bfs(const graph::Graph& g, int startV) {
        std::vector<int> resNVisited(g.size(), -1);
        std::queue<int> queue;

        queue.push(startV); 
        resNVisited.at(startV) = 0;

        while (!queue.empty()) {
            int v = queue.front();
            queue.pop();
            auto&& adj = g.getEdges(v);
            for (auto&& w : adj) {
                if (resNVisited[w] == -1) {
                    resNVisited[w] = resNVisited[v] + 1;
                    queue.push(w);
                }
            }
        }

        return resNVisited;
    }

} // namespace solution