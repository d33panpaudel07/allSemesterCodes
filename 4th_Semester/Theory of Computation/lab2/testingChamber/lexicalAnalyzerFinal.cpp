#include<iostream>
#include<fstream>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]){
	char keywords[33][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","endl"};
	int i, flag = 0;
	
	for(i = 0; i < 33; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	return flag;
}

int main(){
	char ch, buffer[15], operators[] = "+-*/%=";
//	ifstream fin("program.txt");
	fstream fin("program.txt",ios::in | ios::out | ios::trunc );`
	
	if(!fin){
		cout<<"Error while opening the file";
		return 1;
	}
	
	//typing the code 
	fin<<"int main(){"<<endl;
	fin<<"		int a = 10;"<<endl;
	fin<<"		int b = 11;"<<endl;
	fin<<"		cout << \"The result is: \" << a + b <<endl;"<<endl;
	fin<<"		return 0;"<<endl;
	fin<<"}"<<endl;		

//	string str1;
//	
//	int a=0;
//	while(str1 != "done"){
//		a++;
//		cout<<"Line "<<a<<": ";
//		cin>>str1;
//		fin<<str1;
//		cout<<endl;
//	}
	
		
	fin.seekg(0);
	
	int i,j=0;
	
	if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
	
	while(!fin.eof()){
   		ch = fin.get();//reads the current character the advance to the next character on the file
   		
		for(i = 0; i < 6; ++i){
   			if(ch == operators[i])
   				cout<<ch<<" is operator\n";
   		}
   		
   		if(isalnum(ch)){ //checks if all characters are alphaNumeic, comes with ctype library
			buffer[j++] = ch; //storing letters of a line in buffer before incrementing j
   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0)){
   				buffer[j] = '\0';//to properly use strcmp we have to use null terminated strings
   				j = 0;//so that next word or line always starts to get stored in buffer from start i.e index 0 
   				   				
   				if(isKeyword(buffer) == 1){
   					cout<<buffer<<" is keyword\n";
				}
   				else{
   					cout<<buffer<<" is indentifier\n";
				}
   		}
   		
	}
	
	fin.close();
	
	return 0;
}