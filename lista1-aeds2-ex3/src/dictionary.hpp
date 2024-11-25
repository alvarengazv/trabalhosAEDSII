#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include "avl.hpp"
#include "binaryTree.hpp"

struct Node {
    string word;
    Node* left;
    Node* right;
    int height;

    Node(const string& w) : word(w), left(nullptr), right(nullptr), height(1) {}
};

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h> // For _getch()
#else
    #include <unistd.h>
    #include <termios.h>
    namespace {
        static int _getch() {
            struct termios oldattr, newattr;
            int ch;
            tcgetattr(STDIN_FILENO, &oldattr);          // Save old settings
            newattr = oldattr;
            newattr.c_lflag &= ~(ICANON | ECHO);        // Disable buffering and echo
            tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // Apply new settings
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // Restore old settings
            return ch;
        }
    }
#endif

using namespace std;

void loadDictionaryAVL(AVLTree& tree, const vector<string>& words);
void loadDictionaryBinary(BinaryTree& tree, const vector<string>& words);


#endif