// Heuns Algorithm
#include<iostream>
#include<cmath>
using namespace std;

float f(float x,float y){
    return x+y;
}

void Heuns(float x,float X[],float Y[],float h,float m1,float m2){
        int i=1;
        for( i=1;x>X[i-1];i++){
            m1=f(X[i-1],Y[i-1]);
            m2=f(X[i-1]+h,Y[i-1]+h*m1);
             X[i]=X[i-1]+h;
             Y[i]=Y[i-1]+h/2*(m1+m2);
        }
        cout<<"When h= "<<h<<" y("<<X[i-1]<<") = "<<Y[i-1]<<endl;
}

int main(){
    float h,m1,m2;
    float x=0.4;
    h=0.1;
    int n=(x-0)/h;
    float X[n+1],Y[n+1];
    X[0]=0;
    Y[0]=1;
    
    Heuns(x,X,Y,h,m1,m2);
    h=0.2;
    Heuns(x,X,Y,h,m1,m2);
    
    return 0;
}