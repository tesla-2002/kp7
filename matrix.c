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
                if (ind != mat->value->size - 1) {
                	ind++;
                }

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
	int indrow = 0, indcol = 0, indvec = 0;

	if(m == n) {
		for (indcol = n - 1; indcol >= 0; indcol--) {
			for(indvec = mat->col->size - 1; indvec >= 0; indvec--) {
				if(mat->col->elem[indvec] == indcol) {
					vector_pushback(spmat->row, n - indcol - 1);
					vector_pushback(spmat->col, n - mat->row->elem[indvec] - 1);
					vector_pushback(spmat->value, mat->value->elem[indvec]);
				}
			}
		}
	}

	if(n > m) {
		for (indcol = m - 1; indcol >= 0; indcol--) {
			for(indvec = mat->col->size - 1; indvec >= 0; indvec--) {
				if(mat->col->elem[indvec] == indcol) {
					vector_pushback(spmat->row, m - indcol - 1);
					vector_pushback(spmat->col, m - mat->row->elem[indvec] - 1);
					vector_pushback(spmat->value, mat->value->elem[indvec]);
				}
			}
		}

		for (indcol = m; indcol < n; indcol++) {
			for(indvec = 0; indvec < mat->row->size; indvec++) {
				if(mat->col->elem[indvec] == indcol) {
					vector_pushback(spmat->row, indcol);
					vector_pushback(spmat->col, mat->row->elem[indvec]);
					vector_pushback(spmat->value, mat->value->elem[indvec]);
				}
			}
		}
	}

	if(m > n) {
		for (indcol = n - 1; indcol >= 0; indcol--) {
			for(indvec = mat->col->size - 1; indvec >= 0; indvec--) {
				if(mat->col->elem[indvec] == indcol) {
					vector_pushback(spmat->row, n - indcol - 1);
					vector_pushback(spmat->col, n - mat->row->elem[indvec] - 1);
					vector_pushback(spmat->value, mat->value->elem[indvec]);
				}
			}

			indrow = n;
				for(indvec = 0; indvec < mat->row->size; indvec++) {
					if(mat->col->elem[indvec] == n - 1 - indcol) {
						vector_pushback(spmat->row, n - 1 - indcol);
						vector_pushback(spmat->col, indrow);
						vector_pushback(spmat->value, mat->value->elem[indvec]);
						indrow ++;
					}
				}
			
		}
	}
	
	matrix_free(mat);
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
