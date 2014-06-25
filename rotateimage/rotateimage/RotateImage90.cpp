#include<iostream>
using namespace std;

void rotateImage(int[][100], int, int, int[][100]);
void inplacerotateImage(int[][100], int, int);
void inplacerotateImage1(int[][100], int, int);
void input(int[][100], int, int);
void output(int[][100], int, int);

int main(){
	int image[100][100];
	int rimage[100][100];
	int r;
	int c;

	cout << "Enter number of rows:";
	cin >> r;
	cout << "Enter number of columns:";
	cin >> c;

	input(image, r, c);

	cout << "Original Image" << endl;
	output(image, r, c);
	
	rotateImage(image, r, c, rimage);
	cout << "After O(n^2) space rotation" << endl;
	output(rimage, r, c);

	inplacerotateImage1(image, r, c);
	cout << "After inplace rotation" << endl;
	output(image, r, c);
	
	return 0;
}

void input(int image[][100], int r, int c){

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> image[i][j];
		}
	}
}

void output(int image[][100], int r, int c){

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << image[i][j] << " ";
		}
		cout << endl;
	}

}

void rotateImage(int image[][100], int r, int c, int rimage[][100]){

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			rimage[j][c - i- 1] = image[i][j];
		}
	}
}

/*Different approach for inplace swapping*/
void inplacerotateImage1(int image[][100], int r, int c){

	if (r != c){
		cout << "Inplace rotate image is not compatible for this case" << endl;;
		return;
	}

	for (int i = 0; i < r / 2; i++){
		
		for (int j = i; j < c - i - 1;j++){
			int ro;
			int co;
			int val;
			int csteps;
			int rsteps;
			int nval;

			for (int ii = 0; ii <= 4; ii++){
				switch (ii){
				case 1://Moving towards right increase the column by c amount
					csteps = (c - 1) - 2 * i;
					co = j + csteps;
					rsteps = co - (c - i - 1);
					co = co - rsteps;
					ro = i + rsteps;
					val = image[ro][co];
					image[ro][co] = image[i][j];
					break;
				case 2://Moving downwards by row amount
					rsteps = (r - 1) - 2 * i;
					ro += rsteps;
					csteps = ro - (r - i - 1);
					ro = ro - csteps;
					co -= csteps;
					nval = image[ro][co];
					image[ro][co] = val;
					val = nval;
					break;
				case 3://Moving left by column amount
					csteps = (c - 1) - 2 * i;
					co -= csteps;
					if (co < i){
						ro = ro - abs((i - co));
						co = i;
					}
					nval = image[ro][co];
					image[ro][co] = val;
					val = nval;
					break;
				case 4: //Moving up by row amount but not necessary to calculate because it will lead to i and j location
					image[i][j] = val;
					break;
				}
			}
		}
	}
}

/*Inplace rotating by exchanging rows and column obtained by seeing patterns */
void inplacerotateImage(int image[][100], int r, int c){
	if (r != c){
		cout << "Inplace rotate image is not compatible for this case" << endl;
		return;
	}

	int row = r;
	int ro;
	int co;
	int temp;
	int temp1;

	for (int i = 0; i < row / 2; i++){
		
		for (int j = i; j < c-i-1; j++){

			for (int ii = 1; ii <= 4; ii++){
				switch (ii){
				case 1: ro = j;
					co = c - i - 1;
					temp = image[ro][co];
					image[ro][co] = image[i][j];
					break;
				case 2:temp1 = ro;
					ro = co;
					co = c - temp1 - 1;
					temp1 = image[ro][co];
					image[ro][co] = temp;
					temp = temp1;
					break;
				case 3:temp1 = image[co][i];
					image[co][i] = temp;
					temp = temp1;
					break;
				case 4:
					image[i][j] = temp;
					break;
			}
			}
		}

	}

}