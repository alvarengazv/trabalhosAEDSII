#include "binaryTree.hpp"

// Função principal
int main() {
    BinaryTree tree1, tree2;

    // Conjunto de inserções para uma árvore desbalanceada
    vector<int> unbalancedInsertions = {10, 20, 30, 40, 50};
    cout << "Inserindo na árvore desbalanceada:" << endl;
    for (int val : unbalancedInsertions) {
        tree1.insert(val);
    }
    tree1.displayLongestPath();

    // Conjunto de inserções para uma árvore mais equilibrada
    vector<int> balancedInsertions = {30, 20, 40, 10, 50, 25, 35};
    cout << "\nInserindo na árvore mais equilibrada:" << endl;
    for (int val : balancedInsertions) {
        tree2.insert(val);
    }
    tree2.displayLongestPath();

    // Comparação dos níveis máximos
    int maxLevelUnbalanced = tree1.getMaxLevel();
    int maxLevelBalanced = tree2.getMaxLevel();
    cout << "\nNível máximo da árvore desbalanceada: " << maxLevelUnbalanced << endl;
    cout << "Nível máximo da árvore equilibrada: " << maxLevelBalanced << endl;

    // Remoção de dois nós em cada árvore
    tree1.remove(20);
    tree1.remove(30);

    tree2.remove(20);
    tree2.remove(30);

    // Exibição do caminho mais longo
    cout << "\nCaminho mais longo da árvore desbalanceada:" << endl;
    tree1.displayLongestPath();
    cout << "\nCaminho mais longo da árvore equilibrada:" << endl;
    tree2.displayLongestPath();


    // Análise de crescimento
    cout << "\nAnálise de crescimento:" << endl;
    cout << "A árvore desbalanceada apresenta maior profundidade devido à inserção sequencial que favorece um lado." << endl;
    cout << "A árvore equilibrada tem menor profundidade porque as inserções foram feitas de forma a distribuir os valores mais uniformemente." << endl;

    // Sugestões de rotações
    cout << "\nSugestões detalhadas para rotações na árvore desbalanceada:" << endl;
    tree1.suggestRotationsDetailed();

    cout << "\nSugestões detalhadas para rotações na árvore equilibrada:" << endl;
    tree2.suggestRotationsDetailed();

    cout << "\nJustificativa:" << endl;
    cout << "- Rotações à direita são eficazes em subárvores esquerdas que aumentam desnecessariamente a profundidade." << endl;
    cout << "- Rotações à esquerda são eficazes em subárvores direitas profundas que desequilibram a árvore." << endl;
    cout << "- Em árvores extremamente lineares, múltiplas rotações podem ser necessárias para obter melhorias significativas." << endl;
    cout << "- Rotações são limitadas em eficácia para árvores altamente desequilibradas com inserções sequenciais." << endl;

    return 0;
}