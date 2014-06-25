#include<iostream>
using namespace std;

void input(int[][100], int, int);
void initialize(int*, int);
void output(int[][100], int, int);
void adjustMatrix(int[][100], int, int);
void adjustMatrix1(int[][100], int, int);

int main(){
	int boolmatrix[100][100];
	int r;
	int c;

	cout << "Enter the row of the matrix:" << endl;
	cin >> r;
	cout << "Enter the column of the matrix" << endl;
	cin >> c;
	input(boolmatrix, r, c);

	cout << "Before adjusting matrix" << endl;
	output(boolmatrix, r, c);
	adjustMatrix1(boolmatrix, r, c);
	cout << "After adjusting matrix" << endl;
	output(boolmatrix, r, c);
}


void input(int boolmatrix[][100], int r, int c){
	int data;

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> data;
			while(data != 0 && data != 1){
				cout<<"Enter correct data: either 0 or 1" << endl;
				cin >> data;
			}
			boolmatrix[i][j] = data;
		}
	}
}

/*Initializing the vector p*/
void initialize(int *p, int size){
	for (int i = 0; i < size; i++)
		p[i] = 0;
}

/*Printing the Matrix*/
void output(int boolimage[][100], int r, int c){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << boolimage[i][j] << " ";
		}
		cout << endl;
	}
}

void adjustMatrix1(int boolmatrix[][100], int r, int c){
	int setrow = 0;
	int setcol = 0;

	for (int i = 0; i < r; i++)
		if (boolmatrix[i][0])setcol = 1;

	for (int i = 0; i < c; i++)
		if (boolmatrix[0][i])setrow = 1;

	for (int i = 1; i < r; i++){
		for (int j = 1; j < c; j++){
			if (boolmatrix[i][j]){
				boolmatrix[i][0] = 1;
				boolmatrix[0][j] = 1;
			}
		}
	}



	for (int i = 1; i < r; i++){
		for (int j = 1; j < c; j++){
			if (boolmatrix[i][0] || boolmatrix[0][j]){
				boolmatrix[i][j] = 1;
			}
		}
	}

	if (setrow){
		for (int i = 0; i < c; i++){
			boolmatrix[0][i] = 1;
		}
	}
	if (setcol){
		for (int i = 0; i < c; i++){
			boolmatrix[i][0] = 1;
		}
	}
	
}		

void adjustMatrix(int boolmatrix[][100], int r, int c){
	int *trmatrix = new int[r];
	int *tcmatrix = new int[c];

	initialize(trmatrix, r);
	initialize(tcmatrix, c);

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (boolmatrix[i][j]){
				trmatrix[i] = 1;
				tcmatrix[j] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (trmatrix[i] || tcmatrix[j]){
				boolmatrix[i][j] = 1;
			}
		}
	}
}