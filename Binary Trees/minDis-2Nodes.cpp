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

vector<node*> getNodepath(int val, node* vertex) {
    if(vertex == NULL) {
        return (vector<node*>)NULL;
    } else {
        vector<node *> left = getNodepath(val, vertex->left);
        vector<node *> right = getNodepath(val, vertex->right);

        if (left != (vector<node *>)NULL) {
            left.push_back(vertex);
            return left;
        }
        else if (right != (vector<node *>) NULL) {
            right.push_back(vertex);
            return right;
        } else {
            return (vector<node *>)NULL;
        }
    }
}

int getMin(node* root,int a, int b) {

    vector<node *> node1 = (vector<node*>)NULL;
    vector<node *> node2 = (vector<node*>)NULL;

    node1 = getNodepath(a, root);
    node2 = getNodepath(b, root);

    if (node1 != (vector<node *>)NULL && node2 != (vector<node *>)NULL) {

        int i = 0;
        while(node1[i] == node2[i] && (node1.size() > 1 && node2.size() > 2)) {
            i++;
        }

        int result = node1.size() + node2.size() - 2 + 2 * i;
    }
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
    minJumps(root, k);
}

// 67 34 89 23 45 79 90 15 70 85