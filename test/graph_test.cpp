#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "graph.h"

#include <sstream>
#include <string>

using namespace std;

TEST_CASE("Create graph")
{
	Graph<char,5> graph;
	enum Vertices { A, B, C, D, E};

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

	ostringstream ss;
	ss << graph;

	const char *dot =
		"digraph G {\n"
		"0 [label=\"A\" xlabel=\"0\"];\n"
		"1 [label=\"B\" xlabel=\"1\"];\n"
		"2 [label=\"C\" xlabel=\"2\"];\n"
		"3 [label=\"D\" xlabel=\"3\"];\n"
		"4 [label=\"E\" xlabel=\"4\"];\n"
		"0 -> 1;\n"
		"0 -> 2;\n"
		"0 -> 3;\n"
		"1 -> 3;\n"
		"2 -> 3;\n"
		"2 -> 4;\n"
		"3 -> 4;\n"
		"4 -> 0;\n"
		"}\n";

	REQUIRE(ss.str() == dot);
}

TEST_CASE("Are adjacent")
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

	REQUIRE_FALSE(graph.areAdjacent(A, A));
	REQUIRE(graph.areAdjacent(A, B));
	REQUIRE(graph.areAdjacent(A, C));
	REQUIRE(graph.areAdjacent(A, D));
	REQUIRE_FALSE(graph.areAdjacent(A, E));

	REQUIRE_FALSE(graph.areAdjacent(B, A));
	REQUIRE_FALSE(graph.areAdjacent(B, B));
	REQUIRE_FALSE(graph.areAdjacent(B, C));
	REQUIRE(graph.areAdjacent(B, D));
	REQUIRE_FALSE(graph.areAdjacent(B, E));

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

	REQUIRE(graph.areAdjacent(E, A));
	REQUIRE_FALSE(graph.areAdjacent(E, B));
	REQUIRE_FALSE(graph.areAdjacent(E, C));
	REQUIRE_FALSE(graph.areAdjacent(E, D));
	REQUIRE_FALSE(graph.areAdjacent(E, E));
}
