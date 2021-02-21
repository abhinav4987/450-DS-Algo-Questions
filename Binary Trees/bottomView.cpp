#include <iostream>
#include <algorithm>
#include<queue>
#include<stack>
#include<unordered_map>
#include<map>
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

int getHeight(node* vertex, int height) {
    if(vertex == NULL) {
        return 0;
    } else {
        return max(max(getHeight(vertex->right,height+1),getHeight(vertex->left,height+1)), height+1);
    }
}

void calBottomView(node* vertex,map<int,int> &bottom,int h_dis,bool isLeft) {
    
    if(vertex == NULL) {
        return;
    } else {
        if(isLeft == false){
            h_dis += 1;
        } else {
            h_dis -= 1;
        }
        // cout << h_dis << " | " << vertex->data << endl;
        if(bottom.find(h_dis) == bottom.end()) {
            bottom.insert({h_dis, vertex->data});
        } else {
            bottom[h_dis] = vertex->data;
        }
        calBottomView(vertex->left, bottom, h_dis, true);
        calBottomView(vertex->right, bottom, h_dis,false);
    }

}

void bottomview(node* root, map<int,int> &bottom) {

    bottom.insert({0, root->data});
    calBottomView(root->left, bottom, 0, true);
    calBottomView(root->right, bottom, 0, false);
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

    map<int, int> bottom;
    bottomview(root, bottom);
    // sort(bottom.begin(), bottom.end());
    for (auto it = bottom.begin(); it != bottom.end();it++) {
        cout << it->second << " ";
    }
}

// 67 34 89 23 45 79 90 15 70 85