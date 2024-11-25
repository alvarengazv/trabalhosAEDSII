#include "dictionary.hpp"

int main() {
    // AVLTree tree;
    BinaryTree tree;

    // Load words into the tree
    vector<string> words = {
        "apple", "app", "application", "apply", "apt", "banana", "band", "bandana",
        "bandwidth", "bank", "cat", "cater", "catering", "cattle", "dog", "dodge",
        "doll", "dollar", "dolphin", "dot"
    };
    loadDictionary(tree, words);

    cout << "AVL Tree Structure:\n";
    tree.displayTree();

    string input;
    cout << "Start typing to get suggestions (press ESC to quit):\n";
    while (true) {
        int ch = _getch();

        // Check for ESC key to exit (ASCII code 27)
        if (ch == 27) {
            break;
        }
        // Backspace key (ASCII code 8 or 127)
        else if (ch == 8 || ch == 127) {
            if (!input.empty()) {
                input.pop_back();

                // Erase the last character from the console
                cout << "\b \b";

                // Clear suggestions below
                cout << "\033[J"; // ANSI escape code to clear from cursor to end of screen
            }
        }
        // Printable characters
        else if (isprint(ch)) {
            input += static_cast<char>(ch);
            cout << static_cast<char>(ch);
        } else {
            continue;
        }

        // Save cursor position
        cout << "\033[s"; // ANSI escape code to save cursor position

        // Move cursor to next line
        cout << "\nSuggestions:\n";

        // Get suggestions
        vector<string> suggestions;
        if (!input.empty()) {
            suggestions = tree.autocomplete(input);
        }

        if (suggestions.empty()) {
            cout << "No suggestions found.\n";
        } else {
            for (const auto& word : suggestions) {
                cout << word << "\n";
            }
        }

        // Clear any remaining suggestions from previous output
        cout << "\033[J"; // ANSI escape code to clear from cursor to end of screen

        // Restore cursor position to input line
        cout << "\033[u"; // ANSI escape code to restore cursor position

        // Move cursor to end of input
        cout.flush();
    }

    return 0;
}