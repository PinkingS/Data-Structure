#ifndef _Graph_H
#include<string>
using namespace std;

#define MaxVertexNum (10)

struct VertexNode;
typedef struct VertexNode *VertexList;
struct TableEntry;
typedef struct TableEntry Table[MaxVertexNum];

void ReadGraph(string filename);
//Graph InitGraph(int VertexNum);
//void insert(int from, int to, int weight, Graph G);
void DestroyTable(Table T);
void showTable(Table T);
void printPath(int V, Table T);
void Dijkstra(Table T);

#endif
