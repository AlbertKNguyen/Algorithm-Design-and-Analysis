//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void primMST(int vertices, vector< vector<int> > graph);
void printMST(int *parent, int vertices);
void buildGraph(int *node1, int *node2, int *weight, vector< vector<int> > &graph, int edges);

int main() {
    int vertices, edges;

    cin >> vertices;
    cin >> edges;

    int nodes1[edges];
    int nodes2[edges];
    int weight[edges];
    vector< vector<int> > graph(vertices, vector<int> (vertices, 0));

    for(int i = 0; i < edges; i++) {
        cin >> nodes1[i];
        cin >> nodes2[i];
        cin >> weight[i];
    }

    buildGraph(nodes1, nodes2, weight, graph, edges);
    primMST(vertices, graph);

    return 0;
}
  
void buildGraph(int *node1, int *node2, int *weight, vector< vector<int> > &graph, int edges) {
    for(int i = 0; i < edges; i++) {
        graph[node1[i]][node2[i]] = weight[i];
        graph[node2[i]][node1[i]] = weight[i];
    }
}
 
void printMST(int *parent, int vertices) { 
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << endl;
    }
} 

void primMST(int vertices, vector< vector<int> > graph) {
    int parent[vertices], key[vertices];  
    bool considered[vertices];  
  
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX, considered[i] = false; 
    }
  
    key[0] = 0;      
    parent[0] = -1; 

    for (int i = 0; i < vertices - 1; i++) { 
        int min = INT_MAX, minIndex; 

        for (int j = 0; j < vertices; j++) {
            if (considered[j] == false && key[j] < min) {
                min = key[j], minIndex = j; 
            }
        }

        int u = minIndex;
        considered[u] = true; 

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && considered[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v]; 
            }
        }
    } 

    printMST(parent, vertices); 
} 