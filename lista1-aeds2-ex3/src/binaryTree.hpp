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

struct NodeBinary {
    string word;
    NodeBinary* left;
    NodeBinary* right;
    int height;

    NodeBinary(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
};

class BinaryTree {
    private:
        NodeBinary* root;

        NodeBinary* insert(NodeBinary* NodeBinary, const string& word);

        void autocomplete(NodeBinary* NodeBinary, const string& prefix, vector<string>& suggestions);

        int getHeight(NodeBinary* NodeBinary);

    public:
        BinaryTree() : root(nullptr) {}

        void insert(const string& word);

        vector<string> autocomplete(const string& prefix);

        vector<string> measureSearchTime(const string& prefix);

};

#endif