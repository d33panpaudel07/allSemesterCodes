#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int x,y;
    cout<<"Enter the row of matrix: ";
    cin>>x;
    cout<<"Enter the column of matrix: ";
    cin>>y;

    float A[x][y];
    float X[x],Y[x],Xnew[x];
    X[x/2]=1;
    float stop=1;
    float k;
    float error[x];

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<"Enter for a"<<i+1<<j+1<<" : ";
            cin>>A[i][j];
        }
    }
    int c=0;
    do{
        for(int i=0;i<x;i++){
            Y[i]=0;
            for(int j=0;j<y;j++){
                //cout<<Y[i]<<" + "<<A[i][j]<<" * "<<X[j]<<endl;
                Y[i]=Y[i]+A[i][j]*X[j];
            }
            cout<<Y[i]<<" ";
        }
        cout<<endl;
        
        k=Y[0];
        for(int j=0;j<x;j++){
            if(Y[j]>k){
                k=Y[j];
            }
        }
        cout<<"k= "<<k;
        cout<<endl;
        for(int j=0;j<x;j++){
            Xnew[j]=Y[j]/k;
            cout<<Xnew[j]<<" ";
        }
        cout<<endl;
        stop=1;
            for(int i=0;i<x;i++){
            if(Xnew[i]==0){
                error[i]=0;
            }else{
                error[i]=abs((Xnew[i]-X[i])/Xnew[i]);
            }
	        cout<<error[i]<<" ";
	        if(error[i]>0.05){
	            stop=0;
	        }
	        }
           cout<<endl;
            for(int j=0;j<x;j++){
                X[j]=Xnew[j];
            }
            cout<<endl<<endl;
            c++;
            
    }while(stop!=1);
    for(int j=0;j<x;j++){
        cout<<Xnew[j]<<" ";
    }
    cout<<endl<<k;
    return 0;
}