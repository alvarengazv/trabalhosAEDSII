#include "binaryTree.hpp"

// Insert a word into the AVL tree
Node* BinaryTree::insert(Node* node, const string& word) {
        if (!node)
            return new Node(word);

        if (word < node->word)
            node->left = insert(node->left, word);
        else if (word > node->word)
            node->right = insert(node->right, word);

        return node;
    }

void BinaryTree::autocomplete(Node* node, const string& prefix, vector<string>& suggestions) {
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
void BinaryTree::insert(const string& word) {
    root = insert(root, word);
}

// Public autocomplete method
vector<string> BinaryTree::autocomplete(const string& prefix) {
    vector<string> suggestions;
    if (prefix.empty())
        return suggestions; // Return an empty list if the prefix is empty
    autocomplete(root, prefix, suggestions);
    return suggestions;
}

// Method to measure search time
vector<string> BinaryTree::measureSearchTime(const string& prefix) {
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

void BinaryTree::printTree() {
    if (root == nullptr) return;

    int maxLevel = getHeight(root);
    int maxWidth = pow(2, maxLevel - 1) * 6; // Adjust width proportional to tree height

    vector<Node*> currentLevel;
    currentLevel.push_back(root);

    for (int level = 1; level <= maxLevel; level++) {
        vector<Node*> nextLevel;
        bool hasMoreNodes = false;

        // Calculate spacing for this level
        int gap = maxWidth / pow(2, level);

        // Print all nodes at the current level
        for (int i = 0; i < currentLevel.size(); i++) {
            Node* node = currentLevel[i];

            // Print leading spaces for this node
            if (i == 0)
                cout << setw(gap / 2) << ""; // First node
            else
                cout << setw(gap) << ""; // Subsequent nodes

            // Print the node value or a blank space for null
            if (node) {
                cout << node->word;
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
                hasMoreNodes |= (node->left || node->right); // Check if more nodes exist
            } else {
                cout << " ";
                nextLevel.push_back(nullptr);
                nextLevel.push_back(nullptr);
            }
        }
        cout << endl;

        // Print connections between nodes
        if (level != maxLevel) {
            for (int i = 0; i < currentLevel.size(); i++) {
                Node* node = currentLevel[i];

                // Print leading spaces for connection lines
                if (i == 0)
                    cout << setw(gap / 2) << "";
                else
                    cout << setw(gap) << "";

                // Print left and right child connections
                if (node) {
                    cout << (node->left ? "/" : " ");
                    cout << setw(2) << (node->right ? "\\" : " ");
                } else {
                    cout << "   "; // Placeholder for null nodes
                }
            }
            cout << endl;
        }

        // Update the current level and check if tree traversal is complete
        currentLevel = nextLevel;
        if (!hasMoreNodes) break;

        maxWidth /= 2; // Halve the spacing for the next level
    }
}

int BinaryTree::getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Helper function to print the tree
// void BinaryTree::printTree(Node* node, string indent, bool last) {
//     if (node != nullptr) {
//         cout << indent;
//         if (last) {
//             cout << "R----";
//             indent += "     ";
//         } else {
//             cout << "L----";
//             indent += "|    ";
//         }
//         cout << node->word << endl;
//         printTree(node->left, indent, false);
//         printTree(node->right, indent, true);
//     }
// }

void BinaryTree::displayTree() {
    // printTree(root, "", true);
    printTree();
}