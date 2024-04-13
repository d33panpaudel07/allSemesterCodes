//simpson 3/8 simple
#include<iostream>
#include<cmath>
#include<cstdlib>
#define f(x) (sin(x)+2*cos(x))

using namespace std;
void simpson(){
    double h,a,b;
    int n;

    cout<<"enter the value of upper limit and lower:"<<endl;
    cin>>b>>a;
    cout<<"enter the  number of partition:"<<endl;
    cin>>n;
    h=(b-a)/n;
   
    double y0=f(a);
    double yn=f(b);
    double y1=f(a+h);
    double y2=f(a+2*h);
    double answer = 0;

   
    answer = (3*h/8) * (y0 + yn+ 3*( y1+y2 ));
    cout<<answer;
}

int main(){
    simpson();
    return 0;
}