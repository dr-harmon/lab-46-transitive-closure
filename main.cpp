#include "transitive_closure.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
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
	graph.insertDirectedEdge(B, D);
	graph.insertDirectedEdge(B, C);
	graph.insertDirectedEdge(C, D);
	graph.insertDirectedEdge(D, B);
	graph.insertDirectedEdge(D, E);

	cout << "Original:" << endl;
	cout << graph;

    applyTransitiveClosure(graph);

	cout << "Transitive closure:" << endl;
	cout << graph;

	return EXIT_SUCCESS;
}
