//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bellmanFord(int vertices, int edges, vector< vector<int> > graph, int *nodes1, int *nodes2);
void print(int *distance, int vertices);
void buildGraph(int *nodes1, int *nodes2, int *weight, vector< vector<int> > &graph, int edges);

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
    bellmanFord(vertices, edges, graph, nodes1, nodes2);

    return 0;
}
  
void buildGraph(int *nodes1, int *nodes2, int *weight, vector< vector<int> > &graph, int edges) {
    for(int i = 0; i < edges; i++) {
        graph[nodes1[i]][nodes2[i]] = weight[i];
    }
}
 
void print(int *distance, int vertices) { 
    for (int i = 0; i < vertices; i++) {
        if(distance[i] != INT_MAX) {
            cout << distance[i] << endl;
        }
        else {
            cout << "INFINITY" << endl;
        }
    }
} 

void bellmanFord(int vertices, int edges, vector< vector<int> > graph, int *nodes1, int *nodes2) {
    bool hasNegativeWeight = false;
    int distance[vertices]; 
  
    for(int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX; 
    }

    distance[0] = 0; 
  
    for(int i = 0; i <= vertices - 1; i++) { 
        for(int j = 0; j < edges; j++) { 
            if(distance[nodes1[j]] != INT_MAX && distance[nodes1[j]] + graph[nodes1[j]][nodes2[j]] < distance[nodes2[j]]) {
                distance[nodes2[j]] = distance[nodes1[j]] + graph[nodes1[j]][nodes2[j]]; 
            }
        } 
    } 
  
    for(int i = 0; i < edges; i++) {
        if(distance[nodes1[i]] != INT_MAX && distance[nodes1[i]] + graph[nodes1[i]][nodes2[i]] < distance[nodes2[i]]) {
            hasNegativeWeight = true;
        }
    } 
  
    if(!hasNegativeWeight) {
        cout << "TRUE" << endl;
        print(distance, vertices); 
    }
    else {
        cout << "FALSE" << endl;
    }
} 