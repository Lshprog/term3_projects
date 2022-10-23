#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h";
#include "Strassen.h"
#include "Functionality_matrices.h"
#include "Reversedmatrix_minors.h"

#include <time.h>

TEST_CASE("testing strassen`s algorithm") {

	std::clock_t start;
	std::clock_t finish;

	for (int i = 2048; i < 2049; i += 2) {
		Matrix* matrix1 = create_matrix_random(i-1,i);
		Matrix* matrix2 = create_matrix_random(i,i+1);

		start = clock();
		Matrix* not_strassen = matrix_multiply(matrix1,matrix2);
		//not_strassen->print();
		finish = clock();
		std::cout << " Regular algorithm : " << std::endl;
		std::cout << " >>>Start : " << start <<"ms" << std::endl;
		std::cout << " >>>Finish : " << finish << "ms" << std::endl;
		std::cout << " >>>Time taken : " << finish - start << "ms" << std::endl;
		std::cout << std::endl;

		start = clock();
		Matrix* strassen = strassen_multiply(matrix1,matrix2);
		//strassen->print();
		finish = clock();

		std::cout << " Strassen`s algorithm : " << std::endl;
		std::cout << " >>>Start : " << start << "ms" <<std::endl;
		std::cout << " >>>Finish : " << finish << "ms" << std::endl;
		std::cout << " >>>Time taken : " << finish - start << "ms"  << std::endl;
		std::cout<< std::endl;

		bool result = compare_matrices(not_strassen, strassen);

		delete matrix1;
		delete matrix2;
		delete not_strassen;
		delete strassen;

		CHECK(result);
	}


}



TEST_CASE("Test 2") {
	
	for (int n = 3; n < 7; n++) {

		Matrix* matrix = create_matrix_random(n, n);

		std::cout << "Matrix:" << std::endl;
		matrix->print();
		std::cout << "\nMatrix determinant: " << matrix_det(matrix, n) << std::endl;
		std::cout << "\nReversed matrix:\n";

		Matrix* reversed = reverse_matrix(matrix, n);
		reversed->print();

		delete matrix;
		delete reversed;

	}
	
}