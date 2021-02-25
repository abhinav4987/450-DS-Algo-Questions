// 67 34 89 23 45 79 90 15 70 85

// inorder
// 15 23 34 45 67 70 79 85 89 90 

// preorder
// 67 34 23 15 45 89 79 70 85 90


// step 1

// root = 67
// left : 15 23 34 45 } 4 elements
// right : 70 79 85 89 90 } 5 elements

// step 2

// left_side  = 34 23 15 45 || 15 23 34 45
// right_side = 89 79 70 85 90 || 70 79 85 89 90

// left_side_root = 34
// right_side_root = 89


// right_side_left = 70 79 85
// right_side_right = 90

// step 3 
// (right sub tree)

using namespace std;
#include<iostream>
#include<algorithm>

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

node* construction(int inorder[],int preorder[],int n,node* vertex) {
    int root = preorder[0];
    int pivot;
    for (int i = 0; i < n;i++) {
        if(inorder[i] == root) {
            pivot = i;
            break;
        }
    }
    int n1, n2;
    n1 = pivot ;
    n2 = n - 1 - pivot;
    int left_inorder[n1],left_preorder[n1];
    int right_inorder[n2],right_preorder[n2];
    for (int i = 0; i < n1;i++) {
        left_inorder[i] = inorder[i];
        left_preorder[i] = preorder[1+i]
    }
    for (int i = 0; i < n2; i++)
    {
        right_inorder[i] = inorder[pivot + 1 + i];
        right_preorder[i] = preorder[1 + i + n1];
    }
    if(vertex == NULL) {
        vertex = get_newNode(pivot);
    }
    vertex->left = construction(left_inorder,left_preorder,n1,vertex->left);
    vertex->right = construction(right_inorder, right_preorder, n2, vertex->right);
    return vertex;
}

int main() {

    int n;
    cin >> n;

    int inorder[n];
    int preorder[n];

    for (int i = 0; i < n;i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n;i++) {
        cin >> preorder[i];
    }
    node *root = NULL;
    root = construction(inorder, preorder,n,root);
}