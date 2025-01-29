#include <iostream>
#include <climits>
using namespace std;

void minMaxSearch(int arr[], int low, int high, int &minVal, int &maxVal, int &steps) {
    steps++; // Increment for function call
    if (low == high) { // Single element
        minVal = maxVal = arr[low];
        //steps += 3; // 1 condition + 2 assignments
        return;
    }

    if (high == low + 1) { // Two elements
        if (arr[low] < arr[high]) {
            minVal = arr[low], maxVal = arr[high];
        } else {
            minVal = arr[high], maxVal = arr[low];
        }
        //steps += 5; // 2 conditions + 2 comparisons + 2 assignments
        return;
    }

    int mid = (low + high) / 2, minL, maxL, minR, maxR;
    //steps++; // For calculating mid
    minMaxSearch(arr, low, mid, minL, maxL, steps);
    minMaxSearch(arr, mid + 1, high, minR, maxR, steps);

    minVal = min(minL, minR);
    maxVal = max(maxL, maxR);
    //steps += 4; // For 2 `min` and 2 `max` operations
}

int main() {
    int arr[] = {2, 5, 3, 1, 8, 93, 7, 55, 11, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minVal = INT_MAX, maxVal = INT_MIN, steps = 0;

    minMaxSearch(arr, 0, n - 1, minVal, maxVal, steps);

    cout << "Minimum: " << minVal << "\nMaximum: " << maxVal << "\nSteps: " << steps << endl;
    return 0;
}
