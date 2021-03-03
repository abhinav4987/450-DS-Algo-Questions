#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
    int nodes;
    int edges;
    vector<vector<int>> adjList;

    graph(int nodes, int edges)
    {
        this->nodes = nodes;
        this->edges = edges;
        for (int i = 0; i < nodes; i++)
        {
            vector<int> graphNode;
            graphNode.push_back(i);
            adjList.push_back(graphNode);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < this->adjList.size(); i++)
        {
            cout << i << " ==>   ";
            for (int j = 0; j < this->adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    void addEdge(int a, int b)
    {
        this->adjList[a].push_back(b);
        this->adjList[b].push_back(a);
    }

    void bfs(int start, int nodes)
    {
        bool visited[nodes];

        for (int i = 0; i < nodes; i++)
        {
            visited[i] = false;
        }

        queue<int> que;
        que.push(start);
        visited[start] = true;
        while (!que.empty())
        {
            int top = que.front();
            cout << top << " ";

            for (int i = 1; i < adjList[top].size(); i++)
            {

                if (visited[adjList[top][i]] == false)
                {
                    que.push(adjList[top][i]);
                    visited[adjList[top][i]] = true;
                }
            }
            que.pop();
        }
    }

    void dfs(int current, bool visited[])
    {
        if (this->adjList[current].size() > 1)
        {
            cout << current << " ";
            for (int i = 1; i < adjList[current].size(); i++)
            {
                if (visited[adjList[current][i]] == false)
                {
                    visited[adjList[current][i]] = true;
                    dfs(adjList[current][i], visited);
                }
            }
        }
    }

    bool isCyclicUtil(int current, bool visited[])
    {

        if (this->adjList[current].size() > 1)
        {
            bool result = false;

            for (int i = 1; i < adjList[current].size(); i++)
            {
                if (visited[adjList[current][i]] != false)
                {
                    return true;
                }
                else
                {
                    // cout << "visiting node " << current << " right now" << endl;
                    visited[adjList[current][i]] = true;
                    result = result || isCyclicUtil(adjList[current][i], visited);
                }
            }

            return result;
        }
        else
        {
            return false;
        }
    }

    bool isCyclic(bool visited[])
    {
        bool result = false;
        for (int i = 0; i < this->nodes; i++)
        {
            for (int j = 0; j < this->nodes; j++)
            {
                visited[j] = false;
            }
            result = result || isCyclicUtil(i, visited);
        }

        return result;
    }
};

int main()
{
    cout << "what are the number of nodes!!" << endl;
    int nodes;
    cin >> nodes;
    cout << "what are the number of edges!!" << endl;
    int edges;
    cin >> edges;

    graph Graph = graph(nodes, edges);
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph.addEdge(a, b);
    }

    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }

    Graph.printGraph();

    bool isThereCycle = Graph.isCyclic(visited);
    if (isThereCycle)
    {
        cout << "the directed graph is cyclic!!";
    }
    else
    {
        cout << "the directed graph isn't cyclic";
    }
}