# Lab 46: Transitive Closure

In this lab, we'll look at how to compute the transitive closure of a graph using the Floyd-Warshall algorithm.

## Graph ADT

A simplified graph ADT has been provided in `graph.h`. It differs from the graph ADT from previous labs in the following ways:

* Vertices are represented as zero-based indices, not `Vertex` references.
* Edges have no associated type.
* It uses a matrix representation (instead of adjacency list) so that determining whether two vertices are adjacent can be done in constant time.
* It requires that the total number of vertices is known at build time.
* It can be printed in DOT format using the `<<` operator.

Refer to the code in `main` for an example of how to create and print graphs using this ADT.

## Transitive Closure

To compute the transitive closure, start with the provided `applyTransitiveClosure` function. It takes a graph as a reference parameter, so instead of creating a new graph as the return value, you can simply modify the given one in-place.

Implement the function by following the Floyd-Warshall pseudocode from Example 13.22 in the textbook. Remember that the graph ADT expects zero-based indices, so your `k` loop should start with 0, not 1. Also, you do not need to create multiple graphs for each `k`; simply apply the calculations to the current state of the graph.

Make sure all test cases pass before continuing.

## Self Loops

The provided `main` function prints a graph and its transitive closure. Run `main`, then copy-paste the output into a DOT viewer such as [Edotor](https://edotor.net). Observe the differences between the two graphs.

Next, comment out the `i ≠ j` and `i, j ≠ k` conditions in your `applyTransitiveClosure` function, then re-run `main`. How did the transitive closure change? Do you see the self-loops? What do these self-loops indicate?
