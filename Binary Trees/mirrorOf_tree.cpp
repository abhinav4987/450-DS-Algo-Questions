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

// create a normal tree
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

// add function creating mirror tree
node *addNode_mirrorVersion(node *parent, int input)
{
    if (parent == NULL)
    {
        parent = get_newNode(input);
    }
    else if (parent->data == input)
    {
        cout << "already present in the tree ";
    }
    else if (parent->data < input)
    {
        parent->left = addNode_mirrorVersion(parent->left, input);
    }
    else
    {
        parent->right = addNode_mirrorVersion(parent->right, input);
    }
    return parent;
}


int get_replacingNode(node* vertex) {
    if(vertex->left == NULL) {
        return vertex->data;
    } else {
        return get_replacingNode(vertex->left);
    }
}

// deletion function
node* deleteNode(int index,node* vertex) {
    if(vertex == NULL) {
        cout << " requested node not found!! :)";
    }
    else if(index > vertex->data){
        vertex->right =  deleteNode(index, vertex->right);
    } 
    else if(index < vertex->data) {
        vertex->left = deleteNode(index, vertex->left);
    } 
    else {
        if(vertex->right == NULL) {
            node *returNode = vertex->right;
            delete vertex;
            return returNode;
        }else {
            int replace = get_replacingNode(vertex->right);
            vertex->data = replace;
            vertex->right = deleteNode(replace, vertex->right);
            return vertex;
        }
    }
    return vertex;
}


// level order prinitng
void lvl_orderPrint(node *parent)
{
    queue<node *> que;
    que.push(parent);

    while (!que.empty())
    {
        node *current = que.front();
        cout << current->data << " ";
        if (current->left != NULL)
            que.push(current->left);
        if (current->right != NULL)
            que.push(current->right);
        que.pop();
    }
}


int main() {
    node *root = new node();
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n;i++) {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        // int input;
        // cin >> input;
        if (i == 0)
        {
            root->data = array[i];
        }
        else
        {
            if (root->data > array[i])
            {
                root->left = addNode(root->left, array[i]);
            }
            else
            {
                root->right = addNode(root->right, array[i]);
            }
        }
    }
    lvl_orderPrint(root);
    node *mirror = new node();
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mirror->data = array[i];
        }
        else
        {
            if (mirror->data > array[i])
            {
                mirror->right = addNode_mirrorVersion(mirror->right, array[i]);
            }
            else
            {
                mirror->left = addNode_mirrorVersion(mirror->left, array[i]);
            }
        }
    }
    cout << endl;
    lvl_orderPrint(mirror);
}