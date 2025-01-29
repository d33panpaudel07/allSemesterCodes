#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int curr_min;
    int temp;
    int stepsCounter = 0;

    for (int i = 0; i < 10; i++)
    {
        curr_min = i;
        for (int j = i + 1; j < 10; j++)
        {
            stepsCounter++;
            if (arr[j] < arr[curr_min])
            {
                curr_min = j;
            }
        }
        temp = arr[curr_min];
        arr[curr_min] = arr[i];
        arr[i] = temp;
        stepsCounter++;
    }

    for (int k = 0; k < 10; k++)
    {
        cout << arr[k] << ", ";
    }
    cout << endl;

    cout << "Total steps: " << stepsCounter << endl;

    return 0;
}
