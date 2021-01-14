#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include<math.h>
using namespace std;
double determinant(double matrix1[100][100], int r1, int c1);
int main() {
    int flag1 = 0;
	string inputmatrix1;
	getline(cin, inputmatrix1);
	string OP;
	getline(cin, OP);

	int spaces = 0;
	int flag = 0;

	int k1 = inputmatrix1.length() - 1;

	double matrix1[100][100];
	for (int o1 = 0; o1 < 100; o1++) {
		for (int o2 = 0; o2 < 100; o2++) {
			matrix1[o1][o2] = 0;
		}
	}
	for (int k = 0; k <= k1; k++)
	{
		if (inputmatrix1[k] == ' ')
			spaces++;
		else if (inputmatrix1[k] == ';' && flag == 0) {
			spaces++;
			flag = spaces;
		}
		else if (inputmatrix1[k] == ';' || inputmatrix1[k] == ']') {
			spaces++;
			if (spaces % flag != 0 && flag != 0)
				break;
		}

	}
	if (spaces % flag != 0)
		cout << "ERROR";

	else {

		inputmatrix1.erase(0, 1);
		int n1 = inputmatrix1.length() - 1;
		int count1 = 0;

		int row1;
		int column1;
		double v1 = 0;
		string s1;

		// cut and convert the first matrix
		for (row1 = 0; row1 < 100; row1++)
		{
			for (column1 = 0; column1 < 100; column1++)
			{
				for (int N1 = 0; N1 < n1; N1++)
				{

					if (inputmatrix1[count1] == ' ') {
						s1 = inputmatrix1.substr(count1 - N1, N1);
						v1 = atof(s1.c_str());
						count1++;
						break;
					}
					else if (inputmatrix1[count1] == ';' || inputmatrix1[count1] == ']') {
						s1 = inputmatrix1.substr(count1 - N1, N1);
						v1 = atof(s1.c_str());
						break;
					}

					else if (inputmatrix1[count1] == '.') {
						int c1 = count1 + 1;
						int P1 = 0;
						while (P1 < n1)
						{

							if (inputmatrix1[c1] == ' ')
							{
								s1 = inputmatrix1.substr(count1 - N1, count1 - (count1 - N1) + P1 + 1);
								v1 = atof(s1.c_str());
								count1 = c1 + 1;
								break;
							}
							else if (inputmatrix1[c1] == ']' || inputmatrix1[c1] == ';') {
								s1 = inputmatrix1.substr(count1 - N1, count1 - (count1 - N1) + P1 + 1);
								v1 = atof(s1.c_str());
								count1 = c1;
								break;
							}
							else {
								c1++;
								P1++;
							}
						}

						break;
					}
					else if (inputmatrix1[count1] == ']' && inputmatrix1[count1] == ';')
						break;
					else
						count1++;

				}
				matrix1[row1][column1] = v1;
				if (inputmatrix1[count1] == ';') {
					count1++;

					break;
				}


				if (count1 == n1)
					break;



			}
			if (inputmatrix1[count1] == ']')

				break;

		}
		int semi1 = 0;
		int space1 = 0;

		for (int index1 = 0; index1 < k1; index1++) {
			if (inputmatrix1[index1] == ';')
				semi1++;
			else if (inputmatrix1[index1] == ' ')
				space1++;
		}

		int c1 = (space1 / (semi1 + 1)) + 1;
		int r1 = semi1 + 1;
		if (OP[0] == '^') {

			if (c1 != r1) {
				cout << "ERROR";
			}
			else {
                int power;
                cin >> power;
				double multiply[100][100];
				for (int o1 = 0; o1 < 100; o1++) {
					for (int o2 = 0; o2 < 100; o2++) {
						multiply[o1][o2] = 0;
					}
				}

				double multiply1[100][100];

				for (int I = 0; I < r1; I++) {

					for (int J = 0; J < c1; J++) {
						for (int mult = 0; mult < c1; mult++) {
							multiply[I][J] += matrix1[I][mult] * matrix1[mult][J];

						}
					}
				}
				if (power == 2){
                    cout << '[';
				for (int i = 0; i < r1; i++) {

					for (int j = 0; j < c1; j++)
					{

						cout << multiply[i][j];

						if (j != (space1 / (semi1 + 1)))
							cout << " ";
					}

					if (i != semi1)
						cout << ';';
					else
						cout << ']';

				}
				}
				else{
				for (int index = 0; index < power - 2; index++) {

					for (int o1 = 0; o1 < 100; o1++) {
						for (int o2 = 0; o2 < 100; o2++) {
							multiply1[o1][o2] = 0;
						}
					}
					for (int I = 0; I < r1; I++) {

						for (int J = 0; J < c1; J++) {

							for (int mult = 0; mult < c1; mult++) {
								multiply1[I][J] += multiply[I][mult] * matrix1[mult][J];

							}
						}
					}
					for (int i = 0; i < r1; i++) {
						for (int j = 0; j < c1; j++) {
							multiply[i][j] = multiply1[i][j];
						}
					}
				}
				cout << '[';
				for (int i = 0; i < r1; i++) {

					for (int j = 0; j < c1; j++)
					{

						cout << multiply1[i][j];

						if (j != (space1 / (semi1 + 1)))
							cout << " ";
					}

					if (i != semi1)
						cout << ';';
					else
						cout << ']';

				}
			}
			}
		}

		else if (OP[0] == 'T') {
			double matrixT[100][100];
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c1; j++) {
					matrixT[j][i] = matrix1[i][j];
				}
			}
			cout << '[';
			for (int i = 0; i < c1; i++) {

				for (int j = 0; j < r1; j++)
				{

					cout << matrixT[i][j];

					if (j != (semi1))
						cout << " ";
				}

				if (i != (space1 / (semi1 + 1)))
					cout << ';';
				else
					cout << ']';

			}
		}
		else if(OP[0] == 'D'){
                if (r1 != c1)
                cout <<"ERROR";
                else{
                        cout << determinant(matrix1, r1, c1);
                }
		}
		else if (OP[0] == 'I'){
                double matrixI [100][100];
             if (r1 != c1)
                cout <<"ERROR";
                else {
                    double D = determinant(matrix1, r1, c1);
                    if (D == 0)
                        cout << "ERROR";
                    else{
                        if (r1 == 2){
                            matrixI[0][0] = matrix1[1][1];
                            matrixI[1][1] = matrix1[0][0];
                            matrixI[0][1] = -1 * matrix1[0][1];
                            matrixI[1][0] = -1 * matrix1[1][0];
                            for (int i = 0; i < r1; i++){
                                for (int j = 0; j < r1; j++){
                                    matrixI[i][j] = (1/D) * matrixI[i][j];
                                }
                            }
                            cout << '[';
			for (int i = 0; i < r1; i++) {

				for (int j = 0; j < r1; j++)
				{

					cout << matrixI[i][j];

					if (j != (semi1))
						cout << " ";
				}

				if (i != (space1 / (semi1 + 1)))
					cout << ';';
				else
					cout << ']';

			}
                        }
                        else if(r1 == 3){
                            double matrixT[100][100];
                           double matrixD[100][100];
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c1; j++) {
					matrixT[j][i] = matrix1[i][j];
				}
			}
			int c1 = 0;
			int c2 = 0;
			double d2;
			double mat3[100][100];
			int n = 0;
			for(int I = 0; I < r1; I++){
                    for (int J = 0; J < r1; J++){
			for (int i = 0; i < r1  ; i++){
                        for (int j = 0; j < r1 ; j++){
                            if (i == I || j == J)
                            continue;
                                else{
                                    mat3[c1][c2] = matrixT[i][j];
                                    c2++;
                                }
                            }
                            if (i == I)
                                continue;
                            else{
                                c1++;
                                c2 = 0;
                            }
                        }
                        c2 =0;
                        c1 = 0;

                        d2 = (mat3[0][0] * mat3[1][1]) - (mat3[0][1] * mat3[1][0]);

                        matrixD[I][J] = d2 * pow(-1 , n);
                        n++;
                    }
			}
                    for(int i =0; i < r1; i++){
                        for (int j = 0; j < r1; j++){
                            matrixD[i][j] = (1/D) * matrixD[i][j];
                        }
                    }
                        cout << '[';
			for (int i = 0; i < r1; i++) {

				for (int j = 0; j < r1; j++)
				{

					cout << matrixD[i][j];

					if (j != (semi1))
						cout << " ";
				}

				if (i != (space1 / (semi1 + 1)))
					cout << ';';
				else
					cout << ']';

			}

                        }
                        if (r1 > 3){
                            double matrixD[100][100];
                            int c1 = 0;
			int c2 = 0;
			double d2;
			double mat3[100][100];

			for(int I = 0; I < r1; I++){
                    for (int J = 0; J < r1; J++){
			for (int i = 0; i < r1  ; i++){
                        for (int j = 0; j < r1 ; j++){
                            if (i == I || j == J)
                            continue;
                                else{
                                    mat3[c1][c2] = matrix1[i][j];
                                    c2++;
                                }
                            }
                            if (i == I)
                                continue;
                            else{
                                c1++;
                                c2 = 0;
                            }
                        }
                        c2 =0;
                        c1 = 0;

                        d2 = determinant(mat3,r1-1,r1-1);

                        matrixD[I][J] = d2 * pow(-1 , I+J);

                    }

			}
                    for(int i =0; i < r1; i++){
                        for (int j = 0; j < r1; j++){
                            matrixD[i][j] = (1/D) * matrixD[i][j];
                        }
                    }
                        cout << '[';
			for (int i = 0; i < r1; i++) {

				for (int j = 0; j < r1; j++)
				{

					cout << matrixD[i][j];

					if (j != (semi1))
						cout << " ";
				}

				if (i != (space1 / (semi1 + 1)))
					cout << ';';
				else
					cout << ']';

			}
                        }


                    }
                }
		}


	}

}
double determinant(double matrix1[100][100], int r1, int c1){
double X;
double mat[100][100];
for(int l = 0; l <r1; l++){
    for(int m = 0; m<r1; m++){
        mat[l][m] = matrix1[l][m];
    }
}
                        for(int i = 0; i <r1; i++){
                            for(int j = 0; j<r1; j++){
                               if(i == j){
                                for(int k = 0; k<j; k++){
                                    if(mat[i][k] != 0){
                                            if(mat[i-1][k] != 0){
                                         X = mat[i][k] / mat[i-1][k];
                                         for(int N = 0; N < r1; N++){
                                            mat[i][N] -= mat[i-1][N] * X;
                                        }
                                            }
                                            else{
                                           for(int G = 1; G < r1; G++){
                                            if(mat[i -G][k] == 0)
                                                continue;
                                            else{
                                                X = mat[i][k] / mat[i-G][k];
                                                for(int N = 0; N < r1; N++){
                                            mat[i][N] -= mat[i-G][N] * X;
                                        }
                                                break;
                                            }
                                           }

                                            }

                                    }
                                }
                               }
                            }
                        }
                        double det = 1;
                        int F = 0;
                        for(int i = 0; i<r1; i++){
                            for(int j = 0; j<r1; j++){
                                if(i == j && mat[i][j] != 0){
                                    det *= mat[i][j];
                                }
                                else if(mat[i][j] == 0 && i == j){
                                        F = 1;
                                return 0;

                                }
                            }
                            if (F == 1)
                                break;
                        }
                        if(F == 0)
                        return det;
		}

