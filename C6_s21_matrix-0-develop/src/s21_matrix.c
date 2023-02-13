#include "s21_matrix.h"

int OK(matrix_t *A) {
    int status = 0;
    if (A == NULL || A->rows <= 0 || A->columns <= 0 || A->matrix == NULL)
        status = 1;
    return status;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int status = 0;
    if (rows <= 0 || columns <= 0) {
        status = 1;
    } else {
        double **a = malloc(rows * sizeof(double*) + columns * rows * sizeof(double));
        double *pc = (double*)(a + rows);
        for (int i = 0; i < rows; i++)
            a[i] = pc + i * columns;
        result->rows = rows;
        result->columns = columns;
        result->matrix = a;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result->matrix[i][j] = 0.0;
            }
        }
        if (!result->matrix) {
            free(result->matrix);
            status = 1;
        }
    }
    return status;
}

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix != NULL) {
        free(A->matrix);
        A->rows = 0;
        A->columns = 0;
        A->matrix = NULL;
    }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int status = SUCCESS;
    if (A->rows == B->rows && A->columns == B->columns && !OK(A) && !OK(B)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
                    status = FAILURE;
                    break;
                }
            }
            if (!status)
                break;
        }
    } else {
        status = FAILURE;
    }
    return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = 0;
    if (OK(A) || OK(B)) {
        status = 1;
    } else {
        if (A->rows != B->rows || A->columns != B->columns) {
            status = 2;
        } else {
            if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
                    }
                }
            }
        }
    }
    return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = 0;
    if (OK(A) || OK(B)) {
        status = 1;
    } else {
        if (A->rows != B->rows || A->columns != B->columns) {
            status = 2;
        } else {
            if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < A->columns; j++) {
                        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
                    }
                }
            }
        }
    }
    return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int status = 0;
    if (OK(A)) {
        status = 1;
    } else {
        if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] * number;
                }
            }
        }
    }
    return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int status = 0;
    if (OK(A) || OK(B)) {
        status = 1;
    } else {
        if (A->columns != B->rows) {
            status = 2;
        } else {
            if ((status = s21_create_matrix(A->rows, B->columns, result)) == 0) {
                for (int i = 0; i < A->rows; i++) {
                    for (int j = 0; j < B->columns; j++) {
                        for (int k = 0; k < B->rows; k++) {
                            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                        }
                    }
                }
            }
        }
    }
    return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int status = 0;
    if (OK(A)) {
        status = 1;
    } else {
        if ((status = s21_create_matrix(A->columns, A->rows, result)) == 0) {
            for (int i = 0; i < A->rows; i++) {
                for (int j = 0; j < A->columns; j++) {
                    result->matrix[j][i] = A->matrix[i][j];
                }
            }
        }
    }
    return status;
}

void minor(int rows, int column, matrix_t *A, matrix_t *result) {
    s21_remove_matrix(result);
    if (A->rows > 1 && A->columns > 1) {
        s21_create_matrix(A->rows - 1, A->columns - 1, result);
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                int add_i = 0;
                int add_j = 0;
                if (i >= rows) add_i = 1;
                if (j >= column) add_j = 1;
                result->matrix[i][j] = A->matrix[i+add_i][j+add_j];
            }
        }
    }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int status = 0;
    if (OK(A)) {
        status = 1;
    } else {
        if (A->rows != A->columns) {
            status = 2;
        } else {
            if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
                matrix_t buf;
                s21_create_matrix(A->rows - 1, A->columns - 1, &buf);
                for (int i = 0; i < A->rows; i++)
                    for (int j = 0; j < A->columns; j++) {
                       minor(i, j, A, &buf);
                       double buf2 = 0.0;
                        s21_determinant(&buf, &buf2);
                        result->matrix[i][j] = pow(-1, i + j) * buf2;
                        s21_remove_matrix(&buf);
                    }
            }
        }
    }
    return status;
}

int s21_determinant(matrix_t *A, double *result) {
    int status = 0;
    *result = 0;
    if (OK(A)) {
        status = 1;
    } else {
        if (A->rows != A->columns) {
            status = 2;
        } else {
            if (A->columns == 1) {
                *result = A->matrix[0][0];
            } else if (A->columns == 2) {
                *result = A->matrix[0][0]*A->matrix[1][1] - A->matrix[0][1]*A->matrix[1][0];
                } else {
                    for (int j = 0; j < A->columns; j++) {
                        double tmp = 0;
                        matrix_t minor_matrix = {0};
                        minor(0, j, A, &minor_matrix);
                        s21_determinant(&minor_matrix, &tmp);
                        if (j%2) {
                            *result -= A->matrix[0][j] * tmp;
                        } else {
                            *result += A->matrix[0][j] * tmp;
                        }
                        s21_remove_matrix(&minor_matrix);
                        tmp = 0;
                    }
                }
        }
    }
    return status;
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int status = 0;
    if (OK(A)) {
        status = 1;
    } else {
        double buf;
        s21_determinant(A, &buf);
        if (A->rows != A->columns || fabs(buf) < 1e-7) {
            status = 2;
        } else {
            if ((status = s21_create_matrix(A->rows, A->columns, result)) == 0) {
                if (A->rows == 1) {
                   result->matrix[0][0] = 1.0 / A->matrix[0][0];
                } else {
                    matrix_t buf2, buf3;
                    s21_transpose(A, &buf2);
                    s21_calc_complements(&buf2, &buf3);
                    s21_mult_number(&buf3, 1.0 / buf, result);
                    s21_remove_matrix(&buf2);
                    s21_remove_matrix(&buf3);
                }
            }
        }
    }
    return status;
}
