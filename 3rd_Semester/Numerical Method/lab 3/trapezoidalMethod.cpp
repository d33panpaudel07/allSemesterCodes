#include<iostream>
#include<cmath>
#include<cstdlib>
#define f(x) (sin(x)+2*cos(x))

using namespace std;
void trapezoidal(){
    double h,a,b;
    int n;

    cout<<"enter the value of upper limit and lower:"<<endl;
    cin>>b>>a;
    cout<<"enter the  number of partition:"<<endl;
    cin>>n;
    h=(b-a)/n;
   
    double y0=f(a);
    double yn=f(b);
    double answer = 0;

   
    answer = h/2 * (y0 + yn );
    cout<<answer;
}

int main(){
    trapezoidal();
    return 0;
}