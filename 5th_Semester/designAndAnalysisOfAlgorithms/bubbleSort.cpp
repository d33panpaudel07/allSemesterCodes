#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int stepsCounter = 0;

    for (int i = 0; i < 10; i++)  // Outer loop runs 10 times
    {
        for (int j = i + 1; j < 10; j++)  // Inner loop runs (10 - i - 1) times
        {
            stepsCounter++; // Comparison step
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                // Normally we wouldn't consider 3 steps below
                // stepsCounter += 3; // Swapping step (3 assignments)
            }
        }
    }

    cout << endl
         << "final answer: ";
    for (int k = 0; k < 10; k++)
    {
        cout << arr[k] << ", ";
    }

    cout << "\nTotal steps: " << stepsCounter << endl;

    return 0;
}
