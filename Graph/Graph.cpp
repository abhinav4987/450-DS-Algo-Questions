#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class graph {
    public:
    int nodes;
    int edges;
    vector<vector<int>> adjList;

    graph(int nodes,int edges) {
        this->nodes = nodes;
        this->edges = edges;
        for (int i = 0;i<edges;i++) {
            vector<int> graphNode;
            graphNode.push_back(i);
            adjList.push_back(graphNode);
        }
    }

    void printGraph() {
        for (int i = 0; i < this->adjList.size();i++) {
            cout << i << " ==>   ";
            for (int j = 0; j < this->adjList[i].size();j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int a,int b,bool biDirection) {
        this->adjList[a].push_back(b);
        if(biDirection) {
            this->adjList[b].push_back(a);
        }
    }
};

int main() {
    cout << "what are the number of nodes!!" << endl;
    int nodes;
    cin >> nodes;
    cout << "what are the number of edges!!" << endl;
    int edges;
    cin >> edges;

    graph Graph = graph(nodes, edges);
    for (int i = 0; i<edges; i++) {
        int a,b;
        cin >> a >> b;
        Graph.addEdge(a, b, true);
    }

        Graph.printGraph();
}