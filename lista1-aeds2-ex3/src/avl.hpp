#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

struct NodeAVL {
    string word;
    NodeAVL* left;
    NodeAVL* right;
    int height;

    NodeAVL(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
    private:
        NodeAVL* root;

        int getHeight(NodeAVL* NodeAVL);

        int getBalance(NodeAVL* NodeAVL);

        NodeAVL* rightRotate(NodeAVL* y);

        NodeAVL* leftRotate(NodeAVL* x);

        NodeAVL* insert(NodeAVL* NodeAVL, const string& word);

        void autocomplete(NodeAVL* NodeAVL, const string& prefix, vector<string>& suggestions);

    public:
        AVLTree() : root(nullptr) {}

        void insert(const string& word);

        vector<string> autocomplete(const string& prefix);
};

#endif