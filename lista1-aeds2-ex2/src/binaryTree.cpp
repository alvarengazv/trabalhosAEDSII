#include "binaryTree.hpp"

int BinaryTree::calculateMaxLevel(TreeNode* node) {
    if (!node) return 0;
    return 1 + max(calculateMaxLevel(node->left), calculateMaxLevel(node->right));
}

void BinaryTree::findLongestPath(TreeNode* node, vector<int>& path, vector<int>& longestPath) {
    if (!node) return;
    path.push_back(node->val);

    if (!node->left && !node->right) {
        if (path.size() > longestPath.size()) {
            longestPath = path;
        }
    } else {
        findLongestPath(node->left, path, longestPath);
        findLongestPath(node->right, path, longestPath);
    }
    path.pop_back();
}

TreeNode* BinaryTree::insertNode(TreeNode* node, int value) {
    if (!node) return new TreeNode(value);
    if (value < node->val)
        node->left = insertNode(node->left, value);
    else
        node->right = insertNode(node->right, value);
    return node;
}

void BinaryTree::removeNode(TreeNode **t, int value){
    TreeNode *aux;
    
    if (*t == NULL){ 
        printf("[ERROR]: Record not found!!!\n");
        return;
    }

    if (value < (*t)->val){ removeNode(&(*t)->left, value); return;}
    if (value > (*t)->val){ removeNode(&(*t)->right, value); return;}

    if ((*t)->right == NULL){ 
        aux = *t;  
        *t = (*t)->left;
        free(aux);
        return;
    }

    if ((*t)->left != NULL){ 
        antecessor(&(*t)->left, *t);
        return;
    }

    aux = *t;  
    *t = (*t)->right;
    free(aux);
}

void BinaryTree::antecessor(TreeNode **t, TreeNode *aux){ 
    if ((*t)->right != NULL){ 
        antecessor(&(*t)->right, aux);
        return;
    }
    
    aux->val = (*t)->val;
    aux = *t; 
    *t = (*t)->left;
    free(aux);
}

void BinaryTree::suggestSpecificRotations(TreeNode* node, vector<string>& suggestions, string path) {
    if (!node) return;

    int leftDepth = calculateMaxLevel(node->left);
    int rightDepth = calculateMaxLevel(node->right);

    if (leftDepth > rightDepth + 1) {
        suggestions.push_back("Rotação à direita no nó com valor " + to_string(node->val) +
                                " (subárvore esquerda muito profunda). Caminho: " + path);
    }
    if (rightDepth > leftDepth + 1) {
        suggestions.push_back("Rotação à esquerda no nó com valor " + to_string(node->val) +
                                " (subárvore direita muito profunda). Caminho: " + path);
    }

    suggestSpecificRotations(node->left, suggestions, path + " -> Left");
    suggestSpecificRotations(node->right, suggestions, path + " -> Right");
}

void BinaryTree::insert(int value) {
    root = insertNode(root, value);
    cout << "Nó inserido: " << value << endl;
    displayMaxLevel();
}

void BinaryTree::remove(int value) {
    removeNode(&root, value);
    cout << "Nó removido: " << value << endl;
    displayMaxLevel();
}

void BinaryTree::displayMaxLevel() {
    int maxLevel = calculateMaxLevel(root);
    cout << "Nível máximo atual: " << maxLevel << endl;
}

void BinaryTree::displayLongestPath() {
    vector<int> path, longestPath;
    findLongestPath(root, path, longestPath);

    cout << "Caminho mais longo da raiz até a folha mais distante: ";
    for (int val : longestPath) {
        cout << val << " ";
    }
    cout << endl;
}

int BinaryTree::getMaxLevel() {
    return calculateMaxLevel(root);
}

void BinaryTree::suggestRotationsDetailed() {
    vector<string> suggestions;
    suggestSpecificRotations(root, suggestions, "Root");

    if (suggestions.empty()) {
        cout << "A árvore já está razoavelmente equilibrada. Nenhuma rotação específica sugerida." << endl;
    } else {
        cout << "Sugestões específicas de rotações para diminuir a profundidade:" << endl;
        for (const auto& suggestion : suggestions) {
            cout << suggestion << endl;
        }
    }
}