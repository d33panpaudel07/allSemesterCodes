//simpson1/3 simple
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
    double answer = 0;

   
    answer = h/3 * (y0 + yn+ 4 *y1 );
    cout<<answer;
}

int main(){
    simpson();
    return 0;
}