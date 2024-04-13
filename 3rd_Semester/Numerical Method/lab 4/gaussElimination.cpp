#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int x,y;
	cout<<"How many equations do you have? ";
	cin>>x;
	cout<<"How many variables do you have? ";
	cin>>y;

	float A[x][y+1];
	float X[x];
	for(int i=0;i<x;i++){
		cout<<"For 1st equation: "<<endl;
		for(int j=0;j<=y;j++){
			if(j==y){
				cout<<"Enter the value of constant : ";
			}else{
				cout<<"Enter the value of x"<<i+1<<" : ";
			}
			cin>>A[i][j];
		}
		cout<<endl;
	}


float val;
	for(int k=0;k<x;k++){
		//display
		for(int i=0;i<x;i++){
			for(int j=0;j<=y;j++){
				cout<<A[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<x;i++){
			if(i<k){
				continue;
			}
			val=A[i][k];
			for(int j=0;j<=y;j++){
				if(i==k){
					A[i][j]=A[i][j]/val;
				}	else{
					A[i][j]=A[i][j]-val *A[k][j];
				}
			}
		}
	}
	
	for(int i=0;i<x;i++){
			for(int j=0;j<=y;j++){
				cout<<A[i][j]<<"\t";
			}
			cout<<endl;
	}
	
	for(int i=x-1;i>=0;i--){
	    val=A[i][x];
	    cout<<val<<endl;
			for(int j=x-1;j>0;j--){
				if(i==j){
				    continue;
				}else{
				    cout<<val<<" - "<<A[i][j]<<" * "<<X[j]<<endl;
				    val=val-A[i][j]*X[j];
				}
		    }
		X[i]=val;
		cout<<endl;
	}
	
	
	cout<<endl<<endl;
	for(int i=0;i<x;i++){
		cout<<"x"<<i+1<<" = "<<X[i]<<endl;
	}
	
	return 0;
}