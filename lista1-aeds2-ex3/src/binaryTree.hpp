#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

// Node structure for BINARY Tree
struct Node {
    string word;
    Node* left;
    Node* right;
    int height;

    Node(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
};

// BINARY Tree class
class BinaryTree {
private:
    Node* root;

    // Insert a word into the BINARY tree
    Node* insert(Node* node, const string& word);

    // Search for words with a given prefix
    void autocomplete(Node* node, const string& prefix, vector<string>& suggestions);

    // Helper function to print the tree
    // void printTree(Node* node, string indent, bool last);
    void printTree();
    void printLevel(Node* node, int level, int maxLevel, int indentSpace, int levelWidth);
    int getHeight(Node* node);

public:
    BinaryTree() : root(nullptr) {}

    // Public insert method
    void insert(const string& word);

    // Public autocomplete method
    vector<string> autocomplete(const string& prefix);

    vector<string> measureSearchTime(const string& prefix);

    void displayTree();
};

#endif