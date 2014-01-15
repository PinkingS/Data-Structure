#include "Graph.h"
#include <string>
using namespace std;

int main(){
	Graph G;
	string filename = "graph.data";
	G = ReadGraph(filename);
	return 0;

}
