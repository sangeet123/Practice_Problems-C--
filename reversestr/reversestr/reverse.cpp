#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

char* reverse(char[]);
bool test(char[], char[]);


int main(){
	char str1[] = "";
	char str2[] = "a";
	char str3[] = "ab";
	char str4[] = "abc";
	char str5[] = "abcd";
	
	
	assert(test(reverse(str1), ""));
	assert(test(reverse(str2), "a"));
	assert(test(reverse(str3), "ba"));
	assert(test(reverse(str4), "cba"));
	assert(test(reverse(str5), "dcba"));


	return 0;
}
/*Compares the two strings*/
bool test(char org[], char rev[]){
	if (!strcmp(org, rev))return true;
	else return false;
}

/*Reverses the string*/
char* reverse(char str[]){
	for (int i = 0,j = strlen(str)-1; i < j; i++, j--){
		swap(str[i], str[j]);
	}
	return str;
}