#include "matrix.h"

vector* vector_create (vector* vec) { 
	vec = (vector*)malloc(sizeof(vector));
    vec->size = 0;
    vec->elem = NULL;
    return vec;
}

matrix* matrix_create (matrix* mat) {
	mat = (matrix*)malloc(sizeof(matrix));
	mat->row = NULL;
	mat->row = vector_create(mat->row);
	mat->col = NULL;
	mat->col = vector_create(mat->col);
	mat->value = NULL;
	mat->value = vector_create(mat->value);
	return mat;
}

void vector_pushback (vector* vec, int value) {
	vec->size++;
	vec->elem = (int*)realloc(vec->elem, vec->size * sizeof(int));
	vec->elem[vec->size - 1] = value;
}

/*matrix* get_matrix (FILE* input, matrix* mat) {
	int value = 0, m = 0, n = 0, indrow = 0, indcol = 0;
	fscanf(input, "%d %d", &m, &n);

	while (!feof(input)) {
		fscanf(input, "%d", &value);
		if(value != 0) {
			vector_pushback(mat->row, indrow);
			vector_pushback(mat->col, indcol);
			vector_pushback(mat->value, value);
		}

		indcol++;
		if(indcol == n) {
			indrow++;
			indcol = 0;
		}

	}

	return mat;
}*/

void vector_print(vector* vec) {
	printf("(");
	for(int i = 0; i < vec->size; i++) {
		printf("%d ", vec->elem[i]);
	}
	printf(")\n");
}

void spmatrix_print (matrix* mat) {
	vector_print(mat->row);
	vector_print(mat->col);
	vector_print(mat->value);
	printf("\n");
} 

void stdmatrix_print (matrix* mat, int m, int n) {
	int ind = 0;
	for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {   
            if (i == mat->row->elem[ind] && j == mat->col->elem[ind]) {
                printf("%d ", mat->value->elem[ind]);
                ind++;
            } else {
                printf("0 ");
            }

            if (j == n - 1) {
                printf("\n");
            }
        }
    }

    printf("\n");
}

matrix* transpose (matrix* mat, int m, int n) {
	matrix* spmat = NULL;
	spmat = matrix_create(spmat);
	


	return spmat;
}


void vector_free (vector* vec) { 
	vec->size = 0;
    free(vec->elem);
}

void matrix_free (matrix* mat) {
	vector_free(mat->row);
	vector_free(mat->col);
	vector_free(mat->value);
	free(mat->row);
	free(mat->col);
	free(mat->value);
	free(mat);
}
