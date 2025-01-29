/*
length() / size()

empty()		//checks if string is empty

clear()		//clears content of a string

append("string") 	//appends string to end of string

insert(index,"character/string")	//inserts on a specific index

erase(startingIndex,numberOfCharacters)		//erases a substring from a string

substr(startingIndex,numberOfCharacters) 	//returns a substring from a string

find("key") 	//searches for the key in the string

replace(startingIndex,numberOfCharacters,"String")		//replaces a string from index to number of characters from a given string

compare("String to compare to") 	str2.compare(str1)		//not case sensitive //0 if same //-1 if diffrent

c_str() //returns a sequence of characters of a string until '\0' is found
//string str = "Hello\0hehe";
//const char* cstr = str.c_str();
//cout<<cstr;
//result : Hello //hehe is not printed 

push_back()		//appends a character to the end of a string

pop_back()		//removes a character from the end of a string
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
	string str = "Hello\0hehe";
	const char* cstr = str.c_str();

	cout<<cstr;

}