#include <iostream>
#include<string>
using namespace std;

typedef struct Node {
    string name;
    bool fnl = 0;
    Node *aip = NULL;
    Node *bip = NULL;
} Node_dfa;

class odd_a {
    int NOS = 0; //no of states
    int NOI = 0; //no of inputs
    
    
    
    
    
    
    
    int NOE = 0; //no of edges
    string userInput;
    Node_dfa *present = NULL;

public:
    odd_a() {
        cout << "Enter a string to check: ";
        cin >> userInput;

        askNOD(); // Asking number of data
        char *LOI = new char[NOI]; // Array with list of inputs to check later on
        fillingLoi(LOI);

        Node_dfa *states = new Node_dfa[NOS];
        creatingStates(states);

        connectingStates(states, LOI);

        askingInitialAndFinalStates(states);

        bool result = test(userInput, LOI, states); // Pass states as a parameter to test

        cout << (result ? "1" : "0") << endl; // Display the result as 1 or 0

        delete[] LOI; // Clean up dynamic memory allocation for LOI
        delete[] states; // Clean up dynamic memory allocation for states
    }

    bool test(string userInput, char *loi, Node_dfa *states) {
        present = &states[0]; // Start from the initial state

        for (char c : userInput) {
            if (c == loi[0]) { // Transition based on first input character
                present = present->aip;
            } else if (c == loi[1]) { // Transition based on second input character
                present = present->bip;
            } else {
                cout << "Unexpected character in input: " << c << endl;
                return false; // If there is an unexpected character
            }
        }
        return present->fnl; // Return true if the final state is an accepting state
    }

    void askingInitialAndFinalStates(Node_dfa *states) {
        int userChoice = 0;
        cout << "... Enter values for states i.e 0 to n-1 ...";
        cout << "Enter initial state: ";
        cin >> userChoice;
        present = &states[userChoice];

        userChoice = NOI - 1;
        cout << "Enter final state: ";
        cin >> userChoice;
        states[userChoice].fnl = 1;
    }

    void connectingStates(Node_dfa *los, char *loi) {
        int destState = 0;
        for (int i = 0; i < NOS; i++) {
            cout << "Where is " << loi[0] << " of " << los[i].name
                    << " connected to {enter 0 to (no of states-1)} : ";
            cin >> destState;
            los[i].aip = &los[destState];

            cout << "Where is " << loi[1] << " of " << los[i].name
                    << " connected to {enter 0 to (no of states-1)} : ";
            cin >> destState;
            los[i].bip = &los[destState];
        }
    }

    void creatingStates(Node_dfa *los) {
        for (int i = 0; i < NOS; i++) {
            los[i].name = "q" + to_string(i); // Could not directly connect strings when converting from integer
            los[i].fnl = 0;
            los[i].aip = NULL;
            los[i].bip = NULL;
        }
    }

    void fillingLoi(char *loi) {
        for (int i = 0; i < NOI; i++) {
            loi[i] = (char) (i + 97);
        }
    }

    void askNOD() {
        cout << "Enter number of states : ";
        cin >> NOS;
        NOI = 2; // Hardcoded for 'A' and 'B'

        NOE = NOS * NOI;
    }
};

int main() {
    odd_a a1;
    return 0;
}
