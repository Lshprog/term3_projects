#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h";

#include "Strassen.h"


#include <time.h>

TEST_CASE("testing strassen`s algorithm") {

	std::clock_t start;
	std::clock_t finish;

	for (int i = 11; i < 30; i += 2) {
		Matrix* matrix1 = create_matrix_random(i-1,i);
		Matrix* matrix2 = create_matrix_random(i,i+1);

		start = clock();
		Matrix* not_strassen = matrix_multiply(matrix1,matrix2);
		not_strassen->print();
		finish = clock();

		std::cout << " >>>Start : " << start << std::endl;
		std::cout << " >>>Finish : " << finish << std::endl;
		std::cout << " >>>Time taken : " << finish - start << std::endl;

		start = clock();
		Matrix* strassen = strassen_multiply(matrix1,matrix2);
		strassen->print();
		finish = clock();

		std::cout << " >>>Start : " << start <<std::endl;
		std::cout << " >>>Finish : " << finish << std::endl;
		std::cout << " >>>Time taken : " << finish - start << std::endl;

		bool result = compare_matrices(not_strassen, strassen);
		CHECK(result);
	}



}