#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

node *get_newNode(int input)
{
    node *nya = new node();
    nya->data = input;
    nya->left = NULL;
    nya->right = NULL;

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

void zigZag(node *vertex ) {

    vector<vector<node*>> tree;
    vector<node*> top;
    top.push_back(vertex);
    tree.push_back(top);
    int i = 0;
    while(true) {
        int j = 0;
        vector<node *> next;

        for (int j = 0;j<tree[i].size();j++) {
            if(tree[i][j]->left != NULL){
                next.push_back(tree[i][j]->left);
            } 
            if(tree[i][j]->right != NULL) {
                next.push_back(tree[i][j]->right);
            }
        }

        if(!next.empty()) {
            tree.push_back(next);
            next.clear();
            i++;
        } else {
            break;
        }
    }

    bool flag = true;
    for (int i = 0;i<tree.size();i++) {
        if(flag == true) {
            for (int j = 0; j < tree[i].size(); j++)
            {
                cout << tree[i][j]->data << " ";
            }
        } else {
            for (int j = tree[i].size() - 1; j >= 0; j--) {
                cout << tree[i][j]->data << " ";
            }
        }
        cout << endl;
        flag = !flag;
    }
}

int main()
{
    int n;
    cin >> n;

    node *root = new node();
    root->left = NULL;
    root->right = NULL;

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

    zigZag(root);
}

// 67 34 89 23 45 79 90 15 70 85