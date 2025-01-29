#include <iostream>
#include <string>

// Function to recursively generate and print derivations
void derive(std::string current, int depth) {
    if (depth == 0) {
        std::cout << current << std::endl;
        return;
    }

    // Replace S with 'aSb'
    derive("a" + current + "b", depth - 1);

    // Replace S with epsilon (empty string)
    derive(current, depth - 1);
}

int main() {
    int depth;

    std::cout << "Enter the maximum depth of derivation: ";
    std::cin >> depth;

    std::cout << "Derivations:" << std::endl;
    derive("", depth);

    return 0;
}

