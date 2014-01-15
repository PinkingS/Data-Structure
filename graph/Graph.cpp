#include "Graph.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define MinGraphSize (1)

struct VertexNode{
	int index;
	int weight;
	Vertex next;
};

struct GraphStruct{
	int GraphSize;
	Vertex *TheVertexes;
};

Graph ReadGraph(string filename){
	ifstream graphFile;
	string line;

	graphFile.open(filename.c_str());
	if(!graphFile){
		cout << "Read Graph File Error !" << endl;
		return NULL;		
	}
	getline(graphFile, line);
	int VertexNum = atoi(line.c_str());
	Graph G = InitGraph(VertexNum);

	int from, to, weight;
	while(getline(graphFile, line)){
		istringstream stream(line);
		stream >> from >> to >> weight;
		cout << from << to << weight;
		insert(from, to, weight, G);
	}
}

static Graph InitGraph(int VertexNum){
	Graph G;
	if(VertexNum < MinGraphSize){
		cout << "Vertex size too small!" << endl;
		return NULL;		
	}
	G = (Graph)malloc(sizeof(struct GraphStruct));
	if(G == NULL){
		cout << "out of space !" << endl;
		return NULL;
	}

	G->GraphSize = VertexNum;

	G->TheVertexes = (Vertex *)malloc(sizeof(struct VertexNode) * (VertexNum+1) );//normal vertex index is started from 1
	if(G->TheVertexes == NULL){
		cout << "out of space!" << endl;
		return NULL;
	}

	for(int i = 0; i <= VertexNum; i++){
		G->TheVertexes[i] = (Vertex)malloc(sizeof(struct VertexNode));
		if(G->TheVertexes[i] == NULL){
			cout << "out of space ! " << endl;
			return NULL;
		}
		else
			G->TheVertexes[i]->next = NULL;
	}

	return G;
}

static void insert(int from, int to, int weight, Graph G){
	Vertex V, NewV;
	
	NewV = malloc(sizeof(struct VertexNode));
	if(NewV == NULL){
		cout << "out of space ! " << endl;
		return 1;
	}
	NewV->index = to;
	NewV->weight = weight;

	V = G->TheVertexes[from];
	NewV->next = V->next;
	V->next = NewV;
}

void DestroyGraph(Graph G){
	if(G == NULL)
		return ;
	for(int i = 0; i <= G->GraphSize; i++)
		free(G->TheVertexes[i]);
	free(G->TheVertexes);
	free(G);
}

void showGraph(Graph G){
	int VertexNum = G->GraphSize;
	cout << "Vertex Number : " << VertexNum << endl;

	for(int i = 1; i <= VertexNum; i++){
	
}	
}
