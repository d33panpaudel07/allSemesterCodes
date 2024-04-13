#include <iostream>
#include <cmath>
#include <iomanip>  
#define e 0.02
#define f(x) (sin(x) + pow(x, 2) + 5 * x - 9)
// #define f(x) (pow(x,4) -2 * pow(x,3)- x-3)

using namespace std;

int main() {
    int i = 0;
    double xu, xl, fxu, fxl, xm = 0;
    double fxm, error = 0;

    cout << "Enter the value of xu:" << endl;
    cin >> xu;
    cout << "Enter the value of xl:" << endl;
    cin >> xl;

    if (f(xu) * f(xl) < 0) {
        cout << setw(15) << "No. of Iteration" << setw(15) << "xu" << setw(15) << "f(xu)" 
             << setw(15) << "xl" << setw(15) << "f(xl)" << setw(15) << "xm" << setw(15) 
             << "f(xm)" << setw(15) << "error:" << endl;
    
        do {
            fxu = f(xu);
            fxl = f(xl);
            xm = (xl + xu) / 2;
            fxm = f(xm);

            if (xm != 0) {  // Checking for division by zero
                error = abs((xu - xm) / xm);
            } else {
                error = 0;
            }

            cout << setw(15) << i << setw(15) << xu << setw(15) << fxu << setw(15) << xl 
                 << setw(15) << fxl << setw(15) << xm << setw(15) << fxm << setw(15) << error << endl;

            if (fxm * fxl < 0) {
                xu = xm;
            } else {
                xl = xm;
            }

            i++;
        
        } while (error >= e);

    } else {
        cout << "Invalid input please restart the program!! " << endl;
    }
   
    return 0;
}