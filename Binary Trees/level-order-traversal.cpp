#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


class node{
    public:
        int data;
        node *left, *right;
};

node* get_newNode(int input) {
    node* nya = new node();
    nya->data = input;
    nya->left = NULL;
    nya->right = NULL;

    return nya;
}

node* addNode(node* parent,int input) {
    
    if(parent == NULL) {
        parent = get_newNode(input);
    } else if(parent->data == input) {
        cout << "already present in the tree ";
    } else if(parent->data > input) {
        parent->left = addNode(parent->left, input);
    } else {
        parent->right = addNode(parent->right, input);
    }

    return parent;
}

void lvl_orderPrint(node* parent){

    queue<node *> que;
    que.push(parent);

    while (!que.empty())
    {
        node *current = que.front();
        cout << current->data << " ";
        if(current->left != NULL)
            que.push(current->left);
        if(current->right != NULL)    
            que.push(current->right);
        
        que.pop();
    }
}

int main() {
    node *root = new node();
    int n;
    cin >> n;

    for (int i = 0; i < n;i++) {
        int input;
        cin >> input;
        if(i == 0) {
            root->data = input;
        } else {
            if(root->data > input) {
                root->left = addNode(root->left,input);
            } else {
                root->right = addNode(root->right,input);
            }
        }
    }

    lvl_orderPrint(root);
}