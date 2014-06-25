#include<iostream>
using namespace std;

char* compress(char[]);
int digitcount(int);
char* performcompression(char[]);

int main(){
	char str[100];
	char *p;

	cout << "Enter String:";
	cin >> str;

	p = compress(str);

	cout << p << endl;
}

/*Main Method that calls the compression Function
*/
char* compress(char str[]){
	int len = strlen(str);
	int count = 0;
	int compresslen = 0;

	for (int i = 0; i < len; i++){
		if ((i+1<len) && str[i] == str[i + 1]){
			count++;
		}else{
			count++;
			compresslen += digitcount(count) + 1;
			count = 0;
		}
	}

	cout << "length=" << len << "  compresslen=" << compresslen << endl;
	if (compresslen >= len){
		cout << "Returning original String" << endl;
		return str;
	}
	else{
		cout << "Performing Compression" << endl;
		return(performcompression(str));
	}

}

/*Thsi method performs the compression*/
char* performcompression(char str[]){
	int len = strlen(str);
	char *compresstr = new char[len];
	char buf[10];//Assuming that total count of contiguous character would not be larger than 10 digits

	int count = 0;
	int j = 0;

	for (int i = 0; i < len; i++){
		if ((i + 1 < len) && str[i] == str[i + 1]){
			count++;
		}else{
			count++;
			compresstr[j] = str[i];
			compresstr[j + 1] = '\0';
			_itoa_s(count, buf, 10);
			strcat_s(compresstr,len,buf);
			j = strlen(compresstr);
			count = 0;
		}
	}

	return compresstr;

}

/*Count the total number of digits present in a number*/
int digitcount(int count){
	if (count/10==0)return 1;
	else return(1 + digitcount(count % 10));
}