//simpson 3/8 composite:
#include<iostream>
#include<cmath>
#include<cstdlib>
//#define f(x) (pow(x,2)+sin(x)+log(x))
#define f(x) (pow(cos(x),2))

using namespace std;

void simpson(){
    double a, b, h;
    int n;

    cout << "Enter the value of upper limit and lower:" << endl;
    cin >> b >> a;
    cout << "Enter the number of segments (must be even):" << endl;
    cin >> n;

    // Ensure n is even, adjust if necessary
    if(n % 2 != 0) {
        n++; // Make n even
    }

    h = (b - a) / n;
    double sum = f(a) + f(b); // y0 and yn are added once

    for(int i = 1; i < n; i++) {
        double x = a + i * h;
        if(i % 3 == 0) {
            sum += 2 * f(x); // Even index terms have a coefficient of 2
        } else {
            sum += 3 * f(x); // Odd index terms have a coefficient of 4
        }
    }

    double answer = (3*h / 8) * sum;
    cout << "The approximate integral value is: " << answer << endl;
}

int main() {
    simpson();
    return 0;
}