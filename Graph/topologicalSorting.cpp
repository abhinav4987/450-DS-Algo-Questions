
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> topoUtil(stack<int> &result,vector<vector<int>> adjList,int current,int visited[]) {

    for (int i = 0; i < adjList[current].size();i++) {
        if(visited[adjList[current][i]] == 0) {
            visited[adjList[current][i]] = 1;
            result = topoUtil(result,adjList, adjList[current][i], visited);
        }
    }
    // cout << current ;
    result.push(current);
    return result;
}

stack<int> topo(vector<vector<int>> adjList,vector<int> start,int nodes) {

    int visited[nodes];
    for (int i = 0; i < nodes;i++) {
        visited[i] = 0;
    }

    stack<int> result;
    for (int i = 0; i < start.size();i++) {
        visited[start[i]] = 1;
        result = topoUtil(result, adjList, start[i], visited);
    }
    cout << endl;
    return result;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    int visited[nodes];
    for (int i = 0; i < nodes;i++) {
        visited[i] = 0;
    }
    vector<vector<int>> adjList;
    for (int i = 0; i < nodes;i++) {
        vector<int> newList;
        newList.push_back(i);
        adjList.push_back(newList);
    }

    for (int i = 0; i < edges;i++) {
        int a,b;
        cin >> a >> b;
        visited[b] = 1;
        adjList[a].push_back(b);
    }
    vector<int> start;
    for (int i = 0; i < nodes; i++)
    {
        if(visited[i] == 0) {
            start.push_back(i);
        }
    }

    
    stack<int> result = topo(adjList, start, nodes);
    int size = result.size();
    for (int i = 0;i<size;i++) {
        cout << result.top() << " ";
        result.pop();
    }
        cout << endl;
}