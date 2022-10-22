#pragma once
#include "Matrices.h";


Matrix* matrix_addition(Matrix* matrix1, Matrix* matrix2, const int &n) {

	Matrix* matrix = new Matrix(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_subtraction(Matrix* matrix1, Matrix* matrix2, const int& n) {

	Matrix* matrix = new Matrix(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2, const int& n) {

	Matrix* matrix = new Matrix(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix->matrix[i][j] = 0;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix->matrix[k][i] += matrix1->matrix[k][j] * matrix2->matrix[j][i];
			}
		}
	}

	return matrix;

}


Matrix* strassen_multiply(Matrix* matrix1, Matrix* matrix2, const int& n) {

	if (n<=4) {
		return matrix_multiply(matrix1,matrix2,n);
	}

	Matrix* a00 = new Matrix(n / 2);
	Matrix* a01 = new Matrix(n / 2);
	Matrix* a10 = new Matrix(n / 2);
	Matrix* a11 = new Matrix(n / 2);

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			a00->matrix[i][j] = matrix1->matrix[i][j];
			a01->matrix[i][j] = matrix1->matrix[i][j + n / 2];
			a10->matrix[i][j] = matrix1->matrix[i + n / 2][j];
			a11->matrix[i][j] = matrix1->matrix[i + n/2][j + n / 2];
		}
	}

	Matrix* b00 = new Matrix(n / 2);
	Matrix* b01 = new Matrix(n / 2);
	Matrix* b10 = new Matrix(n / 2);
	Matrix* b11 = new Matrix(n / 2);

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			b00->matrix[i][j] = matrix2->matrix[i][j];
			b01->matrix[i][j] = matrix2->matrix[i][j + n / 2];
			b10->matrix[i][j] = matrix2->matrix[i + n / 2][j];
			b11->matrix[i][j] = matrix2->matrix[i + n/2][j + n / 2];
		}
	}

	Matrix* s1 = matrix_subtraction(b01, b11, n / 2);
	Matrix* s2 = matrix_addition(a00, a01, n / 2);
	Matrix* s3 = matrix_addition(a10, a11, n / 2);
	Matrix* s4 = matrix_subtraction(b10, b00, n / 2);
	Matrix* s5 = matrix_addition(a00, a11, n / 2);
	Matrix* s6 = matrix_addition(b00, b11, n / 2);
	Matrix* s7 = matrix_subtraction(a01, a11, n / 2);
	Matrix* s8 = matrix_addition(b10, b11, n / 2);
	Matrix* s9 = matrix_subtraction(a00, a10, n / 2);
	Matrix* s10 = matrix_addition(b00, b01, n / 2);

	Matrix* p1 = strassen_multiply(a00, s1, n / 2);
	Matrix* p2 = strassen_multiply(s2, b11, n / 2);
	Matrix* p3 = strassen_multiply(s3, b00, n / 2);
	Matrix* p4 = strassen_multiply(a11, s4, n / 2);
	Matrix* p5 = strassen_multiply(s5, s6, n / 2);
	Matrix* p6 = strassen_multiply(s7, s8, n / 2);
	Matrix* p7 = strassen_multiply(s9, s10, n / 2);

	Matrix* c1 = matrix_addition(matrix_subtraction(matrix_addition(p5,p4,n/2),p2,n/2),p6,n/2);
	Matrix* c2 = matrix_addition(p1,p2,n/2);
	Matrix* c3 = matrix_addition(p3, p4, n / 2);
	Matrix* c4 = matrix_subtraction(matrix_subtraction(matrix_addition(p5, p1, n / 2), p3, n / 2), p7, n / 2);


	Matrix* result = new Matrix(n);

	for (int i = 0; i < n/2; i++) {
		for (int j = 0; j < n/2; j++) {
			result->matrix[i][j] = c1->matrix[i][j];
			result->matrix[i][j + n / 2] = c2->matrix[i][j];
			result->matrix[i + n / 2][j] = c3->matrix[i][j];
			result->matrix[i + n / 2][j + n / 2] = c4->matrix[i][j];

		}
	}

	return result;

	delete s1; delete s2; delete s3; delete s4; delete s5; delete s6; delete s7; delete s8; delete s9; delete s10;
	delete p1; delete p2; delete p3; delete p4; delete p5; delete p6; delete p7;
	delete c1; delete c2; delete c3; delete c4;

}