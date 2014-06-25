#include<iostream>
using namespace std;

void replacespace(char[]);
int countspaces(char[]);

int main(){
	char a[100];

	cout << "Enter String:";
	fgets(a, 100, stdin);
	a[strlen(a)-1] = '\0';//fgets pust additional newline characters at the end

	replacespace(a);
	puts(a);
	return 0;
}

/*This method replaces all the spaces of string str with %20 */
void replacespace(char str[]){

	int count = countspaces(str);
	if (count == 0)return;
	int end = count * 2 + strlen(str);

	str[end--] = '\0';//ending the string with null terminated characters

	for (int i = strlen(str) - 1; i >= 0; i--){
		if (str[i] == ' '){
			str[end--] = '0';
			str[end--] = '2';
			str[end--] = '%';
		}
		else{
			str[end--] = str[i];
		}
	}
}

int countspaces(char str[]){
	int count = 0;

	for (int i = 0; i < strlen(str); i++){
		if (str[i] == ' ')count++;
	}
	cout << count << endl;
	return count;
}