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
	VertexNode *next;
};

struct TableEntry{
	VertexList header;
	int known;
	int path;
	int dist;
};

static void InitTable(int VertexNum, Table T){
	if(VertexNum < MinGraphSize){
		cout << "Vertex size too small!" << endl;
		return NULL;		
	}
/*	
	T = (Table)malloc(sizeof(struct GraphStruct));
	if(G == NULL){
		cout << "out of space !" << endl;
		return NULL;
	}


	G->TheVertexes = (Vertex *)malloc(sizeof(struct VertexNode) * (VertexNum+1) );//normal vertex index is started from 1
	if(G->TheVertexes == NULL){
		cout << "out of space!" << endl;
		return NULL;
	}
*/
	for(int i = 0; i <= VertexNum; i++){
		T[i].header = (Vertex)malloc(sizeof(struct VertexNode));
		if(T[i].header == NULL){
			cout << "out of space ! " << endl;
			return NULL;
		}
		else{
			T[i].header->next = NULL;
			T[i].known = FALSE;
			T[i].path = -1;
			T[i].dist = INT_MAX;
		}
	}
}

static void Insert(int from, int to, int weight, Table T){
	VertexNode *V;
	VertexNode *NewV;
	
	NewV = (VertexNode*)malloc(sizeof(struct VertexNode));
	if(NewV == NULL){
		cout << "out of space ! " << endl;
		return ;
	}
	NewV->index = to;
	NewV->weight = weight;
	NewV->next = T[from].header->next;
	T[from].header->next = NewV;
}

void ReadGraph(string filename, Table T){
	ifstream graphFile;
	string line;

	graphFile.open(filename.c_str());
	if(!graphFile){
		cout << "Read Graph File Error !" << endl;
		return NULL;		
	}
	getline(graphFile, line);
	int VertexNum = atoi(line.c_str());
	InitTable(VertexNum, T);

	int from, to, weight;
	while(getline(graphFile, line)){
		istringstream stream(line);
		stream >> from >> to >> weight;
		cout << from << to << weight;
		Insert(from, to, weight, T);
	}
}

void DestroyTable(Table T){
	if(T == NULL)
		return ;
	for(int i = 0; i <= MaxVertexNum; i++)
		free(T[i].header);
}

void showTable(Table T){
	int VertexNum = G->GraphSize;
	cout << "Vertex Number : " << VertexNum << endl;
	VertexList VL;

	for(int i = 1; i <= 7; i++){
		cout << "Vertex " << i << endl;
		VL = T[i].header;
		while(V->next != NULL){
			VL = VL->next;
			cout <<	"\t\t---" << VL->weight << "--->" << VL->index << endl; 
		}
	}	
}
