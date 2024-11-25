#include "binaryTree.hpp"

NodeBinary* BinaryTree::insert(NodeBinary* node, const string& word) {
        if (!node)
            return new NodeBinary(word);

        if (word < node->word)
            node->left = insert(node->left, word);
        else if (word > node->word)
            node->right = insert(node->right, word);

        return node;
    }

void BinaryTree::autocomplete(NodeBinary* node, const string& prefix, vector<string>& suggestions) {
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

void BinaryTree::insert(const string& word) {
    root = insert(root, word);
}

vector<string> BinaryTree::autocomplete(const string& prefix) {
    vector<string> suggestions;
    if (prefix.empty())
        return suggestions;
    autocomplete(root, prefix, suggestions);
    return suggestions;
}

vector<string> BinaryTree::measureSearchTime(const string& prefix) {
    auto start = chrono::high_resolution_clock::now();
    vector<string> suggestions = autocomplete(prefix);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sugestoes para \"" << prefix << "\":\n";
    for (const auto& word : suggestions) {
        cout << word << "\n";
    }
    cout << "Tempo de busca: " << duration.count() << " segundos\n";

    return suggestions;
}

int BinaryTree::getHeight(NodeBinary* node) {
    if (node == nullptr)
        return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}