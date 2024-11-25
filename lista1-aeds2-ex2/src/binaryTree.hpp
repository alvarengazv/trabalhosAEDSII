#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Estrutura do nó da árvore binária
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Classe para manipular a árvore binária
class BinaryTree {
private:
    TreeNode* root;

    // Função auxiliar para calcular a altura máxima
    int calculateMaxLevel(TreeNode* node);

    // Função auxiliar para encontrar o caminho mais longo
    void findLongestPath(TreeNode* node, vector<int>& path, vector<int>& longestPath);

    // Função auxiliar para inserção de um nó
    TreeNode* insertNode(TreeNode* node, int value);

    // Função auxiliar para remoção de um nó
    void removeNode(TreeNode **t, int value);

    // Função auxiliar para encontrar o antecessor
    void antecessor(TreeNode **t, TreeNode *aux);

    // Função auxiliar para sugerir rotações específicas
    void suggestSpecificRotations(TreeNode* node, vector<string>& suggestions, string path);

public:
    BinaryTree() : root(nullptr) {}

    // Inserir valor na árvore
    void insert(int value);

    // Remover valor da árvore
    void remove(int value);

    // Exibir o nível máximo da árvore
    void displayMaxLevel();

    // Exibir o caminho mais longo
    void displayLongestPath();

    // Função para calcular o nível máximo
    int getMaxLevel();

    // Sugerir rotações manuais
    void suggestRotationsDetailed();
};

#endif