#pragma once

struct Matrix {

	int n;
	double** matrix;

	Matrix(const int n) {
		this->n = n;
		matrix = new double* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new double[n];
		}


	}

	~Matrix() {
		for (int i = 0; i < n; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;

	}

};

