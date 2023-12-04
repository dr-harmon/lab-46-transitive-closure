#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "transitive_closure.h"

using namespace std;

TEST_CASE("Transitive closure (all edges)")
{
	Graph<char,5> graph;
	enum Vertices {A, B, C, D, E};

	graph.insertVertex(A, 'A');
	graph.insertVertex(B, 'B');
	graph.insertVertex(C, 'C');
	graph.insertVertex(D, 'D');
	graph.insertVertex(E, 'E');

	graph.insertDirectedEdge(A, B);
	graph.insertDirectedEdge(A, C);
	graph.insertDirectedEdge(A, D);
	graph.insertDirectedEdge(B, D);
	graph.insertDirectedEdge(C, D);
	graph.insertDirectedEdge(C, E);
	graph.insertDirectedEdge(D, E);
	graph.insertDirectedEdge(E, A);

    applyTransitiveClosure(graph);

	REQUIRE_FALSE(graph.areAdjacent(A, A));
	REQUIRE(graph.areAdjacent(A, B));
	REQUIRE(graph.areAdjacent(A, C));
	REQUIRE(graph.areAdjacent(A, D));
	REQUIRE(graph.areAdjacent(A, E));

	REQUIRE(graph.areAdjacent(B, A));
	REQUIRE_FALSE(graph.areAdjacent(B, B));
	REQUIRE(graph.areAdjacent(B, C));
	REQUIRE(graph.areAdjacent(B, D));
	REQUIRE(graph.areAdjacent(B, E));

	REQUIRE(graph.areAdjacent(C, A));
	REQUIRE(graph.areAdjacent(C, B));
	REQUIRE_FALSE(graph.areAdjacent(C, C));
	REQUIRE(graph.areAdjacent(C, D));
	REQUIRE(graph.areAdjacent(C, E));

	REQUIRE(graph.areAdjacent(D, A));
	REQUIRE(graph.areAdjacent(D, B));
	REQUIRE(graph.areAdjacent(D, C));
	REQUIRE_FALSE(graph.areAdjacent(D, D));
	REQUIRE(graph.areAdjacent(D, E));

	REQUIRE(graph.areAdjacent(E, A));
	REQUIRE(graph.areAdjacent(E, B));
	REQUIRE(graph.areAdjacent(E, C));
	REQUIRE(graph.areAdjacent(E, D));
	REQUIRE_FALSE(graph.areAdjacent(E, E));
}

TEST_CASE("Transitive closure (some edges)")
{
	Graph<char,5> graph;
	enum Vertices {A, B, C, D, E};

	graph.insertVertex(A, 'A');
	graph.insertVertex(B, 'B');
	graph.insertVertex(C, 'C');
	graph.insertVertex(D, 'D');
	graph.insertVertex(E, 'E');

	graph.insertDirectedEdge(A, C);
	graph.insertDirectedEdge(B, D);
	graph.insertDirectedEdge(B, C);
	graph.insertDirectedEdge(C, D);
	graph.insertDirectedEdge(D, E);

    applyTransitiveClosure(graph);

	REQUIRE_FALSE(graph.areAdjacent(A, A));
	REQUIRE_FALSE(graph.areAdjacent(A, B));
	REQUIRE(graph.areAdjacent(A, C));
	REQUIRE(graph.areAdjacent(A, D));
	REQUIRE(graph.areAdjacent(A, E));

	REQUIRE_FALSE(graph.areAdjacent(B, A));
	REQUIRE_FALSE(graph.areAdjacent(B, B));
	REQUIRE(graph.areAdjacent(B, C));
	REQUIRE(graph.areAdjacent(B, D));
	REQUIRE(graph.areAdjacent(B, E));

	REQUIRE_FALSE(graph.areAdjacent(C, A));
	REQUIRE_FALSE(graph.areAdjacent(C, B));
	REQUIRE_FALSE(graph.areAdjacent(C, C));
	REQUIRE(graph.areAdjacent(C, D));
	REQUIRE(graph.areAdjacent(C, E));

	REQUIRE_FALSE(graph.areAdjacent(D, A));
	REQUIRE_FALSE(graph.areAdjacent(D, B));
	REQUIRE_FALSE(graph.areAdjacent(D, C));
	REQUIRE_FALSE(graph.areAdjacent(D, D));
	REQUIRE(graph.areAdjacent(D, E));

	REQUIRE_FALSE(graph.areAdjacent(E, A));
	REQUIRE_FALSE(graph.areAdjacent(E, B));
	REQUIRE_FALSE(graph.areAdjacent(E, C));
	REQUIRE_FALSE(graph.areAdjacent(E, D));
	REQUIRE_FALSE(graph.areAdjacent(E, E));
}
