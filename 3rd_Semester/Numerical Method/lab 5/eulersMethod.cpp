// Eulers Algorithm
#include<iostream>
#include<cmath>
using namespace std;

float f(float x,float y){
    return x+y;
}

void Eulers(float x,float X[],float Y[],float h){
        int i=1;
        for( i=1;x>X[i-1];i++){
             X[i]=X[i-1]+h;
             Y[i]=Y[i-1]+h*f(X[i-1],Y[i-1]);
        }
        cout<<"When h= "<<h<<" y("<<X[i-1]<<") = "<<Y[i-1]<<endl;
}

int main(){
    float h;
    float x=0.4;
    h=0.1;
    int n=(x-0)/h;
    float X[n+1],Y[n+1];
    X[0]=0;
    Y[0]=1;
    
    Eulers(x,X,Y,h);
    h=0.2;
    Eulers(x,X,Y,h);
    
    return 0;
}