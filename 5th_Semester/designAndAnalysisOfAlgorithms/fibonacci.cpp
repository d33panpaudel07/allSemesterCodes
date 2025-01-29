#include <iostream>
using namespace std;

int stepCounter = 0;

int fibo(int n)
{
    stepCounter++;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int result = fibo(n);
    cout << "The " << n << "th term of Fibonacci series is: " << result << endl;
    cout << "Number of steps: " << stepCounter << endl;
    return 0;
}
