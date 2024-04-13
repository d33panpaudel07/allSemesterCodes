#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
    int degree,c;
    float x,output;
    cout<<"Enter the value of x=";
    cin>>x;
    cout << "Enter highest degree: ";
    cin >> degree;
    c=degree;
    float A[degree],B[degree];
    
    for(int i=0;i<=degree;i++){
        cout<<"Enter a coefficient of degree "<<c<<" :";
        cin>>A[c];
        if(i==0){
            B[c]=A[c];          
            cout<<B[c]<<endl;
        } else{
            B[c]=A[c]+B[c+1]*x;
            cout<<B[c]<<endl;
        }
        c--;
    }
    output=B[0];

    cout << endl << "Final output: " << output   ;
    return 0;
}