#include <iostream>
using namespace std;

typedef struct Node
{
	string name;
	bool fnl = 0;
	Node *aip = NULL;
	Node *bip = NULL;
} Node_dfa;

class odd_a
{
	Node_dfa q0, q1;
	// Node_dfa LOI[NOI];
	Node *present = &q0;

public:
	odd_a()
	{
		q0.name = "q0";
		q0.aip = &q1;
		q0.bip = &q0;
		q1.name = "q1";
		q1.aip = &q0;
		q1.bip = &q1;
		q1.fnl = 1;
	}

	bool test(string inp)
	{
		for (char c : inp)
		{
			//			if(c=='a'){
			//				present = present->aip;
			//			}
			//			else if(c=='b'){
			//				present = present->bip;
			//			}

			switch (c)
			{
			case 'a':
				cout << present->name;
				present = present->aip;
				cout << "->" << present->name << endl;
				break;
			case 'b':
				cout << present->name;
				present = present->bip;
				cout << "->" << present->name << endl;
				break;
			default:
				cout << "Unexpected error occurred";
			}
		}
		return present->fnl;
	}
};

int main()
{
	//	cout<<"Hello world";
	//	cout<<endl;

	odd_a a1;
	string str = "abaaa";
	cout << "For string: " << str << endl;
	bool result = a1.test(str);
	(result) ? (cout << "Accept") : (cout << "Reject");

	return 0;
}
