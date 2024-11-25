#include "dictionary.hpp"

// Function to load words into the dictionary (simulating large data volume)
// void loadDictionary(AVLTree& tree, const vector<string>& words) {
void loadDictionary(BinaryTree& tree, const vector<string>& words) {
    for (const auto& word : words) {
        tree.insert(word);
    }
}

// Test the dictionary with different volumes of data
void testDictionary() {
    // AVLTree tree;
    BinaryTree tree;

    // Simulate loading a dictionary with words
    vector<string> words = {
        "apple", "app", "application", "apply", "apt", "banana", "band", "bandana",
        "bandwidth", "bank", "cat", "cater", "catering", "cattle", "dog", "dodge",
        "doll", "dollar", "dolphin", "dot"
    };

    // Load words into the tree
    loadDictionary(tree, words);

    // Simulate user input and measure response time
    vector<string> prefixes = { "ap", "ban", "ca", "do" };

    for (const auto& prefix : prefixes) {
        tree.measureSearchTime(prefix);
        cout << "-------------------------\n";
    }
}