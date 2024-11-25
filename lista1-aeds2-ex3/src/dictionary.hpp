#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
// #include "avl.hpp"
#include "binaryTree.hpp"

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

// Function to load words into the dictionary (simulating large data volume)
// void loadDictionary(AVLTree& tree, const vector<string>& words);
void loadDictionary(BinaryTree& tree, const vector<string>& words);

// Test the dictionary with different volumes of data
void testDictionary();

#endif