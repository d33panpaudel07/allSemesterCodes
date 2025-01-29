#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int value)
{
    if (!root)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

bool searchBST(Node *root, int value, int &steps)
{
    steps++;
    if (!root)
        return false;
    if (value == root->data)
        return true;
    if (value < root->data)
        return searchBST(root->left, value, steps);
    return searchBST(root->right, value, steps);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    int searchValue;
    cout << "Enter value to search: ";
    cin >> searchValue;

    int stepsCounter = 0;
    if (searchBST(root, searchValue, stepsCounter))
        cout << "Found in " << stepsCounter << " steps!" << endl;
    else
        cout << "Not Found after " << stepsCounter << " steps!" << endl;

    return 0;
}
