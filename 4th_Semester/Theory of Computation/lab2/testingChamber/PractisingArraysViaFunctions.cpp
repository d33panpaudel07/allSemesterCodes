/*
TODOs
	Look for keywords,tokens,spaces,commas,(,),{,},endOfLine
*/

#include<iostream>
using namespace std;

class lexicalAnalyzer{
	private:
		int numberOfTokens = 0;
//		string demo = "cout<<\"Testing string\"";	
		
	public:
//		void check
		
		void checkString(string *demo1){
			
			demo1->append(" modified string");
			
			for(int i=0;i<demo1->length();i++){
				cout<<(*demo1)[i];
			}
			cout<<endl<<"Which is it"<<endl;
				
		}
};

int main(){
	lexicalAnalyzer l1;
	string demoo = "cout<<\"Testing string\"";
	l1.checkString(&demoo);
	
	for(int i=0;i<demoo.length();i++){
		cout<<demoo[i];
	}
}
