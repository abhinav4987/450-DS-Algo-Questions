#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

stack<pair<int,int>> findPath(int posI,int posJ,vector<vector<bool>> visited, vector<vector<int>>maze,int n) {
    
    visited[posI][posJ] = true;
    if(posI == n-1 && posJ == n-1) {
        stack<pair<int, int>> result;
        result.push(make_pair(n-1,n-1));
        return result;
    }

    if ((posJ > 0) && (maze[posI][posJ - 1] == 1) && (visited[posI][posJ - 1] == false)) {
        stack<pair<int, int>> result = findPath(posI, posJ - 1, visited, maze, n);
        pair<int, int> top = result.top();
        if (top.first != -1 && top.second != -1)
        {
            result.push(make_pair(posI, posJ));
            return result;
        }
    }
    if (posI > 0 && (maze[posI - 1][posJ] == 1) && (visited[posI - 1][posJ] == false))
    {
        stack<pair<int, int>> result = findPath(posI -1, posJ, visited, maze, n);
        pair<int, int> top = result.top();
        if (top.first != -1 && top.second != -1)
        {
            result.push(make_pair(posI, posJ));
            return result;
        }
    }
    if ((posJ < n - 1) && (maze[posI][posJ+1] == 1) && (visited[posI][posJ+1] == false))
    {
        stack<pair<int,int>> result = findPath(posI, posJ + 1, visited, maze, n);
        pair<int,int> top = result.top();
        if(top.first != -1 && top.second != -1) {
            result.push(make_pair(posI, posJ));
            return result;
        }
    }
    if ((posI < n - 1) && (maze[posI + 1][posJ] == 1) && (visited[posI + 1][posJ] == false))
    {
        stack<pair<int, int>> result = findPath(posI + 1, posJ, visited, maze, n);
        pair<int, int> top = result.top();
        if (top.first != -1 && top.second != -1)
        {
            result.push(make_pair(posI, posJ));
            return result;
        }
    }
    
    stack<pair<int, int>> result;
    result.push(make_pair(-1, -1));
    return result;
}

void printUtil(stack<pair<int,int>> result) {

    while(!result.empty()) {
        pair<int, int> top = result.top();
        cout << top.first << "-" << top.second << endl;
        result.pop();
    }
}

void printPath(vector<vector<bool>> visited, vector<vector<int>> maze,int n) {
    stack<pair<int, int>> result = findPath(0,0,visited, maze,n);
    pair<int, int> top = result.top();
    if (top.first == -1 && top.second == -1)
    {
        cout << -1 << endl;
    } else {
        printUtil(result);
    }
}


int main() {

    int n;
    cin >> n;
    vector<vector<int>> maze;
    vector<vector<bool>> visited;

    for (int i = 0; i < n;i++ ) {
        vector<bool> insert1;
        vector<int> insert2;
        for (int j = 0;j<n;j++ ) {
            int a;
            cin >>a;
            insert2.push_back(a);
            insert1.push_back(false);
        }
        maze.push_back(insert2);
        visited.push_back(insert1);
    }

    printPath(visited, maze,n);
}