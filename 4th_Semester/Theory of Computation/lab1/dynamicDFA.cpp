#include<iostream>
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
	Node *present = NULL;

public:
	odd_a() {
		cout << "Enter a string to check: ";
		cin >> userInput;

		askNOD(); //asking number of data
		char *LOI = new char[NOI]; //array with list of inputs to check later on
		fillingLoi(LOI);

		Node_dfa *states = new Node_dfa[NOS];
		creatingStates(states);

		connectingStates(states, LOI);

		askingInitialAndFinalStates(states);

		bool result = test(userInput, LOI);

		cout << result;

		//to create states and point them to other states
//		Node_dfa q0, q1;

//		q0.name = "q0";
//		q0.aip = &q1;
//		q0.bip = &q0;
//		q1.name = "q1";
//		q1.aip = &q0;
//		q1.bip = &q1;
//		q1.fnl = 1;
	}

	bool test(string userInput, char *loi) {
//		for (char c : inp) {

//			switch (loi[i]) {
//			case 'a':
//				cout << present->name;
//				present = present->aip;
//				cout << "->" << present->name << endl;
//				break;
//			case 'b':
//				cout << present->name;
//				present = present->bip;
//				cout << "->" << present->name << endl;
//				break;
//			default:
//				cout << "Unexpected error occurred";
//			}
		for (char c : userInput) {
			if (loi[0] == c) {
				present = present->aip;
			} else if (loi[1] == c) {
				present = present->bip;
			}
		}
		return present->fnl;
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
//			for (int j = 0; j < NOI; j++) { // for dynamic inputs BUT NO
//			}
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
			los[i].name = "q" + to_string(i); //could not directly connect strings when converting from integer
			los[i].fnl = 0;
			los[i].aip = NULL;
			los[i].bip = NULL;
//			for (int j = 0; i < NOI; i++) { //for dynamic number of inputs but failed as structure may not support dynamically
			//creating data members
//			}
		}
	}

	void fillingLoi(char *loi) {
		for (int i = 0; i < NOI; i++) {
			loi[i] = (char) (i + 65);
		}
	}

//Asking for number of inputs
	void askNOD() {
		cout << "Enter number of states : ";
		cin >> NOS;
		NOI = 2;
//		cout << "Enter number of inputs (i.e A, B, C, ...., Z less than 26) : ";
//		cin >> NOI;

		//updating number of edges based on number of states
		NOE = NOS * NOI;

	}
};

int main() {
//	cout << "Hello world";
//	cout << endl;

	odd_a a1;

	return 0;
}

