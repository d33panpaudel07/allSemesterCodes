#include<iostream>
#include<cmath>
using namespace std;

class Lagrange{
	private:
		float x[6]={1,2,5,8,10,12};
		float fx[6]={0.841,1.600,0.65,3.068,3.144,1.94}; 
		float c=8.35;//c is the value of x
		float y;
	public:
		Lagrange(){
			cout<<"Initial values are: "<<endl
				<<"X : ";
			for(int i=0;i<6;i++){
				cout<<x[i]<<", ";
			}
			cout<<endl<<"Y : ";
			for(int i=0;i<6;i++){
				cout<<fx[i]<<", ";
			}
		}
		float partCalculator(int fxn=0){
			float result;
			float upperPart=1;
			for(int i=0;i<6;i++){
				if(fxn==i){
					continue;
				}else{
					upperPart*=(c-x[i]);
				}
			}
			cout<<endl<<endl<<"Upper value of part"<<fxn+1<<": "<<upperPart;
			float lowerPart=1;
			for(int i=0;i<6;i++){
				if(fxn==i){
					continue;
				}else{
					lowerPart*=(x[fxn]-x[i]);
				}
			}
			cout<<endl<<"Lower value of part"<<fxn+1<<": "<<lowerPart;
			cout<<endl<<"fx[fxn] of part"<<fxn+1<<": "<<fx[fxn];
			return result=fx[fxn]*upperPart/lowerPart;
		}
};

int main(){
	Lagrange l1;
	int uIn;
	cout<<endl<<"Enter max length of data: ";
	cin>>uIn;
	float fValue=0;
	for(int i=0;i<uIn;i++){
		fValue+=l1.partCalculator(i);
	}
	cout<<endl<<"Final value is: "<<fValue;
}