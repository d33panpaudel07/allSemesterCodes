#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
};

int main()
{
    Node myNewNode;
    myNewNode.data = 100;
    cout << "Data: " << myNewNode.data;

    // myNode.data = 5;
    // cout << "Data on node is: " << myNode.data << endl;
    // myNode.next = &myNode2;
    // myNode2.data = 10;
    // cout << "Data on myNode2 is: " << myNode.next->data << endl;
}