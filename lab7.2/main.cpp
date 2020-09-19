//
// Created by andrew on 19.09.2020.
//
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<double>>;

void print(const Matrix &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix createSquareMatrix(size_t size) {
    Matrix matrix = {{}};
    matrix.resize(size);
    for (int i = 0; i < size; i++) {
        matrix[i].resize(size);
    }
    return matrix;
}

Matrix multiply(const Matrix &a, const Matrix &b) {
    int size = a.size();
    Matrix matrix = createSquareMatrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                matrix[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return matrix;
}

int main(int argc, char *argv[]) {
    Matrix a = {{0, 1, 2},
                {3, 4, 5},
                {6, 7, 8}};
    Matrix b = {{2, 4,  6},
                {8, 10, 2},
                {7, 5,  1}};

    Matrix result = multiply(a, b);
    print(result);
    return 0;
}



