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

void rev_lvlOrder_print(node* vertex) {
    queue<node *> que;
    stack<node *> stk;

    que.push(vertex);

    while(!que.empty()) {
        node *current = que.front();
        if(current->left != NULL) {
            que.push(current->left);
        } 
        if(current->right != NULL) {
            que.push(current->right);
        }
        stk.push(current);
        que.pop();
    }

    while(!stk.empty()) {
        node *top = stk.top();
        cout << top->data << " ";
        stk.pop();
    }
}

int main() {

    int n;
    cin >> n;

    node *root = new node();
    root->left = NULL;
    root->right = NULL;

    for (int i = 0; i < n;i++) {
        
        int input;
        cin >> input;

        if(i == 0) {
            root->data = input;
        } else {
            if(root->data > input) {
                root->left = addNode(root->left,input);
            }else {
                root->right = addNode(root->right,input);
            }
        }
    }

    rev_lvlOrder_print(root);
    cout << endl;
}