#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int* elem;
	int size;
} vector;

typedef struct {
	vector* row;
	vector* col;
	vector* value;
} matrix;


vector* vector_create (vector* vec);
matrix* matrix_create (matrix* mat);
void vector_pushback (vector* vec, int value);
//matrix* get_matrix (FILE* input, matrix* mat);
void vector_print(vector* vec);
void spmatrix_print (matrix* mat);
void stdmatrix_print (matrix* mat, int m, int n);
void vector_free (vector* vec);
void matrix_free (matrix* mat);

//void transpose();
//bool is_symmetric();


#endif