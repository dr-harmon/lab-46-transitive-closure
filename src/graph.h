#pragma once

#include <array>
#include <ostream>
#include <unordered_map>

template <typename T, int N>
class Graph {

private:

    std::unordered_map<int,T> vertexElements;
    std::array<std::array<int, N>, N> G;

public:

    Graph() : G({}) {}

    void insertVertex(int v, const T& element) {
        vertexElements[v] = element;
    }

    void insertDirectedEdge(int v, int w) {
        G[v][w] = true;
    }

    bool areAdjacent(int v, int w) const {
        return G[v][w];
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "digraph G {\n";

        for (int i = 0; i < N; i++) {
            os << i << " [label=\"" << graph.vertexElements.at(i) << "\" xlabel=\"" << i << "\"];\n";
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (graph.areAdjacent(i, j)) {
                    os << i << " -> " << j << ";\n";
                }
            }
        }

        os << "}\n";

        return os;
    }
};
