#include <iostream>
#include <algorithm>
using namespace std;
// incomplete

class node
{
public:
    int data;
    int max;
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

int cal_include(node* vertex) {

    node* left = vertex->left;
    node *right = vertex->right;
    int includeSum = 0;
    if(left != NULL) {
        if(left->left != NULL) {
            includeSum += left->left->max;
        }
        if(left->right != NULL) {
            includeSum += left->right->max;
        }
    }

    if(right != NULL) {
        if(right->left != NULL) {
            includeSum += right->left->max;
        }
        if(right->right != NULL) {
            includeSum += right->right->max;
        }
    }

    return includeSum;
}

int cal_exclude(node* vertex) {


    int sum = 0;

}

int max_sumUtil(node* vertex) {

    int included = cal_include(vertex) + vertex->data;
    int exclude = cal_exclude(vertex);
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
}