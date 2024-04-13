#include<iostream>
#include<cmath>
using namespace std;

#define f(x) (1/x)

void gauss(){
    cout<<"This is Gaussian integration for n=3 points:"<<endl;
    double a,b;
    cout<<"Enter the value of a(lower limit) and b(upper limit):"<<endl;
    cin>>a>>b;
    
    // Correct the weights and the sqrt calculations by using floating-point numbers
    double w1 = 5.0/9.0;
    double w2 = 8.0/9.0;
    double w3 = 5.0/9.0;
    double z1 = -sqrt(3.0/5.0);
    double z2 = 0.0;
    double z3 = sqrt(3.0/5.0);

    // Correctly calculate the points for function evaluation
    double x1 = (((b-a) / 2.0) * z1) + (b + a) / 2.0;
    double x2 = (((b-a) / 2.0) * z2) + (b + a) / 2.0;
    double x3 = (((b-a) / 2.0) * z3) + (b + a) / 2.0;

    // Evaluate the function at those points
    double fx1 = f(x1);
    double fx2 = f(x2);
    double fx3 = f(x3);

    // Calculate the final answer
    double answer = ((b-a) / 2.0) * ((w1 * fx1) + (w2 * fx2) + (w3 * fx3));
    
    cout << "The approximate integral value is: " << answer << endl;
}

int main(){
    gauss();
    return 0;
}