#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

bool isKeyword(char *tempBuffer[]){
    char keywords[32][10] = {
                            "auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"
                            };

    int i,flag = 0;

    for(i = 0;i<32;++i){

    }
}

bool isOperator(char *operatorsPointer[],char *ch){
    for(int i = 0; operatorsPointer[i] != nullptr; i++){
        if(*ch == operatorsPointer[i])
        {
            return true;
        }
    }
}

void bufferResetter(int *bufferIndex){
    *bufferIndex = 0;
}

int main(){
    char ch;buffer[],operators[]="+-*/%=";

    fstream docFile("program.txt");

    int i,j = 0;

    if(!docFile.is_open()){
        cout<<"Error opening the file\n";
        exit(0);
    }

    while(!docFile.eof()){
        ch = docFile.get();

        if(isOperator(operators,ch) == true){
            bufferResetter(j);
            cout<<ch<<" -> operator";
        }
        else if(isalnum(ch)){
            buffer[j++] = ch;
            //no need to reset the bufferIndex
        }
        else if((ch == " " || ch == "\n") && (j != 0)){
            buffer[j]="\0";// putting null terminator so that string functions work properly

            bufferResetter(j);

            if(isKeyword(buffer) == 1){
                cout<<buffer<<" -> keyword";
            }
            else{
                cout<<buffer<<" -> identifier";
            }
        }
    }
    fclose();
    return 0;
}
