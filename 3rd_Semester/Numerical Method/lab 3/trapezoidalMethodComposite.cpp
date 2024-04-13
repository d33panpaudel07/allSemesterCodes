#include<iostream>
#include<cmath>
#include<cstdlib>
#define f(x) (exp(pow(-x, 2)))

using namespace std;
void trapezoidal(){
    double h,a,b;
    int n;

    cout<<"enter the value of upper limit and lower:"<<endl;
    cin>>b>>a;
    cout<<"enter the  number of partition:"<<endl;
    cin>>n;
    h=(b-a)/n;
    double hehe=h/2;
    double y0=f(a);
    double yn=f(b);
    double answer = 0;

    for(double i=a+h; i<=b-h; i+=h){
        double y=f(i);
        answer += y;
    }
    answer = hehe * (y0 + yn + 2*answer);
    cout<<answer;
}

int main(){
    trapezoidal();
    return 0;
}