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

	const int& new_size = n/2 + n%2;



	Matrix* a00 = new Matrix(new_size);
	Matrix* a01 = new Matrix(new_size);
	Matrix* a10 = new Matrix(new_size);
	Matrix* a11 = new Matrix(new_size);

	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_size; j++) {
			a00->matrix[i][j] = matrix1->matrix[i][j];
			if (j + new_size < n)
				a01->matrix[i][j] = matrix1->matrix[i][j + new_size];
			else
				a01->matrix[i][j] = 0;

			if (i + new_size < n)
				a10->matrix[i][j] = matrix1->matrix[i + new_size][j];
			else
				a10->matrix[i][j] = 0;

			if (i + new_size < n && j + new_size < n)
				a11->matrix[i][j] = matrix1->matrix[i + new_size][j + new_size];
			else
				a11->matrix[i][j] = 0;
		}
	}

	Matrix* b00 = new Matrix(new_size);
	Matrix* b01 = new Matrix(new_size);
	Matrix* b10 = new Matrix(new_size);
	Matrix* b11 = new Matrix(new_size);

	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_size; j++) {
			b00->matrix[i][j] = matrix2->matrix[i][j];
			if (j + new_size < n)
				b01->matrix[i][j] = matrix2->matrix[i][j + new_size];
			else
				b01->matrix[i][j] = 0;

			if (i + new_size < n)
				b10->matrix[i][j] = matrix2->matrix[i + new_size][j];
			else
				b10->matrix[i][j] = 0;

			if (i + new_size < n && j + new_size < n)
				b11->matrix[i][j] = matrix2->matrix[i + new_size][j + new_size];
			else
				b11->matrix[i][j] = 0;
		}
	}

	Matrix* s1 = matrix_subtraction(b01, b11, new_size);
	Matrix* s2 = matrix_addition(a00, a01, new_size);
	Matrix* s3 = matrix_addition(a10, a11, new_size);
	Matrix* s4 = matrix_subtraction(b10, b00, new_size);
	Matrix* s5 = matrix_addition(a00, a11, new_size);
	Matrix* s6 = matrix_addition(b00, b11, new_size);
	Matrix* s7 = matrix_subtraction(a01, a11, new_size);
	Matrix* s8 = matrix_addition(b10, b11, new_size);
	Matrix* s9 = matrix_subtraction(a00, a10, new_size);
	Matrix* s10 = matrix_addition(b00, b01, new_size);

	Matrix* p1 = strassen_multiply(a00, s1, new_size);
	Matrix* p2 = strassen_multiply(s2, b11, new_size);
	Matrix* p3 = strassen_multiply(s3, b00, new_size);
	Matrix* p4 = strassen_multiply(a11, s4, new_size);
	Matrix* p5 = strassen_multiply(s5, s6, new_size);
	Matrix* p6 = strassen_multiply(s7, s8, new_size);
	Matrix* p7 = strassen_multiply(s9, s10, new_size);

	Matrix* c1 = matrix_addition(matrix_subtraction(matrix_addition(p5,p4, new_size),p2, new_size),p6, new_size);
	Matrix* c2 = matrix_addition(p1,p2, new_size);
	Matrix* c3 = matrix_addition(p3, p4, new_size);
	Matrix* c4 = matrix_subtraction(matrix_subtraction(matrix_addition(p5, p1, new_size), p3, new_size), p7, new_size);


	Matrix* result = new Matrix(n);

	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_size; j++) {
			result->matrix[i][j] = c1->matrix[i][j];
			if(j+new_size<n)
				result->matrix[i][j + new_size] = c2->matrix[i][j];
			if(i+new_size<n)
				result->matrix[i + new_size][j] = c3->matrix[i][j];
			if(j + new_size < n && i + new_size < n)
				result->matrix[i + new_size][j + new_size] = c4->matrix[i][j];

		}
	}

	return result;

	delete s1; delete s2; delete s3; delete s4; delete s5; delete s6; delete s7; delete s8; delete s9; delete s10;
	delete p1; delete p2; delete p3; delete p4; delete p5; delete p6; delete p7;
	delete c1; delete c2; delete c3; delete c4;

}