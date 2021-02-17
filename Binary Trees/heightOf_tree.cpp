#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
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
int calHeight(node* vertex,int height) {
    if(vertex != NULL) {
        height += 1;
        return max(max(calHeight(vertex->left,height), calHeight(vertex->right,height)),height);
    } else
        return 0;
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

    cout << calHeight(root,0)<<endl;
}