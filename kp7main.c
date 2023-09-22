#include "matrix.h"

int main(int argc, char* argv[]) {

	FILE* input = fopen(argv[1], "r");
	if (!input) { 
        printf("Не удалось открыть файл!\n");
        exit(1);
    }

    matrix* spmatrix = NULL;
    spmatrix = matrix_create(spmatrix);

    spmatrix = get_matrix(input, spmatrix);

    spmatrix_print(spmatrix);

    matrix_free(spmatrix);

    fclose(input);

    return 0;
}