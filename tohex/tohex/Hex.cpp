#include<cmath>
#include<stdio.h>
#include<iostream>

using namespace std;

/*Helper Function for converting to Hexadecimal number*/
void Tohex(unsigned long int data, char *hex, int i){
	char buf[3];
	if (data == 0){
		_itoa_s(0, buf, 10);
		strcat_s(hex,20,buf);
		return;
	}

	int rem = data % 16;

	if (rem > 9){
		switch (rem){
		case 10:strcat_s(hex, 19,"a");
			break;
		case 11:strcat_s(hex, 19, "b");
			break;
		case 12:strcat_s(hex, 19, "c");
			break;
		case 13:strcat_s(hex, 19, "d");
			break;
		case 14:strcat_s(hex, 19, "e");
			break;
		case 15:strcat_s(hex, 19, "f");
			break;
		}
	}
	else{
		_itoa_s(rem, buf, 10);
		strcat_s(hex, 19, buf);
	}

	data /= 16;
	if (data > 0){
		Tohex(data, hex, i + 1);
	}
}

/*Conversion to hexadecimal*/
char* convertToHex(long int data){
	char *hex = new char[20];
	hex[0] = '\0';
	unsigned long int lint = _Pow_int(2, 32);
	unsigned long ldata;

	if (data < 0){
		ldata = lint - abs(data);
	}
	else{
		ldata = data;
	}

	Tohex(ldata, hex, 0);
	_strrev(hex);

	puts(hex);
	
	return hex;

}

/* Finding the Checksum */
char* calculatechecksum(char *q){
	long int sum = 0;
	for (size_t i = 0; i < strlen(q); i++){
		sum += q[i];
	}
	return(convertToHex(sum));

}

int main(){

	char *q = convertToHex(-150);

	char *csum=calculatechecksum("621cffffff6a");

	return 0;
}