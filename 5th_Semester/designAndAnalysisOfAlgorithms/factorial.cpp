#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    return num * factorial(num - 1);
}

int main()
{
    int num;
    cout << "Enter a number to find it's factorial: ";
    cin >> num;

    int result = factorial(num);
    cout << "The factorial of " << num << " is: " << result;
    return 0;
}
