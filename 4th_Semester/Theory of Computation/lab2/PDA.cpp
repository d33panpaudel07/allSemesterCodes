#include <iostream>
#include <stack>
#include <string>

class PDA {
public:
    bool processString(const std::string& input) {
        std::stack<char> stack;
        bool seenB = false;

        for (char ch : input) {
            if (ch == 'a') {
                if (seenB) {
                    // If we've started seeing 'b', we should not see 'a' for eg like for "abab"
                    return false;
                }
                // Push 'a' onto the stack
                stack.push(ch);
            } else if (ch == 'b') {
                seenB = true;
                // Pop 'a' from the stack if there is one
                if (stack.empty() || stack.top() != 'a') {
                    return false; // More 'b's than 'a's or unmatched 'b' like for abbb or baba
                }
                stack.pop();
            } else {
                // Invalid character
                return false;
            }
        }
        
        // The string is accepted if the stack is empty
        return stack.empty();
    }
};

int main() {
    PDA pda;
    std::string input;
    
    std::cout << "Enter a string of 'a's followed by 'b's: ";
    std::cin >> input;
    
    if (pda.processString(input)) {
        std::cout << "The string is of the form a^n b^n.\n";
    } else {
        std::cout << "The string is not of the form a^n b^n.\n";
    }
    
    return 0;
}

