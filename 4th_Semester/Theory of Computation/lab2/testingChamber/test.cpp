#include<iostream>
#include<string.h>
#include<fstream>
#include<ctype.h>
using namespace std;

int isKeyword(char buffer[]){
	char keywords[33][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","endl"};
							
	int i, flag = 0;
	
	for(i = 0;i < 32; ++i)
	{
		if(strcmp(keywords[i],buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main(){
	
}