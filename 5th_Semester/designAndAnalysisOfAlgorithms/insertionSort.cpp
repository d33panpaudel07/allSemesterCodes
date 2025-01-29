#include <iostream>
using namespace std;

int stepsCounter = 0;

void insertionSort()
{
    int arr[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};

    // APPARENTLY THIS CODE BELOW IS CALLED LAMBDA FUCNTIONS IN CPP
    auto exchange = [](int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    };

    for (int i = 1; i < 10; i++)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            exchange(arr[j + 1], arr[j]);
            j--;
            stepsCounter++;
        }
        arr[j + 1] = current;
        stepsCounter++;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    cout << "Total steps: " << stepsCounter << endl;
}

int main()
{
    insertionSort();
    return 0;
}