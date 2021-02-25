#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class node
{
    public:
        int data;
        node *left, *right;
    
    node() {

    }

    node(const node &obj) {
        this->data = obj.data;
        this->left = obj.left;
        this->right = obj.right;
    }
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

void conversionUtil(node* vertex, vector<int> &order) {

    if(vertex == NULL) {
        return;
    }
    else {
        conversionUtil(vertex->left,order);
        order.push_back(vertex->data);
        conversionUtil(vertex->right, order);
        return;
    }
}

void insert(node* dll,int val) {
    if(dll == NULL) {

    } else {
        node *temp = dll;
        while(temp->right != NULL) {
            temp = temp->right;
        }

        node *newNode = new node();
        temp->right = newNode;
        temp->right->data = val;
        temp->right->left = temp;
        temp->right->right = NULL;
    }
}

node* conversion(node *vertex) {

    vector<int> order;
    conversionUtil(vertex, order);

    node *DLL = new node();
    DLL->left = NULL;
    DLL->right = NULL;
    if(order.size() > 0) {
        DLL->data = vertex->data;

        node *tree = vertex;

        int i = 1;
        while(i < order.size()) {
            insert(DLL, order[i]);
        }
    }

    return DLL;
}


int main() {

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

    
    node* DoubleLinkedList = conversion(root);
    
}