#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"
using namespace std;

class Graph {
public:
    Graph(int vertices) {   //Constructor creates and initializes adjacency matrix
        numVertices = vertices;
        adjMatrix = new int*[numVertices];  //Creating adjacency matrix
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }
        for (int i = 0; i < numVertices; i++) { //All edges between distinct vertices initially set to INF
            for (int j = 0; j < numVertices; j++) {
                if (i==j) {
                    adjMatrix[i][j] = 0;
                } else {
                    adjMatrix[i][j] = INF;
                }
            }
        }
    }
    ~Graph() {  //Destructor
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete heap;
    }
    void addEdge(int u, int v, int weight) { //Adds given edge weight to adjacency matrix
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {    // Must print MST edges and total weight
        heap = new MinHeap(numVertices);
        int* mst = new int[numVertices];
        int* mstKeys = new int[numVertices];
        int cost = 0;
        for (int i = 0; i < numVertices; i++) { //Initialize arrays with default values
            mst[i] = -1;
            mstKeys[i] = INF;
        }

        mstKeys[0] = 0; //Choosing to start at vertex 0
        for (int i = 0; i < numVertices; i++) { //Inserting all vertices into heap
            heap->insert(i, mstKeys[i]);
        }
        while (heap->isEmpty() != true) {   //Finding the lowest edge weight to add to mst
            int min = heap->extractMin();
            for (int i = 0; i < numVertices; i++) {
                int edgeWeight = adjMatrix[min][i];
                if (edgeWeight != INF && edgeWeight < mstKeys[i] && heap->isInMinHeap(i)) {    //Checking for lowest edge weight that can be added to mst
                    mstKeys[i] = edgeWeight;
                    mst[i] = min;
                    heap->decreaseKey(i, mstKeys[i]);
                }
            }
        }

        for (int i = 1; i < numVertices; i++) { //Printing mst and total cost
            cout<<mst[i]<<"--"<<i<<" ("<<adjMatrix[i][mst[i]]<<")"<<endl;
            cost += adjMatrix[i][mst[i]];
        }
        cout<<"Total cost: "<<cost<<endl;

        delete[] mst;
        delete[] mstKeys;
    }
    void print() {  //Prints adjacency matrix
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

private:
    int** adjMatrix;
    int numVertices;
    const int INF = 1000000000;
    MinHeap* heap;
};

#endif