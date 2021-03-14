using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

#define loop(start, end, i) for (int i = start; i < end; i++)
#define loopRev(start, end, i) for (int i = start; i >= end;i++)

void dfs(int curr,vector<vector<int>> adjList, bool visited[]) {
    
    loop(0,adjList[curr].size(),i) {
        if(visited[adjList[curr][i]] == false) {
            visited[adjList[curr][i]] = true;

        dfs(adjList[curr][i], adjList, visited);
        }
    }
}
//   this one use dfs and bfs to find number of connected components
int makeConnected(int nodes, vector<vector<int>> connections) {

    if(connections.size() < nodes-1){
        return -1;
    }
    vector<vector<int>> adjList;
    int edges = connections.size();
    loop(0,nodes,i) {
        vector<int> neww;
        neww.push_back(i);
        adjList.push_back(neww);
    }
    // cout << "Initiating adjList... " << endl;
    loop(0,connections.size(),i) {
        adjList[connections[i][0]].push_back(connections[i][1]);
        adjList[connections[i][1]].push_back(connections[i][0]);
    }
    // cout << "AdjList created.. " << endl;
    bool visited[nodes];

    loop(0,nodes,i) {
        visited[i] = false;
    }

    bool completed = false;
    int start = 0;
    int components = 0;
    // cout << "repeated DFS initiating ...." << endl;

    while(completed == false) {

        // cout << " Dfs round " << components << endl;
        visited[start] = true;
        dfs(start, adjList, visited);
        loop(0,nodes,i) {
            if(visited[i] == false) {
                break;
            }
            if(i == nodes-1 && visited[i] == true) {
                completed = true;
            }
        }

        loop(0,nodes,i) {
            if(visited[i] == false) {
                start = i;
            }
        }

        components++;
    }

    if(edges >= nodes-1){
        return components-1;
    } else {
        return -1;
    }

}


// solve it using union find


int main() {
    
    int nodes;
    cin >> nodes;
    int edges;
    cin >> edges;

    vector<vector<int>> connections;

    loop(0,edges,i) {
        int a, b;
        cin >> a >> b;

        vector<int> connection;
        connection.push_back(a);
        connection.push_back(b);
        connections.push_back(connection);
    }

    cout << "Initiating..." << endl;

    int result = makeConnected(nodes, connections);

    cout << result << endl;

    return 0;
}