#include <iostream>
#include <algorithm>
#include <queue>
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

int callDiameter(node* vertex,int *diameter) {

    if(vertex == NULL) {
        return 0;
    } else {
        int h1 = callDiameter(vertex->left, diameter);
        int h2 = callDiameter(vertex->right, diameter);
        if(h1+h2 > *diameter) {
            cout << h1 << " " << h2 << endl;
            *diameter = (h1 == 0 ? h1 : h1+1) + (h2 == 0 ? h2 : h2+1) ;
        }
        return max(h1, h2) +1;
    }
}

int main() {
    node *root = new node();
    int n;
    cin >> n;

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
    int diameter = 0;
    callDiameter(root, &diameter);
    cout << diameter  << endl;
}