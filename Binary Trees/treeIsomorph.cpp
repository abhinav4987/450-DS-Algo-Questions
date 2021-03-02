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


bool isLeaf(node* vertex) {
    if(vertex->left == NULL && vertex->right == NULL) {
        return true;
    } else {
        return false;
    }
}

// modify its done on gfg
bool checkWeaatherIsomorph(node* vertex1,node* vertex2) {
    
    if(vertex1 == NULL && vertex2 == NULL) {
        return true;
    }   

    if(vertex1 == NULL || vertex2 == NULL) {
        return false;
    }

    if(vertex1->data != vertex2->data) {
        return false;
    }

    return (checkWeaatherIsomorph(vertex1->left, vertex2->left) && checkWeaatherIsomorph(vertex1->right, vertex2->right)) ||
        (checkWeaatherIsomorph(vertex1->left, vertex2->right) && checkWeaatherIsomorph(vertex1->right, vertex2->left));
}

int main()
{
    int n1;
    cin >> n1;

    node *root1 = new node();
    root1->left = NULL;
    root1->right = NULL;
    root1->max = INT64_MIN;

    for (int i = 0; i < n1; i++)
    {

        int input;
        cin >> input;

        if (i == 0)
        {
            root1->data = input;
        }
        else
        {
            if (root1->data > input)
            {
                root1->left = addNode(root1->left, input);
            }
            else
            {
                root1->right = addNode(root1->right, input);
            }
        }
    }

    int n2;
    cin >> n2;

    node *root2 = new node();
    root2->left = NULL;
    root2->right = NULL;
    root2->max = INT64_MIN;

    for (int i = 0; i < n2; i++)
    {

        int input;
        cin >> input;

        if (i == 0)
        {
            root2->data = input;
        }
        else
        {
            if (root2->data > input)
            {
                root2->left = addNode(root2->left, input);
            }
            else
            {
                root2->right = addNode(root2->right, input);
            }
        }
    }

    if(checkWeaatherIsomorph(root1, root2)) {
        cout << "yes! the tree is isomorphic." << endl;
    }
}

// 67 34 89 23 45 79 90 15 70 85