#include <iostream>
#include <cmath>
#include <iomanip>
// #define f(x) sin(x) + pow(x, 2) + 5 * x - 9
//  #define f(x) (log(x)-3*pow(x,2)+5)
// #define f(x) (4*pow(x,3)- 2*x - 6)
//  #define f(x) ( pow(e,x)-3*x)
// #define f(x) (x-pow(e,x)+2)
#define f(x) (x* sin(x) -1)
#define e 0.05

using namespace std;

int main() {
    int i = 0;
    
    double x0, x1, fx0, fx1, result, finalResult, error = 0;

    cout << "Enter the value of x0:" << endl;
    cin >> x0;
    cout << "Enter the value of x1:" << endl;
    cin >> x1;

    cout << setw(15) << "No. of Iteration" << setw(15) << "(x0)" << setw(15) << "f(x0)" << setw(15) << "(x1)" << setw(15) << "f(x1)" << setw(15) << "result" << setw(15) << "f(result)" << setw(15) << "error:" << endl;
    
    do {
        fx0 = f(x0);
        fx1 = f(x1);
        result = x1 - ((x1 - x0) * fx1) / (fx1 - fx0);
        finalResult = f(result);
        error = abs((result - x1) / result);
        i++;
        
        cout << setw(15) << i << setw(15) << x0 << setw(15) << fx0 << setw(15) << x1 << setw(15) << fx1 << setw(15) << result << setw(15) << finalResult << setw(15) << error << endl;

        x0 = x1; 
        
        x1 = result;  
       
         
    } while (error >= e);

    return 0;
}