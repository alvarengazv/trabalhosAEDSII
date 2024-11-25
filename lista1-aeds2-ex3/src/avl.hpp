#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Node structure for AVL Tree
struct Node {
    string word;
    Node* left;
    Node* right;
    int height;

    Node(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Get the height of the node
    int getHeight(Node* node);

    // Calculate balance factor
    int getBalance(Node* node);

    // Right rotate subtree rooted with y
    Node* rightRotate(Node* y);

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x);

    // Insert a word into the AVL tree
    Node* insert(Node* node, const string& word);

    // Search for words with a given prefix
    void autocomplete(Node* node, const string& prefix, vector<string>& suggestions);

    // Helper function to print the tree
    void printTree(Node* node, string indent, bool last);

public:
    AVLTree() : root(nullptr) {}

    // Public insert method
    void insert(const string& word);

    // Public autocomplete method
    vector<string> autocomplete(const string& prefix);

    vector<string> measureSearchTime(const string& prefix);

    void displayTree();
};

#endif