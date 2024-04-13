
#include<iostream>
#include<cmath>
using namespace std;
void calculate(float Ynew[],float X[],int i,int counter){
    for(int k=0;k<counter-i-1;k++){
        Ynew[k]=(Ynew[k+1]-Ynew[k])/(X[k+1+i]-X[k]);
       // cout<<Ynew[k]<<", ";
    }
    cout<<endl;
}

float Hero(int c,float X[],float x,int j,int i){
    float val=1;
    for(int k=0;k<i;k++){
        if(k==j){
            val=val*1;
        }else{
            val=val*(x-X[k]);
        }
    }
    return val;
}

float derivative(float data[],int counter,float X[],float x){
    float output;
   for(int i=1;i<counter;i++){
       if(i==1){
           output=output+data[i-1];
       }else{
           for(int j=0;j<i;j++){
               output=output+data[i-1]*Hero(x,X,x,j,i);
           }
           cout<<endl;
       }
   }
   return output;
}

int main(){
    int counter;
    cout<<"How many points do you want to enter?";
    cin>>counter;
    float x,y,s,h;
    cout<<"Enter the value for calculation: ";
    cin>>x;

    float X[counter],Y[counter],Ynew[counter],data[counter];
    
    // float X[counter]={1,1.2,1.4,1.6,1.8,2};
    // float Y[counter]={0,0.128,0.544,1.296,2.432,4};
    // float data[counter],Ynew[counter];
    for(int i=0;i<counter;i++){
        cout<<"value of x"<<i<<": ";
        cin>>X[i];
        cout<<"value of y"<<i<<": ";
        cin>>Y[i];
        Ynew[i]=Y[i];
    }
    
    for(int i=0;i<counter-1;i++){
        calculate(Ynew,X,i,counter);
        data[i]=Ynew[0];
        //cout<<data[i]<<endl;
    }
    
    y=derivative(data,counter,X,x);
    cout<<"Derivative = "<<y;
    
    return 0;
}