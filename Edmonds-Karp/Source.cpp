#include "EdmondsKarp.h"

int main()
{
	EdmondsKarp_algorithm graph;
	graph.input("input.txt");
	cout << "For this graph maximum flow is: ";
	cout << graph.maxflow() << endl;
	return 0;
}