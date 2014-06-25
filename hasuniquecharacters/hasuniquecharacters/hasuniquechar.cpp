#include<iostream>
#include<cstring>
#include<map>
using namespace std;

bool hasUniquecharacters(char[]);
bool hasUniquecharactersusingmap(char[]);
bool hasUniquecharactersusingloop(char[]);

int main(){
	char a[100];

	cout << "Enter String:";
	cin >> a;


	if (hasUniquecharactersusingloop(a)){
		cout << "has unique characters" << endl;
	}
	else{
		cout << "No, it does not have unique characters" << endl;
	}

	return 0;
}

/*Works for both lower and upper case but time complexicity is O(n^2)*/
bool hasUniquecharactersusingloop(char str[]){
	for (int i = 0; i < strlen(str); i++){
		for (int j = i + 1; j < strlen(str); j++){
			if (str[i] == str[j])return false;
		}
	}
	return true;
}

/*Works for all the cases but uses additional datastructures i.e., map */
bool hasUniquecharactersusingmap(char str[]){
	std::map<char, int>strmap;

	for (int i = 0; i < strlen(str); i++){
		if (strmap.count(str[i]) == 0){
			strmap[str[i]] = 1;
		}
		else return false;
	}
	return true;

}

/*only works for lower case letter*/
bool hasUniquecharacters(char str[]){
	unsigned int x = 0;

	for (int i = 0; i < strlen(str); i++){
		int sift = str[i] - 'a';

		if (1 << sift & x)return false;
		else x |= 1 << sift;
	}
	return true;
}