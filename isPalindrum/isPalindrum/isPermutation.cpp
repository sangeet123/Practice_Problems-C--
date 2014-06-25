#include<iostream>
#include<random>
#include<time.h>
#include<map>
using namespace std;

bool isPermutation(char*,char*);//uses quick sort and changes the original string
bool isPermutation1(char*, char*);//uses constant space but does not work for unicode character
bool isPermutation2(char*, char*);//uses has map
void qsort(char*, int, int);//my own implementation of quick sort
void swap(char&, char&);//swap two characters
int compare(const void*, const void*);//compare function for library implementation of quick sort
int genrandom(int, int);//generates random numbers in the range of two integers given by the parameters

int main(){
	char str1[100]="";
	char str2[100]="";

	cout << "Enter first string:";
	cin >> str1;
	cout << "Enter second string:";
	cin >> str2;

	if (isPermutation2(str1,str2)){
		cout << "Yes they are permutation of each other" << endl;
	}else{
		cout << "No, they are not permutation of each other" << endl;
	}

	return 0;
}

/*complexicity 2nlog(n)+n; Using qsort approach */
bool isPermutation(char *str1, char *str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 == len2){
		srand(time(NULL));
		//qsort(str1,len1,sizeof(char),compare);//qsort implementation provided by c++
		//qsort(str2,len2,sizeof(char),compare);
		qsort(str1, 0, len1 - 1);
		qsort(str2, 0, len2 - 1);
		if (!strcmp(str1, str2))return true;
	}

	return false;
}

/*My own implementation of qsort; using randomized partition*/
void qsort(char *str, int l, int r){

	if (l < r){
		int x = genrandom(l, r);
		swap(str[x], str[r]);
		char pivot = str[r];
		int i = l - 1;
		int j = l;

		while (j < r){
			if (str[j] < pivot){
				swap(str[i + 1], str[j]);
				i++;
			}
			j++;
		}
		swap(str[i + 1], str[r]);
		qsort(str, l, i);
		qsort(str, i + 2, r);
	}

}

/*Swaps two characters*/
void swap(char& a, char &b){
	char temp = a;
	a = b;
	b = temp;
}

/*compares two variables a and b*/
int compare(const void *a, const void *b){

	return(*(char*)a - *(char*)b);
}

/*Generates random numbers in between l and h*/
int genrandom(int l, int h){
	int x = rand() % (h - l);
	return l + x;
}

/*Initialize the count array to zeroes*/
void initialize(int count[], int size){

	for (int i = 0; i < size; i++)
		count[i] = 0;
}

/*returns true if every array elements is zero else return false*/
bool iscountzero(int count[], int size){
	for (int i = 0; i < size; i++){
		if (count[i]!=0)return false;
	}
	return true;
}

/*using additional datastructures i.e., hasmap Time complexicity O(n)*/
bool isPermutation2(char* str1, char* str2){
	
	if (strlen(str1) != strlen(str2))return false;
	
	map<char, int> strmap;


	for (int i = 0; i < strlen(str1); i++){
		if (strmap.count(str1[i]) > 0){
			strmap[str1[i]]++;
		}
		else{
			strmap[str1[i]] = 1;
		}
	}

	for (int i = 0; i < strlen(str2); i++){
		if (strmap.count(str2[i]) > 0){
			strmap[str2[i]]--;
			if (strmap[str2[i]] == 0)strmap.erase(str2[i]);
		}
		else{
			return false;
		}
	}

	return true;
}


/*using O(n)~2(n+256) complexicity with constant space */
bool isPermutation1(char* str1, char* str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int count[256];

	initialize(count,256);

	if (len1 == len2){
		for (int i = 0; i < len1; i++){
			count[str1[i] - 0]++;
		}

		for (int i = 0; i < len2; i++){
			count[str2[i] - 0]--;
		}
		return(iscountzero(count, 256));

	}
	
	return false;
}