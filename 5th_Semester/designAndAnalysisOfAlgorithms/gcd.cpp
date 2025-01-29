#include <iostream>
using namespace std;
int gcd(int num1, int num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    else if (num2 == 0)
    {
        return num1;
    }
    else if (num1 == num2)
    {
        return num1;
    }
    else if (num1 > num2)
    {
        return gcd(num1 - num2, num2);
    }
    else
    {
        return gcd(num1, num2 - num1);
    }
}

int main()
{
    int num1, num2;
    cout << "Enter a: ";
    cin >> num1;
    cout << "Enter b: ";
    cin >> num2;

    int result = gcd(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}