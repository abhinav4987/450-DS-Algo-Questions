#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// incomplete

class node
{
public:
    int data;
    long long int max;
    node *left, *right;
};

node *get_newNode(int input)
{
    node *nya = new node();
    nya->data = input;
    nya->left = NULL;
    nya->right = NULL;
    nya->max = INT64_MIN;
    return nya;
}

node *addNode(node *parent, int input)
{
    if (parent == NULL)
    {
        parent = get_newNode(input);
    }
    else if (parent->data == input)
    {
        cout << "already present in the tree ";
    }
    else if (parent->data > input)
    {
        parent->left = addNode(parent->left, input);
    }
    else
    {
        parent->right = addNode(parent->right, input);
    }

    return parent;
}

int get_replacingNode(node *vertex)
{
    if (vertex->left == NULL)
    {
        return vertex->data;
    }
    else
    {
        return get_replacingNode(vertex->left);
    }
}

node *deleteNode(int index, node *vertex)
{
    if (vertex == NULL)
    {
        cout << " requested node not found!! :)";
    }
    else if (index > vertex->data)
    {
        vertex->right = deleteNode(index, vertex->right);
    }
    else if (index < vertex->data)
    {
        vertex->left = deleteNode(index, vertex->left);
    }
    else
    {
        if (vertex->right == NULL)
        {
            node *returNode = vertex->right;
            delete vertex;
            return returNode;
        }
        else
        {
            int replace = get_replacingNode(vertex->right);
            vertex->data = replace;
            vertex->right = deleteNode(replace, vertex->right);
            return vertex;
        }
    }
    return vertex;
}

void kSum_root_leaf(node *vertex, int sum, int k, vector<int> path)
{
    if (vertex == NULL)
    {
        return;
    }
    else
    {
        path.push_back(vertex->data);
        sum += vertex->data;

        if (sum == k)
        {
            // loop print the vector.
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " ";
            }
            cout << endl;
            return;
        }

        kSum_root_leaf(vertex->left, sum, k, path);
        kSum_root_leaf(vertex->right, sum, k, path);

        path.pop_back();
        return;
    }
}

void printPath(node *root, int k)
{

    if (root == NULL)
    {
        return;
    }

    vector<int> path;
    kSum_root_leaf(root, 0, k, path);
    printPath(root->left, k);
    printPath(root->right, k);
    return;
}

void printVec(vector<int> path, int j)
{
    for (int i = path.size() - 1; i >= j; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void kSum_root_leaf2(node *vertex, int sum, int k, vector<int> &path)
{
    if (vertex == NULL)
    {
        return;
    }
    else
    {
        // cout << vertex->data << endl;
        path.push_back(vertex->data);

        int temp = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            temp += path[i];
            // cout << temp << endl;
            if (temp == k)
            {
                printVec(path, i );
            }
        }

        kSum_root_leaf2(vertex->left, sum, k, path);
        kSum_root_leaf2(vertex->right, sum, k, path);

        path.pop_back();
        return;
    }
}

void printPath2(node *root, int k)
{
    vector<int> path;
    kSum_root_leaf2(root, 0, k, path);
}

int main()
{
    int n;
    cin >> n;

    node *root = new node();
    root->left = NULL;
    root->right = NULL;
    root->max = INT64_MIN;

    for (int i = 0; i < n; i++)
    {

        int input;
        cin >> input;

        if (i == 0)
        {
            root->data = input;
        }
        else
        {
            if (root->data > input)
            {
                root->left = addNode(root->left, input);
            }
            else
            {
                root->right = addNode(root->right, input);
            }
        }
    }
    int k;
    cin >> k;
    printPath2(root, k);
}

// 67 34 89 23 45 79 90 15 70 85