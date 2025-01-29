/*
TODOs
	Look for keywords,tokens,spaces,commas,(,),{,},endOfLine
*/

#include<iostream>
using namespace std;

class lexicalAnalyzer{
	private:
		int numberOfTokens = 0;
//		string demo = "cout << \"Testing string\"";	
		
	public:
//		void check
		
		void checkString(string *demo){
			for (int i = 0; i < demo->length(); i++) {
				cout << (*demo)[i];

				if((*demo)[i] == '"'){
					while((*demo)[i+1] != '"'){
						i++;
					}
					cout << " [string] ";
				}
				
				// Check for spaces
				else if ((*demo)[i] == ' ') {
					cout << " [space] ";
				}

				// Check for commas
				else if ((*demo)[i] == ',') {
					cout << " [comma] ";
				}

				// Check for parentheses
				else if ((*demo)[i] == '(' || (*demo)[i] == ')') {
					cout << " [parenthesis] ";
				}

				// Check for curly braces
				else if ((*demo)[i] == '{' || (*demo)[i] == '}') {
					cout << " [curly brace] ";
				}

				// Check for end of line
				else if ((*demo)[i] == '\n') {
					cout << " [end of line] ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
};

int main(){
	lexicalAnalyzer l1;
	string demoo = "cout<<\"Testing string\"";
	l1.checkString(&demoo);
}
