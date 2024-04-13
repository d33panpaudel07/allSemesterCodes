#include <iostream>
#include <cmath>
#include <iomanip>  // For setw function
// #define f(x) sin(x) + pow(x, 2) + 5 * x - 9
// #define df(x) cos(x) + 2 * x + 5
// #define f(x) (pow(x,2)-5*x+6)
// #define df(x) (2*x-5)
// #define f(x) (pow(x,3)-6*pow(x,2)+11*x -6)
// #define df(x) (3*pow(x,2)-6*2*x+ 11)
// #define f(x) (pow(x,5) - 3*(pow(x,2)) - 100)
// #define df(x) (5*pow(x,4)-3*2*x)
#define f(x) (pow(x,4)-21*pow(x,3)+149*pow(x,2)-399*x+270)//basic part of question
#define df(x) (4*pow(x,3)-21*3*pow(x,2)+149*2*x-399)//differentiating given function
#define e 0.05//setting minimum error value

using namespace std;

int main() {
    int i = 0;
    double xOld, xNew, fxOld, dfxOld, result,error;

    cout << "Enter the value of x:" << endl;
    cin >> xOld;

cout << setw(20) << "No. of Iteration:" << setw(20) << "xOld" << setw(25) << "f(xOld)" << setw(23)<<"f'(xOld)"<<setw(18)<<"xNew"<<setw(20)<<"Error:"<<endl;
    do {
        fxOld = f(xOld);
        dfxOld = df(xOld);
        xNew = xOld - (fxOld / dfxOld);

     if (xNew != 0) {
            error = fabs((xNew - xOld) / xNew);
        } else {
            error = 0;
        }

        result = fxOld;
        
       i++;
       
        cout << setw(10) << i << setw(30) << xOld << setw(25) << fxOld <<setw(20) << dfxOld <<setw(20)<<xNew<<setw(20)<<error<<endl;
        xOld = xNew;
         
    } while (fabs(result) >= e);

    return 0;
}