#include "avl.hpp"

// Get the height of the node
int AVLTree::getHeight(Node* node) {
    return node ? node->height : 0;
}

// Calculate balance factor
int AVLTree::getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotate subtree rooted with y
Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x
Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Insert a word into the AVL tree
Node* AVLTree::insert(Node* node, const string& word) {
    // Perform normal BST insertion
    if (!node)
        return new Node(word);

    if (word < node->word)
        node->left = insert(node->left, word);
    else if (word > node->word)
        node->right = insert(node->right, word);
    else // Duplicate words not allowed
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor to check whether this node became unbalanced
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && word < node->left->word)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && word > node->right->word)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && word > node->left->word) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && word < node->right->word) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void AVLTree::autocomplete(Node* node, const string& prefix, vector<string>& suggestions) {
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

// Public insert method
void AVLTree::insert(const string& word) {
    root = insert(root, word);
}

// Public autocomplete method
vector<string> AVLTree::autocomplete(const string& prefix) {
    vector<string> suggestions;
    if (prefix.empty())
        return suggestions; // Return an empty list if the prefix is empty
    autocomplete(root, prefix, suggestions);
    return suggestions;
}

// Method to measure search time
vector<string> AVLTree::measureSearchTime(const string& prefix) {
    auto start = chrono::high_resolution_clock::now();
    vector<string> suggestions = autocomplete(prefix);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Suggestions for \"" << prefix << "\":\n";
    for (const auto& word : suggestions) {
        cout << word << "\n";
    }
    cout << "Search time: " << duration.count() << " seconds\n";

    return suggestions;
}

// Helper function to print the tree
void AVLTree::printTree(Node* node, string indent, bool last) {
    if (node != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "     ";
        } else {
            cout << "L----";
            indent += "|    ";
        }
        cout << node->word << endl;
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

void AVLTree::displayTree() {
    printTree(root, "", true);
}