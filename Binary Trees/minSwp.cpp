// concept use
// when you use inorder traversal, you get an increasing sequence.
// but in a binary tree which is not a BST
// so store the inorder traversal and calculate the  number of minimum swaps you will need to sort it.
// we will be doing that instead of the whole question
// also it is considered that the tree is complete

// solving the question - "calculate the minimum number of swaps needed to swap the array"
// beautiful question uses graphs
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];


    for (int i = 0; i<n; i++ ) {
        cin >> array[i];
    }

    int swaps = 0;

}