#ifndef _Graph_H
#include<string>
using namespace std;

struct VertexNode;
typedef struct VertexNode *Vertex;
struct GraphStruct;
typedef struct GraphStruct *Graph;

Graph ReadGraph(string filename);
//Graph InitGraph(int VertexNum);
//void insert(int from, int to, int weight, Graph G);
void DestroyGraph(Graph G);
void showGraph(Graph G);


#endif
