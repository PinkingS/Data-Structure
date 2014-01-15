#include "Graph.h"
#include <string>
using namespace std;

int main(){
	Table T;
	string filename = "graph.data";
	int VertexNum = 7;
	Table T[VertexNum];
	ReadGraph(filename, T);
	showTable(T);
	return 0;

}
