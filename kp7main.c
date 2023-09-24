#include "matrix.h"

int main(int argc, char* argv[]) {

	FILE* input = fopen(argv[1], "r");
	if (!input) { 
        printf("Не удалось открыть файл!\n");
        exit(1);
    }

    matrix* spmatrix = NULL;
    spmatrix = matrix_create(spmatrix);
    int value = 0, m = 0, n = 0, indrow = 0, indcol = 0;
    fscanf(input, "%d %d", &m, &n);
    while (!feof(input)) {
        if(!fscanf(input, "%d", &value)) {
            printf("Некорректные данные файла\n");
            exit(1);
        }
        
        if(value != 0) {
            vector_pushback(spmatrix->row, indrow);
            vector_pushback(spmatrix->col, indcol);
            vector_pushback(spmatrix->value, value);
        }

        indcol++;
        if(indcol == n) {
            indrow++;
            indcol = 0;
        }
    }

    fclose(input);

    spmatrix_print(spmatrix);

    stdmatrix_print(spmatrix, m, n);

    matrix_free(spmatrix);

    return 0;
}