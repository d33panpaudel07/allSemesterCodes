#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

#define f(x,y) (exp(-x )+ y)

double integrationDouble(double a, double b, double c, double d){
    
    double result = ((d - c) * (b - a)) * (f(a, c) + f(a, d) + f(b, c) + f(b, d)) / 4.0;
    return result;
}

int main(){
    double a, b, c, d;
    cout << "Enter the value of first integration lower limit (a):" << endl;
    cin >> a;
    cout << "Enter the value of first integration upper limit (b):" << endl;
    cin >> b;
    cout << "Enter the value of second integration lower limit (c):" << endl;
    cin >> c;
    cout << "Enter the value of second integration upper limit (d):" << endl;
    cin >> d;

    cout << "Approximate double integral value: " << integrationDouble(a, b, c, d) << endl;

    return 0;
}