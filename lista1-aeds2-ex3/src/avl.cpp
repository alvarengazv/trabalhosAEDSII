#include "avl.hpp"

int AVLTree::getHeight(NodeAVL* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(NodeAVL* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

NodeAVL* AVLTree::rightRotate(NodeAVL* y) {
    NodeAVL* x = y->left;
    NodeAVL* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

NodeAVL* AVLTree::leftRotate(NodeAVL* x) {
    NodeAVL* y = x->right;
    NodeAVL* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

NodeAVL* AVLTree::insert(NodeAVL* node, const string& word) {
    if (!node)
        return new NodeAVL(word);

    if (word < node->word)
        node->left = insert(node->left, word);
    else if (word > node->word)
        node->right = insert(node->right, word);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    if (balance > 1 && word > node->left->word) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && word < node->right->word) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::autocomplete(NodeAVL* node, const string& prefix, vector<string>& suggestions) {
    if (!node)
        return;

    if (node->word.compare(0, prefix.size(), prefix) == 0) {
        suggestions.push_back(node->word);
        autocomplete(node->left, prefix, suggestions);
        autocomplete(node->right, prefix, suggestions);
    } else if (prefix < node->word) {
        autocomplete(node->left, prefix, suggestions);
    } else {
        autocomplete(node->right, prefix, suggestions);
    }
}

void AVLTree::insert(const string& word) {
    root = insert(root, word);
}

vector<string> AVLTree::autocomplete(const string& prefix) {
    vector<string> suggestions;
    if (prefix.empty())
        return suggestions;
    autocomplete(root, prefix, suggestions);
    return suggestions;
}