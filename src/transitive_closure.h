#pragma once

#include "graph.h"

template <typename T, int N>
void applyTransitiveClosure(Graph<T,N>& graph)
{
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (i != k) {
                for (int j = 0; j < N; j++) {
                    if (j != i && j != k) {
                        if (graph.areAdjacent(i, k) &&
                            graph.areAdjacent(k, j) &&
                           !graph.areAdjacent(i, j)) {
                            graph.insertDirectedEdge(i, j);
                        }
                    }
                }
            }
        }
    }
}
