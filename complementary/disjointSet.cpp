#include<vector>
#include<iostream>
#include<algorithm>
#define loop(i, start, end) for (int i = start; i < end;i++)
using namespace std;

class edge {
    public:
        int a;
        int b;
        int weight;

        edge(int a,int b,int weight) {
            this->a = a;
            this->b = b;
            this->weight = weight;
        }
};

int Find(int element,int set[]) {
    if (set[element] == element) {
        return element;
    } else {
        return Find(set[element], set);
    }

}

int getHeight(int element,int set[]) {

    if (set[element] == element)
    {
        return 0;
    }
    else
    {
        return getHeight(set[element], set) + 1;
    }
}

void Union(int set[],int setA,int setB,int parentA,int parentB) {

    int heightA = getHeight(setA, set);
    int heightB = getHeight(setB, set);

    if(heightA > heightB) {
        set[parentB] = parentA;
    } else {
        set[parentA] = parentB;
    }
}

int main() {

    int nodes, edges;
    cin >> nodes >> edges;

    vector<edge> graphEdges;

    loop(i,0,edges) {
        int a, b;
        cin >> a >> b;
        int weight;
        cin >> weight;
        edge newEdge = edge(a, b, weight);
        graphEdges.push_back(newEdge);
    }

    sort(graphEdges.begin(), graphEdges.end(), [](const edge &lhs, const edge &rhs) {
        return lhs.weight < rhs.weight;
    });

    loop(i,0,edges) {
        cout << graphEdges[i].a << "--" << graphEdges[i].b << " || " << graphEdges[i].weight << endl;
    }

    int set[edges];
    loop(i,0,edges) {
        set[i] = i;
    }

    vector<edge> mst;
    int i = 0;
    while(mst.size() < nodes-1 && i < edges) {
        if(mst.size() == 0) {
            mst.push_back(graphEdges[0]);
            i++;
        } else {
            int setA = Find(graphEdges[i].a, set);
            int setB = Find(graphEdges[i].b, set);
            if(setA != setB) {
                Union(set, graphEdges[i].a, graphEdges[i].b,setA,setB);
                mst.push_back(graphEdges[i]);
            }
            i++;
        }
    }


    loop(i,0,mst.size()) {
        cout << mst[i].a << " " << mst[i].b << " || " << mst[i].weight << endl;
    }
}