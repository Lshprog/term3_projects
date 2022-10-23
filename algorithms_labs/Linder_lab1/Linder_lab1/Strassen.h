#pragma once
#ifndef STRASSEN_H
#define STRASSEN_H
#include "Matrices.h";

Matrix* create_matrix_random(const int& a, const int& b) {
	Matrix* matrix = new Matrix(a,b);
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			matrix->matrix[i][j] = -10 + (rand() % 21); 
		}
	}
	return matrix;
}

bool compare_matrices(Matrix* matrix1, Matrix* matrix2) {

	if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
		return false;

	for (int i = 0; i< matrix1->rows; i++) {
		for (int j = 0;j< matrix1->columns; j++) {
			if (matrix1->matrix[i][j] != matrix2->matrix[i][j])
				return false;
		}
	}

	return true;
}


bool check_matrices_for_multiply(Matrix* matrix1, Matrix* matrix2) {
	if (matrix1->columns == matrix2->rows)
		return true;
	else
		return false;
}

Matrix* matrix_addition(Matrix* matrix1, Matrix* matrix2) {

	Matrix* matrix = new Matrix(matrix1->rows,matrix1->columns);

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_subtraction(Matrix* matrix1, Matrix* matrix2) {
	
	
	Matrix* matrix = new Matrix(matrix1->rows, matrix1->columns);

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2) {

	const int n = matrix1->columns;

	Matrix* matrix = new Matrix(matrix1->rows,matrix2->columns);

	for (int i = 0; i < matrix1->rows; i++) {
		for (int j = 0; j < matrix2->columns; j++) {
			matrix->matrix[i][j] = 0;
		}
	}

	for (int k = 0; k < matrix1->rows; k++) {
		for (int i = 0; i < matrix2->columns; i++) {
			for (int j = 0; j < n; j++) {
				matrix->matrix[k][i] += matrix1->matrix[k][j] * matrix2->matrix[j][i];
			}
		}
	}

	return matrix;

}


Matrix* strassen_multiply(Matrix* matrix1, Matrix* matrix2) {
	
	const int r = matrix1->rows;
	const int c = matrix2->columns;
	const int n = matrix1->columns;

	if (n<=4 && r<=4 && c<=4) {
		return matrix_multiply(matrix1,matrix2);
	}

	const int new_size = n  /2 + n % 2;
	const int new_r = r / 2 + r % 2;
	const int new_c = c / 2 + c % 2;


	Matrix* a00 = new Matrix(new_r, new_size);
	Matrix* a01 = new Matrix(new_r, new_size);
	Matrix* a10 = new Matrix(new_r, new_size);
	Matrix* a11 = new Matrix(new_r, new_size);

	for (int i = 0; i < new_r; i++) {
		for (int j = 0; j < new_size; j++) {
			a00->matrix[i][j] = matrix1->matrix[i][j];
			if (j + new_size < n)
				a01->matrix[i][j] = matrix1->matrix[i][j + new_size];
			else
				a01->matrix[i][j] = 0;

			if (i + new_r < r)
				a10->matrix[i][j] = matrix1->matrix[i + new_r][j];
			else
				a10->matrix[i][j] = 0;

			if (i + new_r < r && j + new_size < n)
				a11->matrix[i][j] = matrix1->matrix[i + new_r][j + new_size];
			else
				a11->matrix[i][j] = 0;
		}
	}

	Matrix* b00 = new Matrix(new_size, new_c);
	Matrix* b01 = new Matrix(new_size, new_c);
	Matrix* b10 = new Matrix(new_size, new_c);
	Matrix* b11 = new Matrix(new_size, new_c);

	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_c; j++) {
			b00->matrix[i][j] = matrix2->matrix[i][j];
			if (j + new_c < c)
				b01->matrix[i][j] = matrix2->matrix[i][j + new_c];
			else
				b01->matrix[i][j] = 0;

			if (i + new_size < n)
				b10->matrix[i][j] = matrix2->matrix[i + new_size][j];
			else
				b10->matrix[i][j] = 0;

			if (i + new_size < n && j + new_c < c)
				b11->matrix[i][j] = matrix2->matrix[i + new_size][j + new_c];
			else
				b11->matrix[i][j] = 0;
		}
	}

	Matrix* s1 = matrix_subtraction(b01, b11);
	Matrix* s2 = matrix_addition(a00, a01);
	Matrix* s3 = matrix_addition(a10, a11);
	Matrix* s4 = matrix_subtraction(b10, b00);
	Matrix* s5 = matrix_addition(a00, a11);
	Matrix* s6 = matrix_addition(b00, b11);
	Matrix* s7 = matrix_subtraction(a01, a11);
	Matrix* s8 = matrix_addition(b10, b11);
	Matrix* s9 = matrix_subtraction(a00, a10);
	Matrix* s10 = matrix_addition(b00, b01);

	Matrix* p1 = strassen_multiply(a00, s1);
	Matrix* p2 = strassen_multiply(s2, b11);
	Matrix* p3 = strassen_multiply(s3, b00);
	Matrix* p4 = strassen_multiply(a11, s4);
	Matrix* p5 = strassen_multiply(s5, s6);
	Matrix* p6 = strassen_multiply(s7, s8);
	Matrix* p7 = strassen_multiply(s9, s10);

	Matrix* c1 = matrix_addition(matrix_subtraction(matrix_addition(p5,p4),p2),p6);
	Matrix* c2 = matrix_addition(p1,p2);
	Matrix* c3 = matrix_addition(p3, p4);
	Matrix* c4 = matrix_subtraction(matrix_subtraction(matrix_addition(p5, p1), p3), p7);


	Matrix* result = new Matrix(r,c);

	for (int i = 0; i < new_r; i++) {
		for (int j = 0; j < new_c; j++) {
			result->matrix[i][j] = c1->matrix[i][j];
			if(j+new_c < c)
				result->matrix[i][j + new_c] = c2->matrix[i][j];
			if(i+new_r < r)
				result->matrix[i + new_r][j] = c3->matrix[i][j];
			if(j + new_c < c && i + new_r < r)
				result->matrix[i + new_r][j + new_c] = c4->matrix[i][j];

		}
	}

	return result;

	delete s1; delete s2; delete s3; delete s4; delete s5; delete s6; delete s7; delete s8; delete s9; delete s10;
	delete p1; delete p2; delete p3; delete p4; delete p5; delete p6; delete p7;
	delete c1; delete c2; delete c3; delete c4;

}

#endif