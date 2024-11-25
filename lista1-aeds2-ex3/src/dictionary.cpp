#include "dictionary.hpp"
void loadDictionaryAVL(AVLTree& tree, const vector<string>& words) {
    for (const auto& word : words) {
        tree.insert(word);
    }
}

void loadDictionaryBinary(BinaryTree& tree, const vector<string>& words) {
    for (const auto& word : words) {
        tree.insert(word);
    }
}